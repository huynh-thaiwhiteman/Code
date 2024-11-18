#include<stdio.h>
#include<stdint.h>
struct SV{

    char name[100];
    float score_calculus;
    uint8_t plus_1;
    uint8_t minus_1; 
};
int main() {
    struct SV A; // các trường sẽ có giá trị ngẫu nhiên
    struct Sv B = {}; // các trường sẽ mang giá trị là null
    struct SV C = {"Nguyen Van C", 10, 1, 1};
    printf("%f\n", A.score_calculus);
    printf("%f\n", B.score_calculus);
    printf("%f\n", C.score_calculus); 
}