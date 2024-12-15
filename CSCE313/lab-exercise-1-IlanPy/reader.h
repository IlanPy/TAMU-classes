#include "state.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

//added using namespace std
using namespace std;

class Reader{
private:
    ifstream input_file;
public:
    Reader(const string& filename);
    ~Reader();

    //pass by reference
    void readData(vector<vector<string>>& csvRows);
};

Reader::Reader(const string& filename) {
    input_file.open(filename);

    if (!input_file.is_open()) {
        cerr << "Error opening the file." << endl;
        throw runtime_error("Error opening the file: " + filename);
    }
}

Reader::~Reader() {
    input_file.close();
}

void Reader::readData(vector<vector<string>>& csvRows) {
    string line;

    while (getline(input_file, line)) {
        istringstream iss(line);
        vector<string> row;
        string value;
        while ( getline(iss, value, ',')) {
            row.push_back(value);
        }
        csvRows.push_back(row);
    }
}