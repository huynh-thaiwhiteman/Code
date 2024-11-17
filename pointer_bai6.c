#include <stdio.h>

int *compare(int *ptr_a, int *ptr_b)
{
    if(*ptr_a > *ptr_b)
    {
        return ptr_a;
    }
    else
    {
        return ptr_b;
    }
}

int main()
{
    int a = 5;
    int b = 6;
    printf("address of a = 0x%p\n", &a);
    printf("address of b = 0x%p\n", &b);
    printf("address of larger number = 0x%p\n", compare(&a, &b));
    return 0;
}    