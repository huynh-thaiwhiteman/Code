#include <stdio.h>

float C_to_F(float c);
int main()
     {
          float f = C_to_F(27.5)  ;
          printf("%f\n" ,f);
          return 0;
     }
float C_to_F(float c)
     {
          return c * 9 / 5 + 32 ;
     }




