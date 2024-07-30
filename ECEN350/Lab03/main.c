/* main.c simple program to test assembler program */

#include <stdio.h>

extern long long int test(long long int a, long long int b);
extern long long int lab03b();
extern void lab03c(long long int a);
int main(void)
{
    long long int a = test(3, 5);
    printf("Result of test(3, 5) = %lld\n", a);
    long long int b = lab03b();
    printf("Result of lab03b(UIN=34) = %lld\n", b);
    lab03c(23);
    return 0;
}
