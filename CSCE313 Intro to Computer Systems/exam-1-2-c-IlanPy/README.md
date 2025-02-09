[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/EpJJ6o7U)
# Exam 1.2.c
Implement a simple `diff` utility program that performs a line-by-line comparison of the output of two commands.
Most of the functionality is already implemented for you. You only need to complete the missing parts in the code.

# Instructions
1. The main process executes the two commands in two separate child processes using `fork()` and `execvp()` syscalls.
1. The output of each of the child processes is written to a separate pipe.
1. The main process reads the outputs of the child processes using the read ends of the two pipes, and prints the line-by-line difference.

# Usage
1. Compilation: `g++ mydiff.cpp -o mydiff`
1. Running: `./mydiff "<command 1>" "<command 2>"`
1. Example: `./mydiff "ls -1 .." "ls -1"`
1. Test with different commands to make sure your code is working as expected.

# Getting Started
- The sections of code in `mydiff.cpp` which are labeled with **`/* TODO: */`** are incomplete and need to be addressed.
- The rest of the code need not be changed
