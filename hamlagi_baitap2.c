#include <stdio.h>

int fractional(int n)
{
    int res = 1;
    if (n < 0)
    {
        return -1;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            res = res * i;
        }
        return res;
    }
}

int main()
{ 
    int n = 5;
    printf("%d! = %d", n, fractional (n));
    return 0;
}            