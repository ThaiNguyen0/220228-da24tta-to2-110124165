#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n);
void bai17a();
void bai17b();
void bai17c();
void bai17d();
void bai17e();
void bai17f();
void bai17g();
void bai17h();
void bai17i();

int main() {
    bai17a();
    bai17b();
    bai17c();
    bai17d();
    bai17e();
    bai17f();
    bai17g();
    bai17h();
    bai17i();
    return 0;
}


bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}


void bai17a() {
    int n;
    printf("Nhap mot so nguyen n (n < 100): ");
    scanf("%d", &n);
    if (n >= 100) {
        printf("Nhap gia tri sai, vui long nhap lai (n < 100)\n");
    } else {
        for (int i = 1; i <= n; i++) {
            printf("%d ", i);
        }
        printf("\n");
    }
}


void bai17b() {
    int n;
    printf("Nhap mot so nguyen n (n < 100): ");
    scanf("%d", &n);
    if (n >= 100) {
        printf("Nhap gia tri sai, vui long nhap lai (n < 100)\n");
    } else {
        for (int i = 0; i <= n; i += 2) {
            printf("%d ", i);
        }
        printf("\n");
    }
}


void bai17c() {
    int n;
    printf("Nhap mot so nguyen n (n < 100): ");
    scanf("%d", &n);
    if (n >= 100) {
        printf("Nhap gia tri sai, vui long nhap lai (n < 100)\n");
    } else {
        for (int i = 0; i <= n; i += 5) {
            printf("%d ", i);
        }
        printf("\n");
    }
}


void bai17d() {
    int n;
    printf("Nhap so nguyen duong n (n < 100): ");
    scanf("%d", &n);
    if (n >= 100) {
        printf("Nhap gia tri sai, vui long nhap lai (n < 100)\n");
    } else if (n < 2) {
        printf("Nhap sai gia tri, vui long nhap lai!\n");
    } else {
        for (int i = 2; i < n; i++) {
            if (isPrime(i)) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
}


void bai17e() {
    int n, sum = 0;
    printf("Nhap mot so nguyen n (n < 100): ");
    scanf("%d", &n);
    if (n >= 100) {
        printf("Nhap gia tri sai, vui long nhap lai (n < 100)\n");
    } else {
        for (int i = 1; i <= n; i++) {
            sum += i;
        }
        printf("Tong cac so tu 1 den %d la: %d\n", n, sum);
    }
}


void bai17f() {
    int n, sum = 0;
    printf("Nhap mot so nguyen n (n < 100): ");
    scanf("%d", &n);
    if (n >= 100) {
        printf("Nhap gia tri sai, vui long nhap lai (n < 100)\n");
    } else {
        for (int i = 1; i <= n; i += 2) {
            sum += i;
        }
        printf("Tong cac so le tu 1 den %d la: %d\n", n, sum);
    }
}


void bai17g() {
    int n, sum = 0;
    printf("Nhap mot so nguyen n (n < 100): ");
    scanf("%d", &n);
    if (n >= 100) {
        printf("Nhap gia tri sai, vui long nhap lai (n < 100)\n");
    } else {
        for (int i = 2; i < n; i++) {
            if (isPrime(i)) {
                sum += i;
            }
        }
        printf("Tong cac so nguyen to nho hon %d la: %d\n", n, sum);
    }
}


void bai17h() {
    int n, sum = 0, count = 0;
    printf("Nhap mot so nguyen n (n < 100): ");
    scanf("%d", &n);
    if (n >= 100) {
        printf("Nhap gia tri sai, vui long nhap lai (n < 100)\n");
    } else {
        for (int i = 1; i <= n; i += 2) {
            sum += i;
            count++;
        }
        if (count > 0) {
            printf("Trung binh cong cac so le tu 1 den %d la: %.2f\n", n, (float)sum / count);
        }
    }
}


void bai17i() {
    int n, sum = 0, count = 0;
    printf("Nhap mot so nguyen n (n < 100): ");
    scanf("%d", &n);
    if (n >= 100) {
        printf("Nhap gia tri sai, vui long nhap lai (n < 100)\n");
    } else {
        for (int i = 2; i < n; i++) {
            if (isPrime(i)) {
                sum += i;
                count++;
            }
        }
        if (count > 0) {
            printf("Trung binh cong cac so nguyen to nho hon %d la: %.2f\n", n, (float)sum / count);
        }
    }
}
