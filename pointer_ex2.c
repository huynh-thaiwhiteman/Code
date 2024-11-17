#include <stdio.h>
void funcX(char *a)
{
    *a = 15;
}
int main()
{
    char a = 10;
    short int b = 65;
    char c = 66;
    float f = 3.14;
    funcX(&a);
    printf("a = %d", a);
    return 0; 
}

