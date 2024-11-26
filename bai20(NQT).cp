#include <stdio.h>
#define SIZE 100

void nhapMangA(float a[], int n); 
void xuatMangA(float a[], int n);
float TongA(float a[], int n);
float TBViTriLe(float a[], int n);
int Demsoduong(float a[], int n);
void TangdanA(float a[], int n);
void GiatrileA(float a[], int n);
void VitrizeroA(float a[], int n);
int main()
{
    float a[SIZE] = {1, -3, 4, -2, 5, 0};
    int n,kq1,kq2,kq3;

    do 
    {
        printf("\nNhap vao so phan tu: ");
        scanf("%d", &n);

        if (n <= 0 || n > SIZE)
        {
            printf("So phan tu khong hop le vui long nhap lai! "); 
        }
    } while (n <= 0 || n > SIZE);

    //goihamcau a
    nhapMangA(a, n);
  
    //goihamcau b
    printf("\nMang A vua nhap ");
    xuatMangA(a, n);

	//goihamcau c
	kq1 = TongA(a, n);
	printf("\nTong cac gia tri trong mang la: %d", kq1);

	//goi ham cau d
    kq2 = TBViTriLe(a, n); 
    printf("\nTrung binh cong tai vi tri le la: %d", kq2);
   
    //goi ham cau e 
    kq3 = Demsoduong(a,n);
    printf("\n Cac so duong trong mang la: %d ",kq3);
   
    //goi ham cau f 
    TangdanA(a,n);
    printf("\nThu tu tang dan cua mang ");
    xuatMangA(a, n);
   
    //goi ham cau g
    GiatrileA(a,n);

	//goi ham cau h 
	VitrizeroA(a,n);

}


void nhapMangA(float a[], int n)
{
    for (int i = 0; i < n; i++)
    {   
        printf("Vui long nhap gia tri cua phan tu A[%d]: ", i);
        scanf("%f", &a[i]);
    }
}


void xuatMangA(float a[], int n)
{
    printf("gom cac phan tu: "); 
    for (int i = 0; i < n; i++)
    {
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
float TBViTriLe(float a[], int n) {
    float tong = 0;
    int dem = 0;
    for (int i = 1; i < n; i += 2) {  
        tong += a[i];
        dem++;
    }
    return tong; 
}
int Demsoduong(float a[], int n) {
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
    printf("Vi tri co gia tri 0: ");
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

