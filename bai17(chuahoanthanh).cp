#include <stdio.h> 
#include <stdbool.h>
bool isPrime(int n){ 
	if (n < 2)
	return 0; 
	for (int i = 2;i * i <= n; i++){ 
		return 0;
	}
}
 
void bai17a(){ 
	int n;
	printf("nhap mot so nguyen n(n<100):"); 
	scanf("%d ", &n); 
	if (n>=100){ 
		printf("nhap gia tri sai vui long nhap lai(n<100)");
	} else {
	
		for (int i = 1;  i <= n ; i++){ 
		printf("%d ",i); 
	}
	printf("\n");
}

}
/////////////////////////////////////////////////////////////
 
void bai17b(){
 	int n;
	printf("nhap mot so nguyen n(n<100):"); 
	scanf("%d ", &n); 
	if (n>=100){ 
		printf("nhap gia tri sai vui long nhap lai(n<100)");
	} else {
	
		for (int i = 0;  i <= n ; i=i+2){ 
		printf("%d",i); 
	}
	printf("\n");
}
	}
////////////////////////////////////////////////////////////

void bai17c(){
	int n;
	printf("nhap mot so nguyen n(n<100):"); 
	scanf("%d ", &n); 
	if (n>=100){ 
		printf("nhap gia tri sai vui long nhap lai(n<100)");
	} else {
	
		for (int i = 0;  i <= n ; i=i+5){ 
		printf("%d ",i); 
	}
	printf("\n");
}
	}
////////////////////////////////////////////////////////////
	
void bai17d(){ 
	int n;
	printf("nhap so nguyen duong n(n<100): "); 
	scanf("%d ",n); 
	if(n<2){ 
		printf("nhap sai gia tri vui long nhap lai!"); 
	}else{ 
	for (int i = 2; i< n; i++){ 
	if (isPrime(1)){ 
		printf("%d ",i);
		}
	printf("\n");
	}
		}
	} 




int main(){ 
 bai17a();
 bai17b();
 bai17c(); 
 bai17d();
}

	
	
	
	










 
	
	
