#include <stdio.h> 
int main(){ 
	int n, sum = 0 ; 
	printf("nhap gia tri n(n>0): ");
	scanf("%d",&n);
	if(n<=0){ 
		printf("Nhap sai gia tri vui long nhap lai! " ); 
		return 1; 
	} 
	for(int i= 1; i<= n;i++){ 
		sum +=i; 	
	}
	printf("tong 1+2+3+...+ %d = %d\n", n ,sum);
	return 0 ; 
}


