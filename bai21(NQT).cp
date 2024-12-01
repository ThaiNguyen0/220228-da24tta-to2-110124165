#include <stdio.h>
#include <stdbool.h>
#define ROW 100
#define COL 100 

void NhapmangA(int A[ROW][COL], int m, int n);
void XuatmangA(int A[ROW][COL], int m, int n);
int tongmangA(int A[ROW][COL], int m, int n);
int TongdongA(int A[ROW][COL], int m, int n, int k);
int TongcotA(int A[ROW][COL], int m, int n, int k); 
bool kiemTraDongAm(int A[ROW][COL], int m, int n, int k);
bool kiemTraCotNguyenTo(int A[ROW][COL], int m, int n, int k);
void sapXepDongGiamDan(int A[ROW][COL], int m, int n, int k);
bool kiemTraCotLe(int A[ROW][COL], int m, int n, int k);
bool kiemTraGiaTriX(int A[ROW][COL], int m, int n, int x);
void timViTriX(int A[ROW][COL], int m, int n, int x);
int timMaxDongK(int A[ROW][COL], int m, int n, int k);
int timMinDongK(int A[ROW][COL], int m, int n, int k);
void inSNTDongK(int A[ROW][COL], int m, int n, int k);
bool kiemTraNguyenTo(int n);

int main() {
    int m, n, k, x;
    int A[ROW][COL];

    // Nh?p s? dòng và s? c?t
    printf("Nhap so dong (max %d): ", ROW);
    scanf("%d", &m);
    printf("Nhap so cot (max %d): ", COL);
    scanf("%d", &n);

    // Ki?m tra s? dòng và s? c?t h?p l?
    if (m <= 0 || m > ROW || n <= 0 || n > COL) {
        printf("So dong va cot khong hop le, vui long nhap lai!\n");
        return 0;
    }

    //goihamcau a
    NhapmangA(A, m, n);

    // goihamcau b
    XuatmangA(A, m, n);

    //goihamcau c
    int tong = tongmangA(A, m, n);
    printf("Tong mang A la: %d\n", tong);

    //goiham cau d
    printf("Nhap chi so dong k (0-%d): ", m-1);
    scanf("%d", &k);
    int tongk = TongdongA(A, m, n, k);
    if (tongk != -1) {
        printf("Tong dong %d cua mang A la: %d\n", k, tongk);
    }

    //goiham cau e
    printf("Nhap chi so cot k (0-%d): ", n-1);
    scanf("%d", &k);
    int tongcotk = TongcotA(A, m, n, k);
    if (tongcotk != -1) {
        printf("Tong cot %d cua mang A la: %d\n", k, tongcotk);
    }

    //goiham cau f
    if (kiemTraDongAm(A, m, n, k)) {
        printf("Dong %d co ton tai so am.\n", k);
    } else {
        printf("Dong %d khong co so am.\n", k);
    }

    //goiham cau g
    if (kiemTraCotNguyenTo(A, m, n, k)) {
        printf("Cot %d co ton tai so nguyen to.\n", k);
    } else {
        printf("Cot %d khong co so nguyen to.\n", k);
    }

    //goiham cau h
    sapXepDongGiamDan(A, m, n, k);
    printf("Doi xung dong %d sau khi sap xep giam dan: ", k);
    for (int j = 0; j < n; j++) {
        printf("%d ", A[k][j]);
    }
    printf("\n");

    //goiham cau i
    if (kiemTraCotLe(A, m, n, k)) {
        printf("Cot %d toan gia tri le.\n", k);
    } else {
        printf("Cot %d khong toan gia tri le.\n", k);
    }

    //goiham cau j
    printf("Nhap gia tri x de kiem tra ton tai: ");
    scanf("%d", &x);
    if (kiemTraGiaTriX(A, m, n, x)) {
        printf("Gia tri %d ton tai trong mang A.\n", x);
    } else {
        printf("Gia tri %d khong ton tai trong mang A.\n", x);
    }

    // goiham cau k
    timViTriX(A, m, n, x);

    // goiham cau l
    int maxK = timMaxDongK(A, m, n, k);
    printf("Gia tri lon nhat tren dong %d la: %d\n", k, maxK);

    // goiham cau m
    int minK = timMinDongK(A, m, n, k);
    printf("Gia tri nho nhat tren dong %d la: %d\n", k, minK);

    // goiham cau n
    printf("Cac so nguyen to tren dong %d: ", k);
    inSNTDongK(A, m, n, k);

    return 0;
}


void NhapmangA(int A[ROW][COL], int m, int n) {
    printf("Nhap mang A:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Nhap A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
}


void XuatmangA(int A[ROW][COL], int m, int n) {
    printf("Mang A:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}


int tongmangA(int A[ROW][COL], int m, int n) {
    int tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            tong += A[i][j];
        }
    }
    return tong;
}


int TongdongA(int A[ROW][COL], int m, int n, int k) {
    if (k < 0 || k >= m) {
        printf("So dong khong hop le!\n");
        return -1;
    }
    int tong = 0;
    for (int j = 0; j < n; j++) {
        tong += A[k][j];
    }
    return tong;
}


int TongcotA(int A[ROW][COL], int m, int n, int k) {
    if (k < 0 || k >= n) {
        printf("So cot khong hop le!\n");
        return -1;
    }
    int tong = 0;
    for (int i = 0; i < m; i++) {
        tong += A[i][k];
    }
    return tong;
}


bool kiemTraDongAm(int A[ROW][COL], int m, int n, int k) {
    if (k < 0 || k >= m) {
        printf("So dong khong hop le!\n");
        return false;
    }
    for (int j = 0; j < n; j++) {
        if (A[k][j] < 0) {
            return true;
        }
    }
    return false;
}


bool kiemTraCotNguyenTo(int A[ROW][COL], int m, int n, int k) {
    for (int i = 0; i < m; i++) {
        if (kiemTraNguyenTo(A[i][k])) {
            return true;
        }
    }
    return false;
}


bool kiemTraNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}


void sapXepDongGiamDan(int A[ROW][COL], int m, int n, int k) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[k][i] < A[k][j]) {
                int temp = A[k][i];
                A[k][i] = A[k][j];
                A[k][j] = temp;
            }
        }
    }
}


bool kiemTraCotLe(int A[ROW][COL], int m, int n, int k) {
    for (int i = 0; i < m; i++) {
        if (A[i][k] % 2 == 0) {
            return false;
        }
    }
    return true;
}


bool kiemTraGiaTriX(int A[ROW][COL], int m, int n, int x) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == x) {
                return true;
            }
        }
    }
    return false;
}


void timViTriX(int A[ROW][COL], int m, int n, int x) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == x) {
                printf("Gia tri %d ton tai tai vi tri: A[%d][%d]\n", x, i, j);
                return;
            }
        }
    }
    printf("Gia tri %d khong ton tai trong mang A.\n", x);
}


int timMaxDongK(int A[ROW][COL], int m, int n, int k) {
    int max = A[k][0];
    for (int j = 1; j < n; j++) {
        if (A[k][j] > max) {
            max = A[k][j];
        }
    }
    return max;
}


int timMinDongK(int A[ROW][COL], int m, int n, int k) {
    int min = A[k][0];
    for (int j = 1; j < n; j++) {
        if (A[k][j] < min) {
            min = A[k][j];
        }
    }
    return min;
}


void inSNTDongK(int A[ROW][COL], int m, int n, int k) {
    bool found = false;
    for (int j = 0; j < n; j++) {
        if (kiemTraNguyenTo(A[k][j])) {
            printf("%d ", A[k][j]);
            found = true;
        }
    }
    if (!found) {
        printf("Khong co so nguyen to tren dong %d.\n", k);
    }
}

