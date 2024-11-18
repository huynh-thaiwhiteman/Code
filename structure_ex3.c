#include<stdio.h>
#include<string.h>

struct CauThu{
    char hoten[50];
    char clb[50];
    char quoctich[50];
    int banthang, kientao;
};


struct CauThu nhap(){
    struct CauThu x;
    printf("Nhap ho ten : "); gets(x.hoten);
    printf("Nhap clb : "); gets(x.clb);
    printf("Quoc tich : "); gets(x.quoctich);
    printf("So ban thang: ");
    scanf("%d", &x.banthang);
    printf("So kien tao: ");
    scanf("%d", &x.kientao);
    return x;
}

void xuat(struct Cauthu x){
    printf("Thong tin cau thu : \n");
    printf("Ho ten : %s\n", x.hoten);
    printf("CLB : %s\n", x.clb);
    printf("Quoc tich: %s\n", x.quoctich);
    printf("Ban thang : %d, kien tao : %d\n", x.banthang, x.kientao);
}

int main(){
    struct Cauthu s = nhap();
    xuat(s);
    return 0;
}
