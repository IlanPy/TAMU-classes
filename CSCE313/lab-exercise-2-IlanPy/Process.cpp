#include "Process.h"

/**
 * @brief Process class default constructor
 *
 */
Process::Process() :pid(0), arrival_time(0), cpu_burst_time(0), io_burst_time(0), cpu_remaining_time(0), io_remaining_time(0), total_remaining_time(0), isCompleted(false), isIOBound(false), isCritical(false) {
}

/**
 * @brief Process class parameterized constructor
 *
 */
Process::Process(int pid, int arrival_time, int cpu_burst_time, int io_burst_time, bool isIOBound, bool isCritical) {
    this->pid = pid;
    this->arrival_time = arrival_time;
    this->cpu_burst_time = cpu_burst_time;
    this->cpu_remaining_time = cpu_burst_time;
    this->io_remaining_time = io_burst_time;
    this->total_remaining_time = cpu_burst_time + io_burst_time; // timer hasn't started yet, so it's full time
    this->isCompleted = false;
    this->isIOBound = isIOBound;
    this->isCritical = isCritical;
}

/**
 * @brief Process class copy construcor
 *
 */
Process::Process(const Process &p){
    this->pid = p.pid;
    this->arrival_time = p.arrival_time;
    this->cpu_burst_time = p.cpu_burst_time;
    this->io_burst_time = p.io_burst_time;
    this->cpu_remaining_time = p.cpu_remaining_time;
    this->io_remaining_time = p.io_remaining_time;
    this->total_remaining_time = p.total_remaining_time;
    this->isCompleted = p.isCompleted;
    this->isIOBound = p.isIOBound;
    this->isCritical = p.isCritical;
}

/**
 * @brief Every time, When your process is running on cpu, use this function to update
 *  the remaining time and monitor if the process is done or not
 */
void Process::Run(int run_time) {
    // update cpu_remaining_time
    this->cpu_remaining_time -= run_time;
    this->total_remaining_time = this->cpu_remaining_time+ this->io_remaining_time;
    // isCompleted updated based on remaining time or not
    isCompleted = (this->total_remaining_time == 0);
}

/**
 * @brief Every time, When your process is processing I/O operations, use this function to update
 *  the remaining time and monitor if the process is done or not
 */
void Process::IOrun(int io_run_time) {
    // update cpu_remaining_time
    this->io_remaining_time -= io_run_time;
    this->total_remaining_time = this->cpu_remaining_time + this->io_remaining_time;
    // isCompleted updated based on remaining time or not
    isCompleted = (this->total_remaining_time == -1);
}

/**
 * @brief getter functions
 * 
 */
int Process::getPid() const {
    return this->pid;
}
int Process::get_arrival_time() const {
	return this->arrival_time;
}
int Process::get_cpu_burst_time() const {
    return this->cpu_burst_time;
}
int Process::get_io_burst_time() const {
    return this->io_burst_time;
}
int Process::get_cpu_remaining_time() const {
	return this->cpu_remaining_time;
}
int Process::get_io_remaining_time() const {
    return this->io_remaining_time;
}
int Process::get_total_remaining_time() const {
    return this->total_remaining_time;
}
bool Process::is_Completed() const {
    return this->isCompleted;
}
bool Process::is_Proc_IOBound() const {
    return this->isIOBound;
}
bool Process::is_Proc_Critical() const {
    return this->isCritical;
}

/**
 * @brief Assignment Operator Overloading
 *
 */
Process & Process::operator=(const Process & p)
{
    this->pid = p.pid;
    this->arrival_time = p.arrival_time;
    this->cpu_burst_time = p.cpu_burst_time;
    this->io_burst_time = p.io_burst_time;
    this->cpu_remaining_time = p.cpu_remaining_time;
    this->io_remaining_time = p.io_remaining_time;
    this->total_remaining_time = p.total_remaining_time;
    this->isCompleted = p.isCompleted;
    this->isIOBound = p.isIOBound;
    this->isCritical = p.isCritical;
    return *this;
}
