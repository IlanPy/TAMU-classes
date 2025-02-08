# include "TemperatureData.h"
using std::string;

TemperatureData::TemperatureData() /* TODO */:id(""), year(0), month(0), temperature(0) {
	// TODO: implement this function
}

TemperatureData::TemperatureData(string id, int year, int month, double temperature) /* TODO */
	: id(id), year(year), month(month), temperature(temperature) {
	// TODO: implement this function
}

TemperatureData::~TemperatureData() {}

bool TemperatureData::operator<(const TemperatureData& b) {
	// TODO: implement this function
	bool return_val = false;
	if(id < b.id){ return_val = true; }
	else if(id > b.id){ return_val = false; }
	else if(id == b.id){
		if(year < b.year){ return_val = true; }
		else if(year > b.year){ return_val = false; }
		else if(year == b.year){
			if(month < b.month){ return_val = true; }
			else{ return_val = false; }
		}
	}
	return return_val;
}

