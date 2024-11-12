#include <stdio.h>   
   char maso[20]; 
   char hoten [100]; 
   char lop[20];
   int ngay,thang,nam; 
   float diemxettuyen[20];

int main(){ 
  
  printf("\n Nhap msvv:"); 
  fgets(maso , sizeof(maso),stdin); 
  printf("nhap lop: "); 
  fgets(lop, sizeof(lop),stdin);
  printf("\n ho ten: ");
  fgets(hoten, sizeof(hoten), stdin);
  printf("nhap nam sinh: ") ;
  scanf("%d %d %d",&ngay,&thang,&nam);
  printf("nhap diem xet tuyen: "); 
  scanf("%f", &diemxettuyen);  
  
   printf("\nThong tin sinh vien:"); 
   printf("\nma so sinh vien: %s", maso);
   printf("Lop: %s\n",lop); 
   printf("Ho ten: %s\n",hoten);
   printf("Ngay sinh: %02d/%02d/%04d\n",ngay,thang,nam);
   printf("Diem xet tuyen:%.2f\n", diemxettuyen); 
   return 0;
   
 
}

