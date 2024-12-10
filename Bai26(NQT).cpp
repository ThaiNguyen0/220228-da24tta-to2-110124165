#include <stdio.h>
#include <string.h>

typedef struct
{
	char Masach[20];
	char Tensach[120];
	char Tacgia[60];
	char NXB[60];
	int NamXuatBan;
	float DonGia;
	int SoLuong;
	float ThanhTien;
	float Thue;
	float ThucTien;	
};


void nhapTTSach(SACH books[], int *n);
void inTTSach(SACH books[], int n);
void TThanhTien(SACH books[], int n);
void TThucTien(SACH books[], int n);
void SapxepSachTheonam(SACH books[], int n);
void ThucTienMax(SACH books[], int n);
void tinhTongSoLuong(SACH books[], int n);

int main() {
    SACH books[100];
    int n = 0;
    nhapTTSach(books, &n);
    TThanhTien(books, n);
    TThucTien(books, n);
    SapxepSachTheoNam(books, n);
    printf("\nDanh sach sach sau khi nhap la:\n");
    inTTSach(books, n);
    printf("\nSach co thuc tien lon nhat:\n");
    ThucTienMax(books, n);
    printf("\nTang so luong sach:\n");
    tinhTongSoLuong(books, n);
    return 0;
}

		

