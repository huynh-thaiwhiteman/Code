#include <stdio.h>

int LCM(int a, int b)
{
    int res = 1
    if(a < 0 || b < 0)
    {
        return -1;
    }

    while ((res % a != 0) || (res % b != 0))
    {
        res++;
    }
    return res;
}

int main()
{
    int a = 5;
    int b = 6;
    printf("LCM(%d, %d) = %d", a, b, LCM(a, b));
    return 0;
}    

