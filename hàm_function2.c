#include <stdio.h>
void swap (int a, int b);
{
    int tmp = b;
    b = a;
    a = tmp;
    printf("value after swap of first parameter: %d\n", a);
    printf("value after swap of second parameter: %d\n", b);
}
int main()
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    swap(a, b);

    int c, d;
    scanf("%d", &c);
    scanf("%d", &d);
    swap(c, d);

    return 0;
}



