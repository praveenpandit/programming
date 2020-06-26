#include <stdio.h>

int avg(int a, int b)
{
    return (a / 2) + (b / 2) + ((a & 1) ^ (b & 1) ^ 1);
}
int main()
{
    int a = 3;
    int b = 5;
    printf("%d \n", avg(a, b));
    char s[] = "hello%ok";
    printf("%s\n", s);
    printf(s);
    return 0;
}