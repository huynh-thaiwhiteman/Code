#include <stdio.h>

void sum(int *ptr_a, int b)
{
    *ptr_a = *ptr_a + b;
}

int main()
{
    int a = 5;
    int b = 6;
    sum(&a, b);
    printf("a = %d\nb = %d\n", a, b);
    return 0;
}
