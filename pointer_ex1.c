#include <stdio.h>
int main()
{
int a = 65535;
int *ptr_a = &a;
printf(“address of a = 0x%p\n”, ptr_a);
printf(“a = %d\n”, *ptr_a );
*ptr_a = 255;
printf(“a = %d\n”, a);
return 0;
}
