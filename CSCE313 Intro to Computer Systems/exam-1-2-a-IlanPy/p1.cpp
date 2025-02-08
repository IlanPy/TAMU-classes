#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>

#include <algorithm>
#include <vector>

int main(int argc, char** argv) {
    int n = 1, opt;
    while ((opt = getopt(argc, argv, "n:")) != -1) {
        switch (opt) {
        case 'n':
            n = atoi(optarg);
            break;
        }
    }

    /*
    1. TODO: fork n child processes and run p1-helper on each using execvp
        > note: we need to synchronize the child processes to print in the desired order
        > note: sleep(..) does not guarantee desired synchronization
        > note: check "raise" system call
        > note: check "WUNTRACED" flag for "waitpid"
    */
    std::vector<pid_t> pids; /* vector to store pid of children */
    int status = 0;
    for(int i = 0; i < n; i++){
        pid_t pid = fork(); /* fork to create parent and child */
        if (pid < 0) { /* error check */
            std::cout << "Fork failed" << std::endl;
            return 1;
        } 
        else if(pid == 0){ /* child process */
            char *const args[] = {(char*)"./p1-helper", NULL};
            raise(SIGSTOP); /* signal to stop process */
            execvp(args[0], args); /* execute p1-helper after continued */
        } else{ /* parent process */
            waitpid(pid, &status, WUNTRACED); /* wait until stopped */
            pids.push_back(pid); /* store pid in vector pids */
        }
    }

    /* 
    2. TODO: print children pids 
    */
    std::sort(pids.begin(), pids.end()); /* sort pids */


    fflush(stdout);             // DO NOT REMOVE: ensures the first line prints all pids

    if(n != 0){ /* make sure child requested */
        std::cout << pids.at(0); /* print pids in sorted order */
        for(int i = 1; (long unsigned int)i < pids.size(); i++){
            std::cout << " " << pids.at(i);
        } std::cout << std::endl;
    }

    /* 
    3. TODO: signal children with the reverse order of pids 
        > note: take a look at "kill" system call 
    */
    for(int i = pids.size()-1; i >= 0; i--){ /* loop opposite order */
        if (kill(pids.at(i), SIGCONT) == -1){ /* send SIGCONT to child */
            perror("Failed to send SIGCONT signal");
        }
        waitpid(pids.at(i), &status, 0); /* make sure child printed before moving on */
        if (status > 1) {  // exit if child didn't exec properly
            exit(status);
        }
    }
    
    printf("Parent: exiting\n");

    return 0;
}