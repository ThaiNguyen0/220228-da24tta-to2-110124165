#include <stdio.h>
int main(){ 
	int n;
	printf("nhap mot so nguyen n(n<100):"); 
	scanf("%d", &n); 
	if (n>=100){ 
		printf("nhap gia tri sai vui long nhap lai(n<100)");
	} else {
	
		for (int i = 1;  i <= n ; i++){ 
		printf("%d",i); 
	}
	printf("\n");
}
	return 0;
}

	
	
