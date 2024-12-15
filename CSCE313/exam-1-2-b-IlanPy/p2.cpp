#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#define MAX_MESSAGE 256

long long unsigned int hash(int seed, char* buf, int nbytes) {
    long long unsigned int H = seed; 
    for (int i = 0; i < nbytes; ++i) 
        H = H * 2 * buf[i] + 1;
    return H;
}

int main(int argc, char** argv) {

	// TODO: create pipe 
    if(argc != 2 || strlen(argv[1]) > MAX_MESSAGE){ /* ensure sizes and arguements and pipe */
        exit(1);
    }

    int pipefd1[2]; // Parent to child File Descriptors
    int pipefd2[2]; // Child to parent File Descriptors
    char buf[MAX_MESSAGE]; // Buffer up to 256 bytes
    char* msg = argv[1]; // Message from arg
    int bytes = MAX_MESSAGE; // Byte = sizeof(buf)

    if(pipe(pipefd1) == -1 || pipe(pipefd2) == -1){ /* create pipes */
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    int pid = fork(); /* fork */
    if (pid == 0) { /* child process */
        // TODO: read from parent
        close(pipefd1[1]); /*close unused pipe ends*/
        close(pipefd2[0]);

        read(pipefd1[0], buf, bytes); /* read message from p2c */
        close(pipefd1[0]); /*close after finishing*/

        // TODO: compute hash 
        long long unsigned int h = hash(getpid()/*provide pid here*/, buf, strlen(msg));

        // TODO: send hash to parent 
        write(pipefd2[1], &h, sizeof(h)); /* write hash function to c2p */
        close(pipefd2[1]); /*close after finishing*/
    }
    else {
        // TODO: write to child 
        close(pipefd1[0]); /*close unused pipe ends*/
        close(pipefd2[1]);

        write(pipefd1[1], msg, strlen(msg)); /* write message to p2c */
        close(pipefd1[1]); /*close after finishing*/
        
        // TODO: get hash from child 
        long long unsigned int hrecv;
        read(pipefd2[0], &hrecv, sizeof(hrecv)); /* read hash from c2p */
        close(pipefd2[0]); /*close after finishing*/

        wait(NULL); /* prevent zombie */
        
        // TODO: calculate hash on parent side
        long long unsigned int h = hash(pid, msg, strlen(msg));
		
		// print hashes; DO NOT change
        printf("%llX\n", h);
        printf("%llX\n", hrecv);
    }

    return 0;
}