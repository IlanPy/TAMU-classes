#include <iostream>
#include <unistd.h>
#include <algorithm>
#include <cstring>
#include "reader.h"
using namespace std;

bool sort_comparator(const std::vector<std::string> &row1, const std::vector<std::string> &row2) {
    if (row1[1] != row2[1]) {
        return stoi(row1[1]) < stoi(row2[1]);
    }
    return false; 
}

int main (int argc, char *argv[]) {
	int pipefd[2] = {0, 1}; // PIPE FILE DESCRIPTORS
    int opt;
    bool sort_ascending = false;
	while ((opt = getopt(argc, argv, "r:w:a")) != -1) {
		switch (opt) {
			case 'r':
                //Capturing read fd of pipe sent by parent process
				pipefd[0] = atoi(optarg);
				break;
			case 'w':
                //Capturing write fd of pipe sent by parent process
				pipefd[1] = atoi(optarg);
				break;
            case 'a':
                sort_ascending = true;
                break;
		}
	}
    /*TODO: CLOSE READ END FILE DESCRIPTOR*/
    close(pipefd[0]);

    //Read rows from CSV
    std::vector<std::vector<std::string>> csvRows;
    Reader stockReader("./stock_portfolio.csv");
    stockReader.readData(csvRows);

    if(sort_ascending){
        sort(csvRows.begin(), csvRows.end(), sort_comparator);
    }
    else{
        /*TODO: SORT CSVROWS IN DESCENDING ORDER*/
        /*Hint: you could use reverse iterator*/
        sort(csvRows.rbegin(), csvRows.rend(), sort_comparator);
    }

    for(int i = 0 ;i<4; i++){
        string message = csvRows[i][0] + "\n";
        //csvRows[i] will give you (i)th row, which is vector of two strings (stockname, stockvalue)
        
        /*TODO: WRITE message.c_str() which is the stockname to the pipe*/
        write(pipefd[1], message.c_str(), sizeof(message.c_str()));
    }
    /*TODO: CLOSE WRITE END FILE DESCRIPTOR*/
    close(pipefd[1]);
}
