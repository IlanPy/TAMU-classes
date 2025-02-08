// C program to illustrate
// read system Call
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	char c;
	int fd1 = open("sample.txt", O_RDONLY, 0);
	int fd2 = open("sample.txt", O_RDONLY, 0);
	read(fd1, &c, 1); // every time reads, move cursor one position forward
	read(fd1, &c, 1); // result is c!
	read(fd1, &c, 1); // if fd2, result will be a because we haven't moved fd2 yet!
	printf("c = %c\n", c);
	exit(0);
}
