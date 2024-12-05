#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MON_HOC 10
#define MAX_SINH_VIEN 100

struct NGAY_THANG {
    int ngay;
    int thang;
    int nam;
};

struct MON_HOC {
    char mamon[10];
    float diem;
};

struct SINH_VIEN {
    char mssv[15];
    char hoten[50];
    struct NGAY_THANG ngaysinh;
    char gioi_tinh[10];
    char dia_chi[100];
    int somon;
    struct MON_HOC monhoc[MAX_MON_HOC];
};

typedef struct SINH_VIEN SINH_VIEN;

void nhap_ngaysinh(struct NGAY_THANG *ngay) {
    printf("Nhap ngay sinh (dd mm yyyy): ");
    scanf("%d %d %d", &ngay->ngay, &ngay->thang, &ngay->nam);
}

void nhap_monhoc(struct MON_HOC *monhoc) {
    printf("Nhap ma mon: ");
    scanf("%s", monhoc->mamon);
    printf("Nhap diem mon: ");
    scanf("%f", &monhoc->diem);
}

void nhap_sinhvien(SINH_VIEN *sv) {
    printf("\nNhap MSSV: ");
    scanf("%s", sv->mssv);
    
    printf("Nhap ho ten: ");
    getchar();
    fgets(sv->hoten, sizeof(sv->hoten), stdin);
    sv->hoten[strcspn(sv->hoten, "\n")] = 0;

    nhap_ngaysinh(&sv->ngaysinh);

    printf("Nhap gioi tinh: ");
    fgets(sv->gioi_tinh, sizeof(sv->gioi_tinh), stdin);
    sv->gioi_tinh[strcspn(sv->gioi_tinh, "\n")] = 0;

    printf("Nhap dia chi: ");
    fgets(sv->dia_chi, sizeof(sv->dia_chi), stdin);
    sv->dia_chi[strcspn(sv->dia_chi, "\n")] = 0;

    printf("Nhap so mon hoc: ");
    scanf("%d", &sv->somon);

    for (int i = 0; i < sv->somon; i++) {
        nhap_monhoc(&sv->monhoc[i]);
    }
}

void xuat_monhoc(struct MON_HOC *monhoc) {
    printf("  Ma mon: %s, Diem: %.2f\n", monhoc->mamon, monhoc->diem);
}

void xuat_sinhvien(SINH_VIEN *sv) {
    printf("\nMSSV: %s\n", sv->mssv);
    printf("Ho ten: %s\n", sv->hoten);
    printf("Ngay sinh: %02d/%02d/%d\n", sv->ngaysinh.ngay, sv->ngaysinh.thang, sv->ngaysinh.nam);
    printf("Gioi tinh: %s\n", sv->gioi_tinh);
    printf("Dia chi: %s\n", sv->dia_chi);
    printf("So mon hoc: %d\n", sv->somon);

    for (int i = 0; i < sv->somon; i++) {
        xuat_monhoc(&sv->monhoc[i]);
    }
}

void nhap_danhsach_sinhvien(SINH_VIEN ds[], int *n) {
    printf("Nhap so sinh vien: ");
    scanf("%d", n);
    
    for (int i = 0; i < *n; i++) {
        printf("\nNhap thong tin sinh vien %d:\n", i + 1);
        nhap_sinhvien(&ds[i]);
    }
}

void xuat_danhsach_sinhvien(SINH_VIEN ds[], int n) {
    for (int i = 0; i < n; i++) {
        xuat_sinhvien(&ds[i]);
    }
}

SINH_VIEN* tim_sinhvien_theo_mssv(SINH_VIEN ds[], int n, char *mssv) {
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].mssv, mssv) == 0) {
            return &ds[i];
        }
    }
    return NULL;
}

void tim_sinhvien_theo_ten(SINH_VIEN ds[], int n, char *ten) {
    printf("\nDanh sach sinh vien co ten '%s':\n", ten);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(ds[i].hoten, ten) != NULL) {
            xuat_sinhvien(&ds[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co ten '%s'\n", ten);
    }
}

void tim_sinhvien_sinh_thang_8(SINH_VIEN ds[], int n) {
    printf("\nDanh sach sinh vien sinh trong thang 8:\n");
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i].ngaysinh.thang == 8) {
            xuat_sinhvien(&ds[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien sinh trong thang 8\n");
    }
}

void tim_sinhvien_theo_gioitinh(SINH_VIEN ds[], int n, char *gioitinh) {
    printf("\nDanh sach sinh vien gioi tinh '%s':\n", gioitinh);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(ds[i].gioi_tinh, gioitinh) != NULL) {
            xuat_sinhvien(&ds[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien gioi tinh '%s'\n", gioitinh);
    }
}

void tim_sinhvien_theo_diachi(SINH_VIEN ds[], int n, char *diachi) {
    printf("\nDanh sach sinh vien co dia chi '%s':\n", diachi);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(ds[i].dia_chi, diachi) != NULL) {
            xuat_sinhvien(&ds[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co dia chi '%s'\n", diachi);
    }
}

int main() {
    SINH_VIEN ds[MAX_SINH_VIEN];
    int n;
    
    nhap_danhsach_sinhvien(ds, &n);
    xuat_danhsach_sinhvien(ds, n);

    char mssv[15];
    printf("\nNhap MSSV can tim: ");
    scanf("%s", mssv);
    SINH_VIEN *sv = tim_sinhvien_theo_mssv(ds, n, mssv);
    if (sv != NULL) {
        xuat_sinhvien(sv);
    } else {
        printf("Khong tim thay sinh vien co MSSV '%s'\n", mssv);
    }

    char ten[50];
    printf("\nNhap ten can tim: ");
    getchar();
    fgets(ten, sizeof(ten), stdin);
    ten[strcspn(ten, "\n")] = 0;
    tim_sinhvien_theo_ten(ds, n, ten);

    tim_sinhvien_sinh_thang_8(ds, n);

    char gioitinh[10];
    printf("\nNhap gioi tinh can tim: ");
    fgets(gioitinh, sizeof(gioitinh), stdin);
    gioitinh[strcspn(gioitinh, "\n")] = 0;
    tim_sinhvien_theo_gioitinh(ds, n, gioitinh);

    char diachi[100];
    printf("\nNhap dia chi can tim: ");
    fgets(diachi, sizeof(diachi), stdin);
    diachi[strcspn(diachi, "\n")] = 0;
    tim_sinhvien_theo_diachi(ds, n, diachi);

    return 0;
}

