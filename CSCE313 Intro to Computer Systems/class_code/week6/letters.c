#include "apue.h"
#include <fcntl.h>

char    buf1[] = "abcdefghij";
char    buf2[] = "ABCDEFGHIJ";
int main(void)
{
  int fd;
  if ((fd = creat("data.txt", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)  // open()
    printf("creat error");
  if (write(fd, buf1, 10) != 10)
    printf("buf1 write error");

  if (lseek(fd, 16384, SEEK_CUR) == -1) // lseek moves the file cursor by 16384 bytes
    printf("lseek error");


  if (write(fd, buf2, 10) != 10) // Write the same letters in UPPERCASE
    printf("buf2 write error");
    
  exit(0);
}

