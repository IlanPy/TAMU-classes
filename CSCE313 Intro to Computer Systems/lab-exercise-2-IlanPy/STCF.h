#ifndef STCF_HEADER
#define STCF_HEADER
#include <strings.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <tuple>
#include <algorithm>
#include <memory>
#include <queue>
#include <vector>
#include <cassert>
#include "Process.h"
/**
 * @brief STCF Scheduler
 *
 */
class STCF {
private:
	/**
	* @brief used shared pointer from c++11 features
	*
	*/
	vector<Process> processVec;
	queue<Process> processQ;
	queue<Process> IOQ;
public:
	STCF();
	STCF(string file);
	void extractProcessInfo(string file);
	void schedule_tasks();
	void ioProcessing(int timestep);
	void printCPU(int system_time, int pid, bool isComplete);
	void printIO(int system_time, int pid, bool isComplete);
};



#endif
