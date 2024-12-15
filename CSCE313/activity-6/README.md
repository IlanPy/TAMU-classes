[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/9EfA6V_W)
# quiz 1.2.b: Pipe

1. Complete the implementation of main.cpp and sort.cpp. 
2. C++ program main.cpp needs to call "sort" program using fork and execvp.
3. The "main" process and "sort" process communicate using a pipe (unidirectional "sort" sends a message to "main").
4. Sort.cpp reads stock names and their values from a CSV, sorts them based on value, and sends the first four stock names from the list via pipe to "main".
5. The Makefile will produce the sort executable. sort.cpp takes in three command line arguments (-r <Read File Descriptor> -w <Write File Descriptor> -a {ascending(optional flag)}) where -a, which tells sort.cpp to sort the stocks in ascending order, is optional. 

## Instructions:
1. Create a pipe.
1. Create a child process using `fork()`.
1. The child process should execute the command: `./sort -r <pipefd[0]> -w <pipefd[1]> -a` if the ascending option is selected. Otherwise execute `./sort -r <pipefd[0]> -w <pipefd[1]>`
1. The child will send the parent the first four stock names of its list after sorting(In ascending order if -a flag is specified; in descending order if -a is missing) via the pipe.
1. The parent will read the stock names from the pipe and then display them on STDOUT.


Usage:

`./main -a{-a is optional flag}`
