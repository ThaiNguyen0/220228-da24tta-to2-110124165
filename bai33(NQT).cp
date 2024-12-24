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
float giaTriPhanSo(PHAN_SO ps);
void ghiDanhSachPhanSo(PHAN_SO *ps, int n, const char *filename);
void docDanhSachPhanSo(PHAN_SO *ps, int *n, const char *filename);
PHAN_SO timPhanSoNhoNhat(PHAN_SO *ps, int n);
int demPhanSoNhoNhat(PHAN_SO *ps, int n, PHAN_SO min);
void sapXepPhanSo(PHAN_SO *ps, int n);

int main() {
    PHAN_SO ps[100], min;
    int n;

    printf("Nhap so luong phan so: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap phan so %d:\n", i + 1);
        nhapPhanSo(&ps[i]);
        rutGonPhanSo(&ps[i]);
    }

    ghiDanhSachPhanSo(ps, n, "danhsach.txt");

    docDanhSachPhanSo(ps, &n, "danhsach.txt");

    printf("\nDanh sach phan so sau khi rut gon:\n");
    for (int i = 0; i < n; i++) {
        xuatPhanSo(ps[i]);
        printf("\n");
    }

    min = timPhanSoNhoNhat(ps, n);
    printf("\nPhan so co gia tri nho nhat: ");
    xuatPhanSo(min);
    printf("\n");

    int count = demPhanSoNhoNhat(ps, n, min);
    printf("So phan so co gia tri nho nhat: %d\n", count);

    sapXepPhanSo(ps, n);
    printf("\nDanh sach phan so sau khi sap xep theo thu tu giam dan:\n");
    for (int i = 0; i < n; i++) {
        xuatPhanSo(ps[i]);
        printf("\n");
    }

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

float giaTriPhanSo(PHAN_SO ps) {
    return (float)ps.tuSo / ps.mauSo;
}

void ghiDanhSachPhanSo(PHAN_SO *ps, int n, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d %d\n", ps[i].tuSo, ps[i].mauSo);
    }
    fclose(file);
}

void docDanhSachPhanSo(PHAN_SO *ps, int *n, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }
    *n = 0;
    while (fscanf(file, "%d %d", &ps[*n].tuSo, &ps[*n].mauSo) == 2) {
        rutGonPhanSo(&ps[*n]);
        (*n)++;
    }
    fclose(file);
}

PHAN_SO timPhanSoNhoNhat(PHAN_SO *ps, int n) {
    PHAN_SO min = ps[0];
    for (int i = 1; i < n; i++) {
        if (giaTriPhanSo(ps[i]) < giaTriPhanSo(min)) {
            min = ps[i];
        }
    }
    return min;
}

int demPhanSoNhoNhat(PHAN_SO *ps, int n, PHAN_SO min) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (giaTriPhanSo(ps[i]) == giaTriPhanSo(min)) {
            count++;
        }
    }
    return count;
}

void sapXepPhanSo(PHAN_SO *ps, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (giaTriPhanSo(ps[i]) < giaTriPhanSo(ps[j])) {
                PHAN_SO temp = ps[i];
                ps[i] = ps[j];
                ps[j] = temp;
            }
        }
    }
}

