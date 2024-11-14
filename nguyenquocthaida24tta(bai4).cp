#include <stdio.h> 
 
 int main(){ 
 	int a;
 	float b; 
	float c; 
	float d; 
	printf("nhap so luong hang:");
	scanf("%d",&a); 
	printf("nhap don gia cua hang:"); 
	scanf("%f",&b);
	printf("nhap chi phi van chuyen:"); 
	scanf("%f",&c); 
	d = a * b - c ; 
	printf("doanh thu cua cong ty A trong ngay la: %.2f\n",d);
	return 0;
 }
