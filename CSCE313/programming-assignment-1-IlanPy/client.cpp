/*
	Original author of the starter code
	Tanzir Ahmed
	Department of Computer Science & Engineering
	Texas A&M University
	Date: 2/8/20

	Please include your Name, UIN, and the date below
	Name: Ilan Sela
	UIN: 232007587
	Date: 9/3/2024
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/wait.h>

#include <iostream>
#include <fstream>
#include <sstream>

#include "common.h"
#include "FIFORequestChannel.h"

using namespace std;

/* Verifies if the commandline argument passed to client.cpp "num_of_servers"
   is one of the following numbers (2,4,8,16). */
void verify_server_count(int num_of_servers)
{
	/*
		TODO: Allow only 2, 4, 8 or 16 servers
		If the number of servers is any other number
		Print "There can only be 2, 4, 8 or 16 servers\n"
		In the next line, print "Exiting Now!\n"
	*/
	if(num_of_servers != 2 && num_of_servers != 4
		&& num_of_servers != 8 && num_of_servers != 16){
			cout << "There can only be 2, 4, 8 or 16 servers\n";
			cout << "Exiting Now!\n";
			exit(-1); //exit with error
		}
}

/* Establishes a new channel with the server by sending appropriate NEWCHANNEL_MSG message.
   Sets this new channel as main channel (point chan to new channel) for communication with the server. */
void set_new_channel(FIFORequestChannel *chan, FIFORequestChannel **channels, int buffersize)
{
	channels[0] = nullptr;

	/*  TODO:
		1)request new channel
		  Hint: use cwrite and cread

		2)open channel on client side

		3)set the above channel as the main channel

		Remember to clean up any object you allocated memory to
	*/
	// 1)request new channel
	// send new channel request to server
	MESSAGE_TYPE nc = NEWCHANNEL_MSG;
	chan->cwrite(&nc, sizeof(MESSAGE_TYPE));

	// create variable to hold name of server
	char* name = new char[buffersize];
	chan->cread(name, buffersize);

	// 2)open channel on client side
	FIFORequestChannel* new_chan = new FIFORequestChannel(name, FIFORequestChannel::CLIENT_SIDE);

	// 3)set the above channel as the main channel
	chan = new_chan;
	channels[0] = new_chan;
	delete[] name;
}

/* Send datamsg request to server using "chan" FIFO Channel and
   cout the response with serverID */
void req_single_data_point(FIFORequestChannel *chan,
						   int person,
						   double time,
						   int ecg)
{
	/*
		TODO: Reading a single data point
		Hint: Go through datamsg and serverresponse classes
		1) sending a data msg
			Hint: use cwrite

		2) receiving response
			Hint: use cread
	*/

	// Don't Change the cout format present below
	//	cout << resp.ecgData <<" data on server:"<< resp.serverId << " on channel " << chan->name() << endl << endl;

	char buf[MAX_MESSAGE];
	datamsg x(person, time, ecg);

	// 1)sending a data msg
	// copy request to buf then write to server
	memcpy(buf, &x, sizeof(datamsg));
	chan->cwrite(buf, sizeof(datamsg)); // question
	// 2)receiving response
	serverresponse resp(-1, -1);
	chan->cread(&resp, sizeof(serverresponse)); // answer
	cout << resp.ecgData <<" data on server:"<< resp.serverId << " on channel " << chan->name() << endl << endl;
}

/* Sends 1000 datamsg requests to one server through FIFO Channel and
   dumps the data to x1.csv regardless of the patient ID */
void req_multiple_data_points(FIFORequestChannel *chan,
							  int person,
							  double time,
							  int ecg)
{
	// TODO: open file "x1.csv" in received directory using ofstream
	ofstream myfile;
	myfile.open("received/x1.csv");

	// set-up timing for collection
	timeval t;
	gettimeofday(&t, nullptr);
	double t1 = (1.0e6 * t.tv_sec) + t.tv_usec;

	// requesting data points
    // NOTE: Each data point is represented in `time (s), ecg1, ecg2`
    //       starting from t=0 (s), the time interval between data point is 4 ms
	// TODO: Receive 1000 data points, starting from t=4 (s).


    // E.g. myfile << time << "," << ecg1 << "," << ecg2 << flush;

	/* notes:
	Loop over 1st 1000 lines
	send request for ecg 1
	send request for ecg 2
	write line to received/x1.csv
	*/
	double time_ = 4;// start from t=4
	ecg = ecg; time = time; // don't need ecg, or time
	double ecg_v[] = {0, 0};
	char* buf = new char[MAX_MESSAGE]; //stack buf works as well!
	for(int i = 0; i < 1000; i++){
		for(int j = 1; j < 3; j++){
			datamsg x(person, time_, j);
			memcpy(buf, &x, sizeof(datamsg));
			chan->cwrite(buf, sizeof(datamsg)); // question
			serverresponse resp(-1, -1);
			chan->cread(&resp, sizeof(serverresponse)); // answer
			ecg_v[j-1] = resp.ecgData;
		}
		myfile << time_ << "," << ecg_v[0] << "," << ecg_v[1] << "\n" << flush;
		time_ += 0.004;
	}
	delete[] buf; //delete

	// compute time taken to collect
	gettimeofday(&t, nullptr);
	double t2 = (1.0e6 * t.tv_sec) + t.tv_usec;

	// display time taken to collect
	cout << "Time taken to collect 1000 datapoints :: " << ((t2 - t1) / 1.0e6) << " seconds on channel " << chan->name() << endl;

	// closing file
	myfile.close();
}

/* Request Server to send contents of file (could be .csv or any other format) over FIFOChannel and
   dump it to a file in recieved folder */
void transfer_file(FIFORequestChannel *chan,
				   string filename,
				   int buffersize)
{
	// sending a file msg to get length of file
	// create a filemsg, buf, and use cwrite to write the message
	filemsg fm(0, 0); //check how big server is V
	int len = sizeof(filemsg) + (filename.size() + 1);
	char* buf2 = new char[len];
	memcpy(buf2, &fm, sizeof(filemsg));
	strcpy(buf2 + sizeof(filemsg), filename.c_str());
	chan->cwrite(buf2, len);

	// receiving response, i.e., the length of the file
	// Hint: use cread
	int64_t filesize = 0;
	chan->cread(&filesize, sizeof(int64_t));

	// opening file to receive into
	string file_path = "received/" + filename;
	FILE* myfile = fopen(file_path.c_str(), "wb");

	// set-up timing for transfer
	timeval t;
	gettimeofday(&t, nullptr);
	double t1 = (1.0e6 * t.tv_sec) + t.tv_usec;

	// requesting file
	// TODO: Create a filemsg with the current offset you want
	// to read from. Receive data from the server.

	// create filemsg instance (reuse buf2)
	filemsg* file_req = (filemsg*)buf2;
	file_req->offset = 0; // set offset in the file
	file_req->length = 0; // set the length. Careful of last seg
	// send the request (buf2)
	// receive the response
	char* buf3 = new char[buffersize+1]; // create buffer of size buff capacity (m)
	// cread into buf3 length file_req->len
	// write buf3 into file: received filename
	
	int remaining = 0;
	while(file_req->offset < filesize){
		remaining = filesize - file_req->offset;
		file_req->length = (remaining < buffersize) ? remaining : buffersize;
		chan->cwrite(buf2, len); // send request
		chan->cread(buf3, file_req->length); //  cread into buf3 length file_req->len
		fwrite(buf3, sizeof(char), file_req->length, myfile); // write buf3 into file: received filename
		file_req->offset += file_req->length;
	}

	// compute time taken to transfer
	gettimeofday(&t, nullptr);
	double t2 = (1.0e6 * t.tv_sec) + t.tv_usec;

	// display time taken to transfer
	cout << "Time taken to transfer file :: " << ((t2 - t1) / 1.0e6) << " seconds" << endl
		 << endl;

	// closing file
	fclose(myfile);
	delete[] buf2;
	delete[] buf3;
}

int main(int argc, char *argv[])
{
	int person = 0;
	double time = 0.0;
	int ecg = 0;

	int buffersize = MAX_MESSAGE;

	string filename = "";

	bool new_chan = false;

	int num_of_servers = 2;

	int opt;
	while ((opt = getopt(argc, argv, "p:t:e:m:f:s:c")) != -1)
	{
		switch (opt)
		{
		case 'p':
			person = atoi(optarg);
			break;
		case 't':
			time = atof(optarg);
			break;
		case 'e':
			ecg = atoi(optarg);
			break;
		case 'm':
			buffersize = atoi(optarg);
			break;
		case 'f':
			filename = optarg;
			break;
		case 's':
			num_of_servers = atoi(optarg);
			break;
		case 'c':
			new_chan = true;
			break;
		}
	}

	/*
		Example Code Snippet for reference, you can delete after you understood the basic functionality.

		FIFORequestChannel chan("control", FIFORequestChannel::CLIENT_SIDE);

		// example data point request
		char buf[MAX_MESSAGE]; // 256
		datamsg x(1, 0.0, 1);

		memcpy(buf, &x, sizeof(datamsg));
		chan.cwrite(buf, sizeof(datamsg)); // question

		serverresponse resp(-1,-1);
		chan->cread(&resp, sizeof(serverresponse)); //answer

		cout << resp.ecgData <<" data on server:"<< resp.serverId << " on channel " << chan->name() << endl << endl;

		// sending a non-sense message, you need to change this
		filemsg fm(0, 0);
		string fname = "teslkansdlkjflasjdf.dat";

		int len = sizeof(filemsg) + (fname.size() + 1);
		char* buf2 = new char[len];
		memcpy(buf2, &fm, sizeof(filemsg));
		strcpy(buf2 + sizeof(filemsg), fname.c_str());
		chan.cwrite(buf2, len);  // I want the file length;

		delete[] buf2;

		// closing the channel
		MESSAGE_TYPE m = QUIT_MSG;
		chan.cwrite(&m, sizeof(MESSAGE_TYPE));

	*/

	verify_server_count(num_of_servers);

	bool data = ((person != 0) && (time != 0.0) && (ecg != 0));
	bool file = (filename != "");
	// Initialize FIFORequestChannel channels.
	// What should be the size of the object?
	// HINT: We need n channels(one for each of the servers) plus one more for new datachannel request.
	FIFORequestChannel **channels = new FIFORequestChannel*[num_of_servers + 1];
	
	// fork to create servers
	for(int i = 0; i < num_of_servers; i++){
		//enter child
		if(fork() == 0){
			string m_str = to_string(buffersize);
			string s_str = to_string(i+1);
			const char* server_argv[] = {"./server", "-m", m_str.c_str(), "-s", s_str.c_str(), NULL};
			execvp("./server", (char* const*)server_argv);	
			// exit(0);
		}
	}

	// open all requested channels
	for(int i = 1; i < num_of_servers+1; i++){
		channels[i] = new FIFORequestChannel("control_"+to_string(i)+"_", FIFORequestChannel::CLIENT_SIDE);
	}

	// Initialize step and serverId
	int step = 16 / num_of_servers;
	int serverId = 1; //q: changed from 0->1 and saved 0 for new_chan

	if (!filename.empty())
	{
		string patient = filename.substr(0, filename.find('.'));
		std::istringstream ss(patient);
		int patient_id;
		// If ss has a patient id, set serverId using ceil again
		// else, use the first server for file transfer
		if(ss >> patient_id){
			serverId = ceil(static_cast<double>(patient_id) / step);//q:???
		}
	}

	// By this line, you should have picked a server channel to which you can send requests to.

	// TODO: Create pointer for all channels

	if (new_chan)
	{
		// call set_new_channel
		set_new_channel(channels[serverId], channels, buffersize);
	}

	// request a single data point
	if (data)
	{
		// call req_single_data_point
		req_single_data_point(channels[serverId],
			person, time, ecg);
	}

	// request a 1000 data points for a person
	if (!data && person != 0)
	{
		// call req_multiple_data_points
		req_multiple_data_points(channels[serverId],
			person, time, ecg);
	}

	// transfer a file
	if (file)
	{
		// call transfer_file
		transfer_file(channels[serverId], filename, buffersize);
	}

	// close the data channel
	// if new_chan has any value, cwrite with channels[0]
	if(new_chan){
		MESSAGE_TYPE msgbuf = QUIT_MSG;
		channels[0]->cwrite(&msgbuf, sizeof(MESSAGE_TYPE));
		delete channels[0]; //added
	}

	// close and delete control channels for all servers
	for(int i = 1; i < num_of_servers+1; i++){
		MESSAGE_TYPE msgbuf = QUIT_MSG;
		channels[i]->cwrite(&msgbuf, sizeof(MESSAGE_TYPE));
		delete channels[i];
	}
	delete[] channels;

	// wait for child to close
	for(int i = 0; i < num_of_servers; i++){
		wait(NULL);
	}
}
