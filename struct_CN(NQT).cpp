#include<string.h>
#include<stdio.h>
struct CON_NGUOI{
	char hoten[30], diachi[100], gioitinh[4];
	int tuoi;
	float thunhap;
};
typedef struct CON_NGUOI CN;

void nhap(CN *a);
void xuat(CN a);
char diachi(char a);
int main()
{
	CON_NGUOI a, b;
	
	nhap(&a);
	
	printf("\nThong tin vua nhap la: \n");
	xuat(a);
	
	return 0;
}
void xuat(CN a)
{
	printf("Ho ten:%s\t Tuoi:%d\n", a.hoten, a.tuoi);
	printf("Dia chi:%s",a.diachi);
	printf("\nThu nhap: %f", a.thunhap);
}
void nhap(CN *a)
{
	//Nhap thanh phan ho ten
	printf("\nNhap vao ho ten: ");
	fflush(stdin);
	gets(a->hoten);
	//Nhap thanh phan dia chi
	printf("\nNhap dia chi cua ban: ");
	gets(a->diachi);
	//Nhap thanh phan gioi tinh
	printf("\nHay cho biet gio tinh : ");
	gets(a->gioitinh);
	//Nhap thanh phan tuoi
	printf("\nHay cho biet tuoi: ");
	scanf("%d",&a->tuoi);
	
	//Nhap thanh phan thu nhap
	printf("\nNhap thu nhap: ");
	scanf("%f", &a->thunhap);
}
