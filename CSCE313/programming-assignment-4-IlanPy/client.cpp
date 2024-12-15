// your PA3 client code here
#include <fstream>
#include <iostream>
#include <thread>
#include <sys/time.h>
#include <sys/wait.h>

#include "BoundedBuffer.h"
#include "common.h"
#include "Histogram.h"
#include "HistogramCollection.h"
#include "TCPRequestChannel.h"

// ecgno to use for datamsgs
#define EGCNO 1

using namespace std;

class pairs {
public:
    int person;
    double time;
    double ecgData;

    pairs (double _ecgData, double _time, int _person) {
        person = _person;
        time = _time;
        ecgData = _ecgData;
    }
};

void patient_thread_function (BoundedBuffer* request_buffer, int person, int n /* add necessary arguments */) {
    // functionality of the patient threads
    double time = 0.0;
    for(int i = 0; i < n; i++){
        datamsg x(person, time, EGCNO);
        request_buffer->push((char*)&x, sizeof(datamsg));
        time += 0.004;
    }
}

void file_thread_function (BoundedBuffer* request_buffer, TCPRequestChannel* chan, int m, string f/* add necessary arguments */) {
    string file_path = "received/" + f;
    FILE* myfile = fopen(file_path.c_str(), "wb");
    //  q: seek to Clear contents
    fclose(myfile);

    // functionality of the file thread
    // sending a file msg to get length of file
    filemsg fm(0, 0); //check how big server is V
    int len = sizeof(filemsg) + (f.size() + 1);
    char* buf2 = new char[len];
    memcpy(buf2, &fm, sizeof(filemsg));
    strcpy(buf2 + sizeof(filemsg), f.c_str());
    chan->cwrite(buf2, len);
    delete[] buf2;

    // receiving response, i.e., the length of the file
    int64_t filesize = 0;
    chan->cread(&filesize, sizeof(int64_t));

    int i = 0;
    bool leftover = (filesize % m) != 0 ? true : false;
    for(i = 0; i < filesize / m; i++){
        filemsg x(i*m, m);
        request_buffer->push((char*)&x, sizeof(filemsg));
    }
    if(leftover){
        filemsg x(i*m, filesize % m);
        request_buffer->push((char*)&x, sizeof(filemsg));
    }
}

void worker_thread_function (BoundedBuffer* request_buffer, BoundedBuffer* response_buffer, 
        TCPRequestChannel* chan, int m, bool isFile, string f/* add necessary arguments */) {
    // functionality of the worker threads
    char* buf = new char[m + 1]; // m + 1
    if(isFile) {
        string file_path = "received/" + f;
        FILE* myfile = fopen(file_path.c_str(), "rb+"); // q: wb+
        /* redid from file thread to recreate buf2 */
        filemsg fm(0, 0);
        int len = sizeof(filemsg) + (f.size() + 1);
        char* buf2 = new char[len];
        memcpy(buf2, &fm, sizeof(filemsg));
        strcpy(buf2 + sizeof(filemsg), f.c_str());
        /* ********************************* */
        while(true){
            request_buffer->pop(buf2, sizeof(filemsg));
            if(*(MESSAGE_TYPE*)buf2 == QUIT_MSG){
                chan->cwrite((MESSAGE_TYPE*)buf2, sizeof(MESSAGE_TYPE));
                break;
            }
            filemsg x = *(filemsg*)buf2;
            cout << x.length << ", " << x.offset << ", " << x.mtype << endl;
            chan->cwrite(buf2, len); // Question
            chan->cread(buf, x.length); // Answer
            fseek(myfile, x.offset, SEEK_SET);
            fwrite(buf, sizeof(char), x.length, myfile);
        }
        fclose(myfile);
        delete[] buf2;
    } else {
        while(true){
            request_buffer->pop(buf, sizeof(datamsg));
            if(*(MESSAGE_TYPE*)buf == QUIT_MSG){
                chan->cwrite((MESSAGE_TYPE*)buf, sizeof(MESSAGE_TYPE));
                break;
            }
            datamsg x = *(datamsg*)buf;
            chan->cwrite(buf, sizeof(datamsg)); // Question
            chan->cread(buf, sizeof(double)); // Answer
            pairs data(*(double*)buf, x.seconds, x.person);
            response_buffer->push((char*)&data, sizeof(pairs));
        }
    }
    delete[] buf;
}

void histogram_thread_function (BoundedBuffer* response_buffer, HistogramCollection* hc/* add necessary arguments */) {
    // functionality of the histogram threads
    pairs data(0.0, 0.0, 0);
    while(true){
        response_buffer->pop((char*)&data, sizeof(pairs));
        if(data.person == -1){
            break;
        }
        hc->update(data.person, data.ecgData); //EDIT: deleted data.time
    }
}


int main (int argc, char* argv[]) {
    int n = 1000;	// default number of requests per "patient"
    int p = 10;		// number of patients [1,15]
    int w = 100;	// default number of worker threads
	int h = 20;		// default number of histogram threads
    int b = 20;		// default capacity of the request buffer (should be changed)
	int m = MAX_MESSAGE;	// default capacity of the message buffer
	string f = "";	// name of file to be transferred

    string host = "127.0.0.1";  // default ip address
    string port = "50000";      // default port no
    
    // read arguments
    int opt;
	while ((opt = getopt(argc, argv, "n:p:w:h:b:m:f:a:r:")) != -1) {
		switch (opt) {
			case 'n':
				n = atoi(optarg);
                break;
			case 'p':
				p = atoi(optarg);
                break;
			case 'w':
				w = atoi(optarg);
                break;
			case 'h':
				h = atoi(optarg);
				break;
			case 'b':
				b = atoi(optarg);
                break;
			case 'm':
				m = atoi(optarg);
                break;
			case 'f':
				f = optarg;
                break;
            case 'a':
                host = optarg;
                break;
            case 'r':
                port = optarg;
                break;
		}
	}
    
	// fork and exec the server
    // int pid = fork();
    // if (pid == 0) {
    //     execl("./server", "./server", "-m", (char*) to_string(m).c_str(), nullptr);
    // }
    
	// initialize overhead (including the control channel)
	TCPRequestChannel *chan = new TCPRequestChannel(host, port);
    BoundedBuffer request_buffer(b);
    BoundedBuffer response_buffer(b);
	HistogramCollection hc;

    // making histograms and adding to collection
    for (int i = 0; i < p; i++) {
        Histogram *h = new Histogram(10, -2.0, 2.0);
        hc.add(h);
    }
	
	// record start time
    struct timeval start, end;
    gettimeofday(&start, 0);

    /* create all threads here */
    bool isFile = (f != "") ? true : false;

    // making worker channels
    TCPRequestChannel **channels = new TCPRequestChannel*[w];
    for(int i = 0; i < w; i++){
        channels[i] = new TCPRequestChannel(host, port);
    }

    vector<thread> threads;
    if(isFile) {
        //threads
        threads.push_back(thread(file_thread_function, &request_buffer, chan, m, f));
        for(int i = 0; i < w; i++){
            threads.push_back(thread(worker_thread_function, &request_buffer, &response_buffer, 
                channels[i], m, isFile, f));
        }
    } else {
        for(int i = 0; i < p; i++){
            threads.push_back(thread(patient_thread_function, &request_buffer, i+1, n));
        }
        for(int i = 0; i < w; i++){
            threads.push_back(thread(worker_thread_function, &request_buffer, &response_buffer, 
                channels[i], m, isFile, f));
        }
        for(int i = 0; i < h; i++){
            threads.push_back(thread(histogram_thread_function, &response_buffer, &hc));
        }
    }

	/* join all threads here */
    if(isFile){
        threads.at(0).join();
        MESSAGE_TYPE msg = QUIT_MSG;
        for(int i = 0; i < w; i++){
            request_buffer.push((char*)&msg, sizeof(MESSAGE_TYPE));
        }
        for(int i = 1; i <= w; i++){
            threads.at(i).join();
        }
    } else {
        for(int i = 0; i < p; i++){
            threads.at(i).join();
        }
        MESSAGE_TYPE msg = QUIT_MSG;
        for(int i = 0; i < w; i++){
            request_buffer.push((char*)&msg, sizeof(MESSAGE_TYPE));
        }
        for(int i = 0; i < w; i++){
            threads.at(i+p).join();
        }
        pairs data(-1, -1, -1);
        for(int i = 0; i < h; i++){
            response_buffer.push((char*)&data, sizeof(pairs));
        }
        for(int i = 0; i < h; i++){
            threads.at(i+p+w).join();
        }
    }
    for(int i = 0; i < w; i++){ // DELETE
        delete channels[i];
    } delete[] channels;

	// record end time
    gettimeofday(&end, 0);

    // print the results
	if (f == "") {
		hc.print();
	}
    int secs = ((1e6*end.tv_sec - 1e6*start.tv_sec) + (end.tv_usec - start.tv_usec)) / ((int) 1e6);
    int usecs = (int) ((1e6*end.tv_sec - 1e6*start.tv_sec) + (end.tv_usec - start.tv_usec)) % ((int) 1e6);
    cout << "Took " << secs << " seconds and " << usecs << " micro seconds" << endl;

	// quit and close control channel
    MESSAGE_TYPE q = QUIT_MSG;
    chan->cwrite ((char *) &q, sizeof (MESSAGE_TYPE));
    cout << "All Done!" << endl;
    delete chan;

	// wait for server to exit
	// wait(nullptr);
}
