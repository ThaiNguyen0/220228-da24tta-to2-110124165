#include <stdio.h> 
int main(){ 
	int n, nhan =1 ; 
	printf("nhap gia tri n(n>=1): ");
	scanf("%d",&n);
	if(n<=0){ 
		printf("Nhap sai gia tri vui long nhap lai! " ); 
		return 1; 
	} 
	for(int i= 1; i<= n;i++){ 
		nhan *=i; 	
	}
	printf("Tich 1*2*3*...* %d = %d\n", n ,nhan);
	return 0 ; 
}
