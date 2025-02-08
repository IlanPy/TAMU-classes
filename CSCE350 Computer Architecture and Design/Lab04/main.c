/* main.c simple program to test assembler program */

#include <stdio.h>

extern long long int my_mul(long long int a, long long int b);
extern long long int lab04b(long long int n); 

int main(void)
{
    //long long int a = my_mul(3, 5);
    //printf("Result of my_mul(3, 5) = %lld\n", a);
    //long long int c = lab04b(0);
    //printf("Result of fact(0) = %lld\n", c);
    //long long int d = lab04b(1);
    //printf("Result of fact(1) = %lld\n", d);
    //long long int e = lab04b(2);
    //printf("Result of fact(2) = %lld\n", e);
    long long int f = lab04b(3);
    printf("Result of fact(3) = %lld\n", f);
    //long long int g = lab04b(4);
    //printf("Result of fact(4) = %lld\n", g);
    //long long int h = lab04b(5);
    //printf("Result of fact(5) = %lld\n", h);
    return 0;
}
