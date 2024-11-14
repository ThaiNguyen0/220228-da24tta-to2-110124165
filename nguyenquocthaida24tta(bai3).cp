#include <stdio.h> 
#define PI 3.1415 
int main(){ 
	float a = 50.0 ; 
	float b = 23.0 ;
	float c = 30.0 ; 
	float d = 12.56 ; 
	float dthinhthang = (a + b) * c / 2 ; 
	float dthinhtron =(d * d) / (4 * PI); 
	float dtconlai = dthinhthang - dthinhtron; 
	printf("dien tich hinh thang: %.2f m^2\n",dthinhthang);
	printf("dien tich hinh tron: %.2f m^2\n",dthinhtron); 
	printf("dien tich con lai cua san truong: %.2f m^2\n",dtconlai);	
	return 0;	
}
