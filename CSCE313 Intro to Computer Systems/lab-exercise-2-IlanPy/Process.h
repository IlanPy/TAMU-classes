#ifndef PROCESS_HEADER
#define PROCESS_HEADER
#include <string>

using namespace std;

/**
 * @brief Process class has data members and methods related to a process
 *
 */
class Process{
private:
	int pid;
	int arrival_time;
	int cpu_burst_time;
	int io_burst_time;
	int cpu_remaining_time;
	int io_remaining_time;
	int total_remaining_time;
	bool isCompleted;
	bool isIOBound;
    bool isCritical;
public:
	Process();
	Process(int pid, int arrival_time, int cpu_burst_time, int io_burst_time, bool isIOBound, bool isCritical);
	Process(const Process &p);
	void Run(int run_time);
	void IOrun(int run_time);
	int getPid() const;
	bool is_Completed() const;
    bool is_Proc_Critical() const;
	bool is_Proc_IOBound() const;
	int get_cpu_remaining_time() const;
	int get_io_remaining_time() const;
	int get_total_remaining_time() const;
	int get_cpu_burst_time() const;
	int get_io_burst_time() const;
	int get_arrival_time() const;
	Process& operator=(const Process &p);
	
};

#endif
