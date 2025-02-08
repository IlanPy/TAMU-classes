#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

using namespace std;

int main(int argc, char *argv[]) {

    // Get flag from command line
    bool sort_ascending = false;
    int opt;
    while ((opt = getopt(argc, argv, "a")) != -1) {
        switch (opt) {
            case 'a':
                sort_ascending = true;
                break;
        }
    }
    
    int pipefd[2]; //Pipe File Descriptors
    char buf[100]; //Buffer used to read from pipe
    memset(buf, 0 , 100);
    
    /* TODO: CREATE PIPE */
    if(pipe(pipefd) == -1){
        perror("pipe");
        exit(EXIT_FAILURE);
    }


    
    /* TODO: FORK A NEW PROCESS */
    pid_t pid = fork();

    if (pid < 0) {
        cout << "Fork failed" << endl;
        return 1;
    } else if (pid == 0) { // Child Process
        char* const file = (char*)"./sort";
        string zero = to_string(pipefd[0]).c_str();
        string one = to_string(pipefd[1]).c_str();
        if(sort_ascending){
            /* TODO: EXECUTE THE COMMAND ./sort -r -w -a USING EXECVP*/
            char *const args[] = {(char*)"./sort", (char*)"-r", (char*)(to_string(pipefd[0]).c_str()), (char*)"-w", (char*)(to_string(pipefd[1]).c_str()), (char*)"-a", NULL};
            execvp(file, args);
        }
        else{
            /* TODO: EXECUTE THE COMMAND ./sort -r -w USING EXECVP*/
            char *const args[] = {(char*)"./sort", (char*)"-r", (char*)(to_string(pipefd[0]).c_str()), (char*)"-w", (char*)(to_string(pipefd[1]).c_str()), NULL};
            execvp(file, args);
        }
    } else if(pid > 0) { 
        

        /*TODO: CLOSE WRITE END FILE DESCRIPTOR*/
        close(pipefd[1]);
        
        printf("PARENT read from pipe:\n");
        while (true){
            int bytes_read;
            /*TODO: Read data from pipe into "buf" using "read()" function and number of bytes read into "bytes_read" */
            bytes_read = read(pipefd[0], buf, sizeof(buf));
            if (bytes_read == 0) {
                // No more data to read, break the loop
                break;
            }
            //write data to stdout
            write(STDOUT_FILENO, buf, bytes_read);
        }
              
        /*TODO: CLOSE READ END FILE DESCRIPTOR*/
        close(pipefd[0]);
    }

    return 0;
}
