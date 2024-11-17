#include <stdio.h>

void swap (int *ptr_a, int *ptr_b)
{
    int temp = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b + temp;
}

int main()
{
    int a = 5;
    int b = 6;
    swap(&a, &b);
    printf("a = %d\nb = %d\n", a, b);
    return 0;
}    

