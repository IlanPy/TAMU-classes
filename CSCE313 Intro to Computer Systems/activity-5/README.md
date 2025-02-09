[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/_QOEsp4s)
# Activity 5: Fork + Exec

Write a C++ program that performs the following operations.

## Instructions:
1. Create a child process using `fork()`.
1. The child process should execute the command: `ls -l`.
1. If the `option` number is even, the child executes `ls -l` otherwise, the child terminates.
1. The child process should print the parent process ID.
1. The parent process should print the child process ID.
1. The parent process should wait for the child process to finish.
1. The parent process should print the exit status of the child process: either `WIFEXITED` or `WIFSIGNALED`.

Hints:
1. You can use the man page for `waitpid` to understand the parameters.
2. The termination of a process may be due to a voluntary exit or due to the receipt of an unhandled signal whose default disposition is to terminate the process.
3. To distinguish between the two exit statuses:
   - `WIFEXITED` returns true if the process is terminated normally.
   - `WIFSIGNALED` returns true if the process is terminated due to the kill signal.

Usage:

`./main -n <option>`
