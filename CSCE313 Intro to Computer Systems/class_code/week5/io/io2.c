/**
 * C program to illustrate write system Call
 **/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int sz;

    int fd = open("foo.txt", O_WRONLY | O_CREAT | O_APPEND, 00644); // The mode is the definition of actions U G O
    
    /*
    U : User ->>   6: 110 ->> RW (Read, Write, No Execute)
    G : Group ->>  4: 100 ->> R
    O : public ->> 4: 100 ->> R
    */
    
    if (fd < 0)
    {
        perror("r1");
        exit(1);
    }

    sz = write(fd, "hello aggies\n", strlen("hello aggies\n"));

    printf("called write(%d, \"hello aggies\\n\", %d). It returned %d.\n", fd, strlen("hello aggies\n"), sz);

    close(fd);
}
