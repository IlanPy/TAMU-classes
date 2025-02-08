#include "STCF.h"

/**
 * @brief This is a constructor for STCF Scheduler, you should use the extractProcessInfo function first
 *  to load the process information to process vector and then sort process by arrival time
 * 
 * @param file name
 */
STCF::STCF(string file) {
	extractProcessInfo(file);
	sort(processVec.begin(), processVec.end(), [](Process& a, Process& b){
		return a.get_arrival_time() < b.get_arrival_time();
	});
}

/**
 * @brief Schedule tasks based on STCF Rule
 * the jobs are put in the order of shortest remaining time left
 * Make sure you use methods [ printCPU/ printIO ] to print out the information like we put in the document
 * Priority order (high to low from top to bottom)
 * 1. Critical I/O bound task
 * 2. Critical CPU bound task
 * 3. Non Critical I/O bound task
 * 4. Non Critical CPU bound task
 */
void STCF::schedule_tasks() {
    int timestep = 0;
    /*if required you can make use of this flag*/
    bool onlyIOtask = true;

    while (!processVec.empty() || !processQ.empty() || !IOQ.empty()) {
        /* Task 1 */
		/// get new tasks
        /// Go through the processVec
        /// if the arrival time is less than the timestep
        ///   check if the total remaining time and cpu remaining time not equal to zero
        ///   push the process into the processQ queue
        ///   check if only IO processes are present then push into the IOQ queue
        /// else go to the next process
        /// Get new tasks
        for(int i = 0; (long unsigned int)i < processVec.size(); i++){
            if(processVec[i].get_arrival_time() <= timestep){
                if(processVec[i].get_total_remaining_time() != 0 
                    && processVec[i].get_cpu_remaining_time() != 0){
                        processQ.push(processVec[i]);
                        onlyIOtask = false;
                }
                if(processVec[i].get_io_remaining_time() != 0 && processVec[i].get_cpu_remaining_time() == 0){
                    IOQ.push(processVec[i]);
                }
                processVec.erase(processVec.begin() + i); i--;
            }
        }

        /* Task 2 */
        /// is there a task to do?
        /// print timestep, set appropriate process and not completed flag
        /// increase timestep
        if (processQ.empty() && IOQ.empty()) {
            printCPU(timestep, -1, false);
            timestep++;
            continue;
        }

        /* Task 3 */
        /// is there a task to do which is in the IOQ but processQ is empty?
        /// call ioProcessing method with appropriate timestep
        /// increase timestep in correct order to handle other cases too with onlyIOtask flag
        if (!IOQ.empty() && processQ.empty()) {
            if(!onlyIOtask){
                timestep++;
            }
            ioProcessing(timestep);
            if(onlyIOtask){
                timestep++;
            }
            continue;
        }

        /* Task 4 */
        /// Create a comparator using a lambda function to use with the priority queue.
        /// This lambda function returns a boolean value based on which process has higher priority.
        /// Given the declaration, you should complete the conditions inside the lambda function.
        /// make use of the methods given in the process.h to get
        /// is_Proc_Critical/ is_Proc_IOBound/  get_total_remaining_time/ get_cpu_remaining_time
        auto compare = [](const Process& a, const Process& b) {
            // 1) Critical
            if(a.is_Proc_Critical() && !b.is_Proc_Critical()){ return false; }
            if(!a.is_Proc_Critical() && b.is_Proc_Critical()){ return true; }
            // 2) I/O Bound
            if(a.is_Proc_IOBound() && !b.is_Proc_IOBound()){ return false; }
            if(!a.is_Proc_IOBound() && b.is_Proc_IOBound()){ return true; }
            // 3) Shortest total time
            if(b.is_Proc_IOBound()){
                if(a.get_total_remaining_time() < b.get_total_remaining_time()){ return false; }
                if(a.get_total_remaining_time() > b.get_total_remaining_time()){ return true; }
            }
            // 4) Shortest remaining time
            if(a.get_cpu_remaining_time() < b.get_cpu_remaining_time()){ return false; }
            if(a.get_cpu_remaining_time() > b.get_cpu_remaining_time()){ return true; }
            // 5) Exact same -> A has higher priority
            return false;
        };
      
        ///priority_queue to push the processQ processes based on the priority as mentioned above into it
        ///it is initialized to custom comparator as you define above
        /// pq is the priority queue below with comparator compare
        std::priority_queue<Process, std::vector<Process>, decltype(compare)> pq(compare);

        /* Task 5 */
        /// push the processes in the processQ into the priority queue until you empty it
        /// 
        while(!processQ.empty()){
            pq.push(processQ.front());
            processQ.pop();
        }

        /* Task 6 */
        /// Get the current task which follows the above policy(STCF: Shortest Remaining Time First)
        /// and remove from the pq
        /// Print a new process running on CPU
        /// use printCPU method already given by passing required arguments
        /// Execute the process with the help of the given method "Run" on the CPU
        /// increment the timestep
        Process A = pq.top();
        pq.pop();
        printCPU(timestep, A.getPid(), A.is_Completed());
        A.Run(1);
        timestep++;

        /* Task 7 */
        /// Check if the process cpu burst time is done
        ///  if it is done, check for total remaining time
        ///     and push it into the IOQ if IO processing not done
        ///  if total remaining time is done
        ///     print using printCPU method by passing required arguments
        /// if the process cpu burst time is not done
        /// then push into the processQ
        if(A.get_cpu_remaining_time() == 0){
            if(A.get_total_remaining_time() > 0){
                if(A.get_io_remaining_time() > 0 ){
                    IOQ.push(A);
                }
            } else{
                printCPU(timestep, A.getPid(), A.is_Completed());
            }
        } else{
            processQ.push(A);
        }

        /* Task 8 */
        /// process IO operations simultaneously
        /// handle the onlyIOtask flag if required
        /// 
        if(!IOQ.empty()){
            ioProcessing(timestep);
        }

        /* Task 9 */
        /// Reinsert remaining processes in the priority queue back into the processQ
        /// 
        while(!pq.empty()){
            processQ.push(pq.top());
            pq.pop();
        }
    }
}


/*************************** 
ALL FUNCTIONS UNDER THIS LINE ARE COMPLETED FOR YOU
You can modify them if you'd like, though :)
***************************/

/**
 * @brief ioProcessing method to process I/O operations
 * IOQ, a queue for IO operations which are handled in this ioProcessing method
 * @param timestep
 * @return void
 */
void STCF::ioProcessing(int timestep) {

    if (!IOQ.empty()) {
        Process& io_p = IOQ.front();
        io_p.IOrun(1);

        if (io_p.get_total_remaining_time() == -1) {
            IOQ.pop();
            printIO(timestep, io_p.getPid(), io_p.is_Completed());
            if (!IOQ.empty()) {
                io_p = IOQ.front();
                IOQ.front().IOrun(1);
            }
        }
        if (!IOQ.empty()) {
            printIO(timestep, io_p.getPid(), io_p.is_Completed());
        }
    }
}

/**
 * @brief printCPU method for outputting system time as part of the schedule tasks function in case of CPU
 *
 * @param system_time, pid, isComplete
 * @return void
 */
void STCF::printCPU(int system_time, int pid, bool isComplete){
	string s_pid = pid == -1 ? "NOP" : to_string(pid);
	cout << "System Time [" << system_time << "].........Process[PID=" << s_pid << "] ";
	if (isComplete)
		cout << "finished its job!" << endl;
	else
        if(pid != -1)
		    cout << "is running on CPU" << endl;
        else
            cout << "No Operation" << endl;
}

/**
 * @brief printIO method for outputting system time as part of the schedule tasks function in case of I/O
 *
 * @param system_time, pid, isComplete
 * @return void
 */
void STCF::printIO(int system_time, int pid, bool isComplete) {
    string s_pid = pid == -1 ? "NOP" : to_string(pid);
    cout << "System Time [" << system_time << "].........Process[PID=" << s_pid << "] ";
    if (isComplete)
        cout << "finished its job!" << endl;
    else
        cout << "is performing I/O" << endl;
}

/**
 * @brief string2bool function is used to convert string to boolean
 * isCritical and isIOBound values are converted to boolean using this function
 *
 * @param isCritical/ isIOBound of type string reference
 * @return bool
 */

bool
string2bool (const std::string &v)
{
    return !v.empty () &&
        (strcasecmp (v.c_str (), "true") == 0 ||
         atoi (v.c_str ()) != 0);
}

/**
 * @brief All process information goes in to processVec vector as a Process objects
 * Read a process file to extract process information using input file streams
 *
 * @param file name
 * @return void
 */
void STCF::extractProcessInfo(string file){
	/// open file
	ifstream processFile (file);
	if (!processFile.is_open()) {
		perror("could not open file");
		exit(1);
	}

	/// read contents and populate process_info vector
	string curr_line, temp_num;
	int curr_pid, curr_arrival_time, curr_cpu_burst_time, curr_io_burst_time;
    bool isIOBound, isCritical;
	while (getline(processFile, curr_line)) {
		/// use string stream to seperate by comma
		stringstream ss(curr_line);
		getline(ss, temp_num, ',');
		curr_pid = stoi(temp_num);
		getline(ss, temp_num, ',');
		curr_arrival_time = stoi(temp_num);
		getline(ss, temp_num, ',');
		curr_cpu_burst_time = stoi(temp_num);
		getline(ss, temp_num, ',');
		curr_io_burst_time = stoi(temp_num);
		getline(ss, temp_num, ',');
		isIOBound = string2bool(temp_num);
		getline(ss, temp_num, ',');
        isCritical = string2bool(temp_num);
		Process p(curr_pid, curr_arrival_time, curr_cpu_burst_time, curr_io_burst_time, isIOBound, isCritical);

		processVec.push_back(p);
	}

	/// close file
	processFile.close();
}
