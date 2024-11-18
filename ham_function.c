#include <stdio.h>
int main()
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    int swap_1 = b;
    b = a;
    a = swap_1;

    int c, d;
    scanf("%d", &c);
    scanf("%d", &d);

    int swap_2 = d;
    d = c;
    c = swap_2;

    return 0;
}    



