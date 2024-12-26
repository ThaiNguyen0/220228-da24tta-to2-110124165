#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct NGAY_THANG {
    int ngay;
    int thang;
    int nam;
};

struct MON_HOC {
    char ma_mon[10];
    float diem;
};

struct SINH_VIEN {
    char mssv[20];
    char hoten[100];
    struct NGAY_THANG ngaysinh;
    char gioi_tinh[10];
    char dia_chi[100];
    int somon;
    struct MON_HOC *mon_hoc;
};

struct LOP_HOC {
    char malop[20];
    char tenlop[100];
    int siso;
    struct SINH_VIEN *dssv;  
};

void nhap_sinh_vien(struct SINH_VIEN *sv);
void xuat_sinh_vien(struct SINH_VIEN sv);
void nhap_lop_hoc(struct LOP_HOC *lop);
void xuat_lop_hoc(struct LOP_HOC lop);
void ghi_lop_hoc_vao_file(struct LOP_HOC *lop, int n);
void doc_lop_hoc_tu_file(struct LOP_HOC **lop, int *n);
void hien_thi_sinh_vien_lop(struct LOP_HOC *lop, int n, char *malop);
void thong_ke_sinh_vien_gioi_tinh(struct LOP_HOC *lop, int n);
void thong_ke_sinh_vien_no_mon(struct LOP_HOC *lop, int n);

int main() {
    int n;
    printf("Nhap so luong lop hoc: ");
    scanf("%d", &n);
    struct LOP_HOC *lop_hoc = (struct LOP_HOC*) malloc(n * sizeof(struct LOP_HOC));

    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin lop hoc %d:\n", i + 1);
        nhap_lop_hoc(&lop_hoc[i]);
    }

    ghi_lop_hoc_vao_file(lop_hoc, n);

    struct LOP_HOC *doc_lop = NULL;
    int doc_n;
    doc_lop_hoc_tu_file(&doc_lop, &doc_n);

    char malop[20];
    printf("\nNhap ma lop can hien thi: ");
    scanf("%s", malop);
    hien_thi_sinh_vien_lop(doc_lop, doc_n, malop);

    thong_ke_sinh_vien_gioi_tinh(doc_lop, doc_n);
    thong_ke_sinh_vien_no_mon(doc_lop, doc_n);

    for (int i = 0; i < n; i++) {
        free(lop_hoc[i].dssv);
    }
    free(lop_hoc);
    free(doc_lop);
    return 0;
}

void nhap_sinh_vien(struct SINH_VIEN *sv) {
    printf("Nhap ma so sinh vien: ");
    scanf("%s", sv->mssv);
    printf("Nhap ho ten sinh vien: ");
    getchar();
    fgets(sv->hoten, 100, stdin);
    sv->hoten[strcspn(sv->hoten, "\n")] = 0;
    printf("Nhap ngay sinh (ngay thang nam): ");
    scanf("%d %d %d", &sv->ngaysinh.ngay, &sv->ngaysinh.thang, &sv->ngaysinh.nam);
    printf("Nhap gioi tinh: ");
    getchar();
    fgets(sv->gioi_tinh, 10, stdin);
    sv->gioi_tinh[strcspn(sv->gioi_tinh, "\n")] = 0;
    printf("Nhap dia chi: ");
    fgets(sv->dia_chi, 100, stdin);
    sv->dia_chi[strcspn(sv->dia_chi, "\n")] = 0;
    printf("Nhap so mon hoc: ");
    scanf("%d", &sv->somon);

    sv->mon_hoc = (struct MON_HOC*) malloc(sv->somon * sizeof(struct MON_HOC));
    for (int i = 0; i < sv->somon; i++) {
        printf("Nhap ma mon hoc %d: ", i + 1);
        scanf("%s", sv->mon_hoc[i].ma_mon);
        printf("Nhap diem mon hoc %d: ", i + 1);
        scanf("%f", &sv->mon_hoc[i].diem);
    }
}

void xuat_sinh_vien(struct SINH_VIEN sv) {
    printf("\nMSSV: %s\n", sv.mssv);
    printf("Ho ten: %s\n", sv.hoten);
    printf("Ngay sinh: %d/%d/%d\n", sv.ngaysinh.ngay, sv.ngaysinh.thang, sv.ngaysinh.nam);
    printf("Gioi tinh: %s\n", sv.gioi_tinh);
    printf("Dia chi: %s\n", sv.dia_chi);
    printf("So mon hoc: %d\n", sv.somon);
    for (int i = 0; i < sv.somon; i++) {
        printf("Mon %d - Ma mon: %s, Diem: %.2f\n", i + 1, sv.mon_hoc[i].ma_mon, sv.mon_hoc[i].diem);
    }
}

void nhap_lop_hoc(struct LOP_HOC *lop) {
    printf("Nhap ma lop: ");
    scanf("%s", lop->malop);
    printf("Nhap ten lop: ");
    getchar();
    fgets(lop->tenlop, 100, stdin);
    lop->tenlop[strcspn(lop->tenlop, "\n")] = 0;
    printf("Nhap si so: ");
    scanf("%d", &lop->siso);

    lop->dssv = (struct SINH_VIEN*) malloc(lop->siso * sizeof(struct SINH_VIEN));
    for (int i = 0; i < lop->siso; i++) {
        printf("\nNhap thong tin sinh vien %d:\n", i + 1);
        nhap_sinh_vien(&lop->dssv[i]);
    }
}

void xuat_lop_hoc(struct LOP_HOC lop) {
    printf("\nMa lop: %s\n", lop.malop);
    printf("Ten lop: %s\n", lop.tenlop);
    printf("Si so: %d\n", lop.siso);
    for (int i = 0; i < lop.siso; i++) {
        xuat_sinh_vien(lop.dssv[i]);
    }
}

void ghi_lop_hoc_vao_file(struct LOP_HOC *lop, int n) {
    FILE *file = fopen("lop_hoc.dat", "wb");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }
    fwrite(&n, sizeof(int), 1, file);
    for (int i = 0; i < n; i++) {
        fwrite(&lop[i], sizeof(struct LOP_HOC), 1, file);
    }
    fclose(file);
}

void doc_lop_hoc_tu_file(struct LOP_HOC **lop, int *n) {
    FILE *file = fopen("lop_hoc.dat", "rb");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }
    fread(n, sizeof(int), 1, file);
    *lop = (struct LOP_HOC*) malloc(*n * sizeof(struct LOP_HOC));
    for (int i = 0; i < *n; i++) {
        fread(&(*lop)[i], sizeof(struct LOP_HOC), 1, file);
    }
    fclose(file);
}

void hien_thi_sinh_vien_lop(struct LOP_HOC *lop, int n, char *malop) {
    for (int i = 0; i < n; i++) {
        if (strcmp(lop[i].malop, malop) == 0) {
            printf("\nDanh sach sinh vien cua lop %s:\n", malop);
            xuat_lop_hoc(lop[i]);
            return;
        }
    }
    printf("Lop %s khong ton tai.\n", malop);
}

void thong_ke_sinh_vien_gioi_tinh(struct LOP_HOC *lop, int n) {
    for (int i = 0; i < n; i++) {
        int nam = 0, nu = 0;
        for (int j = 0; j < lop[i].siso; j++) {
            if (strcmp(lop[i].dssv[j].gioi_tinh, "nam") == 0) {
                nam++;
            } else if (strcmp(lop[i].dssv[j].gioi_tinh, "nu") == 0) {
                nu++;
            }
        }
        printf("Lop %s - Nam: %d, Nu: %d\n", lop[i].malop, nam, nu);
    }
}

void thong_ke_sinh_vien_no_mon(struct LOP_HOC *lop, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nLop %s - Danh sach sinh vien no mon:\n", lop[i].malop);
        for (int j = 0; j < lop[i].siso; j++) {
            int nmon_no = 0;
            for (int k = 0; k < lop[i].dssv[j].somon; k++) {
                if (lop[i].dssv[j].mon_hoc[k].diem < 5) {
                    nmon_no++;
                }
            }
            if (nmon_no > 0) {
                printf("MSSV: %s, Ho ten: %s, So mon no: %d\n", lop[i].dssv[j].mssv, lop[i].dssv[j].hoten, nmon_no);
            }
        }
    }
}

