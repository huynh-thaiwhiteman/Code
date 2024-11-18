#include<stdio.h>
#include<string.h>

struct Tacgia{
    char hoten[100];
    char quoctich[100];
};


struct Sach{
    struct Tacgia tg;
    char tensach[100];
    int giaban;
};


int main(){
    struct Sach s;
    gets(s.tensach);
    s.giaban = 500000;
    gets(s.tg.hoten);
    gets(s.tg.quoctich);
    printf("Thong tin sach : \n");
    printf("Tieu de : %s\n", s.tensach);
    printf("Ten tac gia : %s\n", s.tg.hoten);
    printf("Quoc tich tac gia : %s\n", s.tg.quoctich);
    printf("Gia ban : %dVNĐ\n", s.giaban);
    return 0;
}

