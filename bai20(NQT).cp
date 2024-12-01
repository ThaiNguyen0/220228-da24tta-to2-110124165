#include <stdio.h>
#define SIZE 100

void nhapMangA(float a[], int n);
void xuatMangA(float a[], int n);
float TongA(float a[], int n);
float TBViTriLeA(float a[], int n);
int DemsoduongA(float a[], int n);
void TangdanA(float a[], int n);
void GiatrileA(float a[], int n);
void VitrizeroA(float a[], int n);
float TimGiaTriLonNhatA(float a[], int n);
int TimViTriLonNhatDauTienA(float a[], int n);
void InTatCaViTriLonNhatA(float a[], int n);
int KiemTraMangToanSoAmA(float a[], int n);

int main() {
    float a[SIZE];
    int n, kq3, toanSoAm;
    float kq1, kq2, maxValue;

    do {
        printf("\nNhap vao so phan tu: ");
        scanf("%d", &n);

        if (n <= 0 || n > SIZE) {
            printf("So phan tu khong hop le, vui long nhap lai!\n");
        }
    } while (n <= 0 || n > SIZE);

    nhapMangA(a, n);
    printf("\nMang A vua nhap: ");
    xuatMangA(a, n);

    kq1 = TongA(a, n);
    printf("\nTong cac gia tri trong mang la: %.2f", kq1);

    kq2 = TBViTriLeA(a, n);
    printf("\nTrung binh cong tai vi tri le la: %.2f", kq2);

    kq3 = DemsoduongA(a, n);
    printf("\nCac so duong trong mang la: %d", kq3);

    TangdanA(a, n);
    printf("\nThu tu tang dan cua mang: ");
    xuatMangA(a, n);

    GiatrileA(a, n);
    VitrizeroA(a, n);

    maxValue = TimGiaTriLonNhatA(a, n);
    printf("\nGia tri lon nhat trong mang la: %.2f", maxValue);

    int viTriDauTien = TimViTriLonNhatDauTienA(a, n);
    printf("\nVi tri dau tien co gia tri lon nhat la: %d", viTriDauTien);

    printf("\nTat ca vi tri co gia tri lon nhat: ");
    InTatCaViTriLonNhatA(a, n);

    toanSoAm = KiemTraMangToanSoAmA(a, n);
    if (toanSoAm) {
        printf("\nMang chi toan so am.");
    } else {
        printf("\nMang khong chi toan so am.");
    }

    return 0;
}

void nhapMangA(float a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Vui long nhap gia tri cua phan tu A[%d]: ", i);
        scanf("%f", &a[i]);
    }
}

void xuatMangA(float a[], int n) {
    printf("Gom cac phan tu: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }
    printf("\n");
}

float TongA(float a[], int n) {
    float tong = 0;
    for (int i = 0; i < n; i++) {
        tong += a[i];
    }
    return tong;
}

float TBViTriLeA(float a[], int n) {
    float tong = 0;
    int dem = 0;
    for (int i = 1; i < n; i += 2) {
        tong += a[i];
        dem++;
    }
    return (dem > 0) ? (tong / dem) : 0;
}

int DemsoduongA(float a[], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            dem++;
        }
    }
    return dem;
}

void TangdanA(float a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                float temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void GiatrileA(float a[], int n) {
    printf("\nGia tri tai vi tri le: ");
    for (int i = 1; i < n; i += 2) {
        printf("%.2f ", a[i]);
    }
    printf("\n");
}

void VitrizeroA(float a[], int n) {
    int found = 0;
    printf("Vi tri co gia tri 0: ");
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong co gia tri nao bang 0 trong mang.");
    }
    printf("\n");
}

float TimGiaTriLonNhatA(float a[], int n) {
    float max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int TimViTriLonNhatDauTienA(float a[], int n) {
    float max = TimGiaTriLonNhatA(a, n);
    for (int i = 0; i < n; i++) {
        if (a[i] == max) {
            return i;
        }
    }
    return -1;
}

void InTatCaViTriLonNhatA(float a[], int n) {
    float max = TimGiaTriLonNhatA(a, n);
    for (int i = 0; i < n; i++) {
        if (a[i] == max) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int KiemTraMangToanSoAmA(float a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) {
            return 0;
        }
    }
    return 1;
}
