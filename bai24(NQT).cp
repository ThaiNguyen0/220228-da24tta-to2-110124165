#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int tuSo;
    int mauSo;
} PHAN_SO;

void nhapPhanSo(PHAN_SO *ps);
void xuatPhanSo(PHAN_SO ps);
int ucln(int a, int b);
void rutGonPhanSo(PHAN_SO *ps);
PHAN_SO congPhanSo(PHAN_SO ps1, PHAN_SO ps2);
PHAN_SO truPhanSo(PHAN_SO ps1, PHAN_SO ps2);
PHAN_SO nhanPhanSo(PHAN_SO ps1, PHAN_SO ps2);
PHAN_SO chiaPhanSo(PHAN_SO ps1, PHAN_SO ps2);

int main() {
    PHAN_SO ps1, ps2, result;

    printf("Nhap phan so 1:\n");
    nhapPhanSo(&ps1);
    printf("Nhap phan so 2:\n");
    nhapPhanSo(&ps2);

    printf("Phan so 1: ");
    xuatPhanSo(ps1);
    printf("\nPhan so 2: ");
    xuatPhanSo(ps2);
    printf("\n");

    rutGonPhanSo(&ps1);
    rutGonPhanSo(&ps2);
    printf("\nPhan so 1 sau khi rut gon: ");
    xuatPhanSo(ps1);
    printf("\nPhan so 2 sau khi rut gon: ");
    xuatPhanSo(ps2);
    printf("\n");

    result = congPhanSo(ps1, ps2);
    printf("\nTong 2 phan so: ");
    xuatPhanSo(result);
    printf("\n");

    result = truPhanSo(ps1, ps2);
    printf("\nHieu 2 phan so: ");
    xuatPhanSo(result);
    printf("\n");

    result = nhanPhanSo(ps1, ps2);
    printf("\nTich 2 phan so: ");
    xuatPhanSo(result);
    printf("\n");

    result = chiaPhanSo(ps1, ps2);
    printf("\nThuong 2 phan so: ");
    xuatPhanSo(result);
    printf("\n");

    return 0;
}

void nhapPhanSo(PHAN_SO *ps) {
    do {
        printf("Nhap tu so: ");
        scanf("%d", &ps->tuSo);
        printf("Nhap mau so: ");
        scanf("%d", &ps->mauSo);
        if (ps->mauSo == 0) {
            printf("Mau so phai khac 0. Vui long nhap lai!\n");
        }
    } while (ps->mauSo == 0);
}

void xuatPhanSo(PHAN_SO ps) {
    printf("%d/%d", ps.tuSo, ps.mauSo);
}

int ucln(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void rutGonPhanSo(PHAN_SO *ps) {
    int gcd = ucln(abs(ps->tuSo), abs(ps->mauSo));
    ps->tuSo /= gcd;
    ps->mauSo /= gcd;
    if (ps->mauSo < 0) {
        ps->tuSo = -ps->tuSo;
        ps->mauSo = -ps->mauSo;
    }
}

PHAN_SO congPhanSo(PHAN_SO ps1, PHAN_SO ps2) {
    PHAN_SO result;
    result.tuSo = ps1.tuSo * ps2.mauSo + ps2.tuSo * ps1.mauSo;
    result.mauSo = ps1.mauSo * ps2.mauSo;
    rutGonPhanSo(&result);
    return result;
}

PHAN_SO truPhanSo(PHAN_SO ps1, PHAN_SO ps2) {
    PHAN_SO result;
    result.tuSo = ps1.tuSo * ps2.mauSo - ps2.tuSo * ps1.mauSo;
    result.mauSo = ps1.mauSo * ps2.mauSo;
    rutGonPhanSo(&result);
    return result;
}

PHAN_SO nhanPhanSo(PHAN_SO ps1, PHAN_SO ps2) {
    PHAN_SO result;
    result.tuSo = ps1.tuSo * ps2.tuSo;
    result.mauSo = ps1.mauSo * ps2.mauSo;
    rutGonPhanSo(&result);
    return result;
}

PHAN_SO chiaPhanSo(PHAN_SO ps1, PHAN_SO ps2) {
    PHAN_SO result;
    result.tuSo = ps1.tuSo * ps2.mauSo;
    result.mauSo = ps1.mauSo * ps2.tuSo;
    rutGonPhanSo(&result);
    return result;
}

