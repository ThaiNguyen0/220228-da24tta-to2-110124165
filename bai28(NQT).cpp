#include <stdio.h>

int main() {
    int n, i;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &arr[i]);
    }

    char filename[110];
    printf("Nhap ten tep de luu: ");
    scanf("%s", filename);

    FILE *fptr;
    fptr = fopen(filename, "w");
    if (fptr == NULL) 
	{
        printf("Loi mo tep!\n");
        return 1;
    }

    fprintf(fptr, "%d\n", n);
    for (i = 0; i < n; i++) 
	{
        fprintf(fptr, "%d  ", arr[i]);
    }

    fclose(fptr);
    printf("Ghi du lieu vao tep thanh cong!\n");

    return 0;
}
