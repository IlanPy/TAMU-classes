# include "TemperatureDatabase.h"
# include <fstream>
# include <sstream>
# include <cstdlib>

using std::cout, std::endl, std::string, std::ofstream;

TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	// TODO: implement this function
	std::ifstream inFS;
	std::istringstream inSS;
	string line;
	string id; int year, month; double temperature;
	//open
	inFS.open(filename);
	//verify
	if(!inFS.is_open()){
		cout << "Error: Unable to open " << filename << endl;
	}
	while(!inFS.eof()){
		getline(inFS, line);
		inSS.clear();
		inSS.str(line);
		if(line == ""){ continue; }
		inSS >> id >> year >> month >> temperature;
		if(inSS.fail()){
			cout << "Error: Other Invalid Input" << endl;
			continue;
		} else if(temperature == -99.99){
			continue;
		} else if(year < 1800 || year > 2023){
			cout << "Error: Invalid year " << year << endl;
			continue;
		} else if(month < 1 || month > 12){
			cout << "Error: Invalid month " << month << endl;
			continue;
		} else if(temperature < -50.0 || temperature > 50.0){
			cout << "Error: Invalid temperature " << temperature << endl;
			continue;
		}
		records.insert(id, year, month, temperature);
	}
	inFS.close();
}

void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}

	dataout << records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {
	// TODO: implement this function
	std::ifstream inFS;
	std::stringstream inSS;
	string line;
	string outputString;
	std::ostringstream OSS;
	int range0, range1; string query, id;
	int count = 0;
	int current_temperature;
	string average_str = "";
	double average;
	int mode[101];
	inFS.open(filename);
	if(!inFS.is_open()){
		exit(1);
	}
	while(!inFS.eof()){
		getline(inFS, line);
		inSS.clear();
		inSS.str(line);
		if(line == ""){ continue; }
		inSS >> id >> query >> range0 >> range1;
		if(inSS.fail()){
			cout << "Error: Other invalid query" << endl;
			continue;
		} else if(range0 > range1 || range0 < 1800 || range1 > 2023){
			cout << "Error: Invalid range " << range0 << "-"
				<< range1 << endl;
			continue;
		} else if(query != "AVG" && query != "MODE"){
			cout << "Error: Unsupported query " << query << endl;
			continue;
		}
		Node* current = records.getHead();
		if(query == "AVG"){
			average = 0;
			count = 0;
			average_str = "";
			std::stringstream averageSS;
			while(current != nullptr){
				if(current->data.id == id && current->data.year >= range0 &&
					current->data.year <= range1){
					average += current->data.temperature;
					count++;
				}
				current = current->next;
			}
			if(count == 0){
				average_str = "unknown";
			} else{
				average = average/count;
				averageSS << average;
				average_str = averageSS.str();
			}
			OSS << id << " " << range0 << " " << range1 << " "
				<< query << " " << average_str << "\n";
		} else{
			count = 0;
			for(int i = 0; i < 101; i++){
				mode[i] = 0;
			}
			while(current != nullptr){
				if(current->data.id == id && current->data.year >= range0 &&
					current->data.year <= range1){
					//round
					if(current->data.temperature - int(current->data.temperature)
						<= 0.5){ current_temperature = current->data.temperature; }
					else{
						current_temperature = current->data.temperature + 1;
					}
					mode[current_temperature+50] += 1;
					count++;
				}
				current = current->next;
			}
			int max_value = 0;
			int max_temperature = 0;
			for(int i = 0; i < 101; i++){
				if(max_value <= mode[i]){
					max_value = mode[i];
					max_temperature = i;
				}
			}
			if(count == 0){
				OSS << id << " " << range0 << " " << range1 << " "
				<< query << " " << "unknown" << "\n"; 
			} else{
				OSS << id << " " << range0 << " " << range1 << " "
				<< query << " " << max_temperature-50 << "\n";
			}
		}
	}
	inFS.close();
	ofstream outFS;
	outFS.open("result.dat");
	if(!outFS.is_open()){
		exit(1);
	}
	outFS << OSS.str();
	outFS.close();
}
