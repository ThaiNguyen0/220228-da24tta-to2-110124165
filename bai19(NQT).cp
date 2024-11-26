#define SIZE 100
#include <stdio.h>
void nhapMang(int a[], int n);
void xuatMang(int a[], int n);
int tongMang(int a[], int n); 
int tongduong(int a[], int n);
int tongLe(int a[], int n);
int phanAm(int a[], int n);
int phanLe(int a[], int n);
int songuyento(int a[],int n);
}
int main()
{
	int A[] = {1,-3,4,-2,5,0};
	int n = sizeof(A)/ sizeof(A[0]) , kq,kq1,kq2,kq3,kq4,kq5;
	
	do
	{
		printf("\nNhap vao so phan tu: ");
		scanf("%d", &n);
	}while(n<=0||n>100); 
	int isPrime(int n)
	{
		if(n < 2)
		return 0;
		for(int i = 2; i <= sqrt(n); i++ )
		{
			if(n % i == 0)
			return 0;
		}
		return 1;
	}
	
	//n hop le
	//goi ham cau a
	nhapMang(A,n);
	
	//Goi ham cau b
	printf("\nMang vua nhap la: ");
	xuatMang(A,n);
	
	//Goi ham cau c
	kq = tongMang(A,n);
	printf("\nTong cac gia tri trong mang la: %d", kq);
	

	//Goi ham cau d 
	kq1 = tongduong(A,n);
	printf("\nTong phan duong trong mang la: %d", kq1); 
	
	//Goi ham cau e 
	kq2 = tongLe(A,n); 
	printf("\nTong vi tri le trong mang la:%d", kq2); 
	
	//Goi ham cau f
	kq3 = phanAm(A,n);
	printf("\nSo phan tu am trong mang nay la:%d",kq3);
	
	//Goi ham cau g
	kq4 = phanLe(A,n);
	printf("\nSo phan tu le trong mang nay la:%d", kq4);
	

	//Goi ham cau h 
	kq5 = songuyento(A,n); 
	prinf("\nSo phan tu la so nguyen to trong mang nay la:%d",kq5);
	return 0;
}
int tongMang(int a[], int n)
{
	int tong = 0;
	int i=0;
	do
	{
		tong = tong + a[i];
		i++;
	}while(i<=n-1);
	return tong;
}

void xuatMang(int a[], int n)
{
	int i;
	for(i=0; i<=n-1; i++)
	{
		printf("%8d", a[i]);
	}
}
void nhapMang(int a[], int n)
{
	int i;
	
	i = 0;
	while(i<=n-1)
	{
		printf("\nNhap gia tri tai vi tri %d: ", i);
		scanf("%d", &a[i]); //a+i
		i++;
	}
} 
int tongduong(int a[], int n)
{ 
	int tong = 0;
	int i = 0; 
	for (int i = 0;i < n;i++) 
	{ 
		if (a[i] > 0)
		{ 
			tong += a[i]; 
		}
	}
	
} 
int tongLe(int a[], int n)
{
	int tong = 0; 
	int i = 0; 
	for(int i = 1; i < n; i+= 2)
	{ 
		tong+=a[i]; 
	} 
	return tong;
}
int phanAm(int a[], int n)
{
	int dem = 0 ;
	for(int i = 0 ; i < n; i++)
	{
	if (a[i] < 0){
		dem++;
	}	
		}
	return dem;
}
int phanLe(int a[], int n )
{ 
	int dem = 0 ; 
	for(int i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0)
		{
		 dem++;
		}
	}
	return dem;		
} 
int songuyento(int a[],int n)
{
	int dem = 0
	for (int i = 0;i < n; i++)
	{
	if (isPrime(a[i])){
		dem++;
	}
	}
	return dem;
}



