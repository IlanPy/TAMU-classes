/**
 *A C program to demonstrate working of fork(), process table entries, and zombies.
 **/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

// This function is a signal handler
void do_something(int signum)
{
    printf("Captured count 10");
}
 
int main()
{
    int i;
    int pid = fork();
    if (pid == 0)
    {
        for (i=0; i<20; i++){
            printf("I am Child\n");
        }
    return 0;
    }
    else
    {
        signal(SIGCHLD, SIG_IGN); // do_something is a signal handler
        //sigaction();
        printf("I am Parent\n");
        while(1);
    }
}