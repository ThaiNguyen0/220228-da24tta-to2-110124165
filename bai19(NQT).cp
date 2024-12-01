#define SIZE 100
#include <stdio.h>
#include <math.h>

void nhapMang(int a[], int n);
void xuatMang(int a[], int n);
int tongMang(int a[], int n); 
int tongduong(int a[], int n);
int tongLe(int a[], int n);
int phanAm(int a[], int n);
int phanLe(int a[], int n);
int songuyento(int a[], int n);
int isPrime(int n);
int sontdautien(int a[], int n);
void soduongle(int a[], int n);
int SoAm(int a[], int n);
int TontaiX(int a[], int n, int x);

int main()
{
    int A[SIZE] = {1, -3, 4, -2, 5, 0};
    int n = sizeof(A) / sizeof(A[0]), kq, kq1, kq2, kq3, kq4, kq5, kq6, x;
    
    do
    {
        printf("\nNhap vao so phan tu: ");
        scanf("%d", &n);
    } while(n <= 0 || n > SIZE); 
    
    nhapMang(A, n);
    printf("\nMang vua nhap la: ");
    xuatMang(A, n);
    
    kq = tongMang(A, n);
    printf("\nTong cac gia tri trong mang la: %d", kq);

    kq1 = tongduong(A, n);
    printf("\nTong phan duong trong mang la: %d", kq1); 
    
    kq2 = tongLe(A, n); 
    printf("\nTong vi tri le trong mang la:%d", kq2); 
    
    kq3 = phanAm(A, n);
    printf("\nSo phan tu am trong mang nay la:%d", kq3);
    
    kq4 = phanLe(A, n);
    printf("\nSo phan tu le trong mang nay la:%d", kq4);

    kq5 = songuyento(A, n); 
    printf("\nSo phan tu la so nguyen to trong mang nay la:%d", kq5);

    kq6 = sontdautien(A, n);
    if (kq6 != -1)
        printf("\nSo nguyen to dau tien trong mang la: %d", kq6);
    else
        printf("\nKhong co so nguyen to nao trong mang.");

    printf("\nCac so duong le trong mang la: ");
    soduongle(A, n);
    
    if (SoAm(A, n))
        printf("\nTrong mang co ton tai so am.");
    else
        printf("\nTrong mang khong ton tai so am.");

    printf("\nNhap gia tri x de kiem tra: ");
    scanf("%d", &x);
    if (TontaiX(A, n, x))
        printf("\nMang co ton tai gia tri x = %d.", x);
    else
        printf("\nMang khong ton tai gia tri x = %d.", x);

    return 0;
}

int tongMang(int a[], int n)
{
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong = tong + a[i];
    }
    return tong;
}

void xuatMang(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%8d", a[i]);
    }
}

void nhapMang(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("\nNhap gia tri tai vi tri %d: ", i);
        scanf("%d", &a[i]);
    }
} 

int tongduong(int a[], int n)
{ 
    int tong = 0;
    for (int i = 0; i < n; i++) 
    { 
        if (a[i] > 0)
        { 
            tong += a[i]; 
        }
    }
    return tong;
} 

int tongLe(int a[], int n)
{
    int tong = 0; 
    for (int i = 1; i < n; i += 2) 
    { 
        tong += a[i]; 
    } 
    return tong;
}

int phanAm(int a[], int n)
{
    int dem = 0;
    for(int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            dem++;
        }
    }
    return dem;
}

int phanLe(int a[], int n)
{ 
    int dem = 0; 
    for(int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            dem++;
        }
    }
    return dem;		
} 

int songuyento(int a[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (isPrime(a[i]))
        {
            dem++;
        }
    }
    return dem;
}

int isPrime(int n)
{
    if(n < 2)
        return 0;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int sontdautien(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (isPrime(a[i]))
            return a[i];
    }
    return -1;  
}

void soduongle(int a[], int n)
{
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0 && a[i] % 2 != 0)
        {
            printf("%d ", a[i]);
            found = 1;
        }
    }
    if (!found)
        printf("Khong co so duong le trong mang.");
}

int SoAm(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
            return 1;  
    }
    return 0;  
}

int TontaiX(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            return 1;  
    }
    return 0;  
}  
