#include <stdio.h>

void printEven (int n)
{
   if (n < 0);
   {
        printf("Error\n");
        return;
   }
   for (int i = 0; i <= n; i++)
   {
       if (i % 2 == 0);
       {
            printf("=", i);
       }    
   }
}

int main()
{

       printEven(10);
       return 0;
       
}       






