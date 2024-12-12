#include <stdio.h>

main()
{
	/*KHai bao bien*/
	int a [3] [3]={{1,2,3},{4,5,6},{7,8,9}};
	int m=3, i , j;
	FILE *fp; 
	char path[50];
	
	/*Nhap duong dan tap tin can ghi du lieu*/
	printf("\nNhap duong dan: ");
	fflush(stdin);
	gets(path);
	
	/*Mo tap tin de ghi du lieu*/
	fp=fopen (path,"wt");
	/*Kiem tra co mo duoc tap tin hay khong*/
if(fp==NULL)
{
	printf("\nLoi mo file"); 

}
else
	/*Ghi so dong*/
	fprintf(fp,"%d\n",m);
	/*Ghi tung dong du lieu*/
for(i=0; i<m; i++)
	{
		for(j=0; j<m; j++)
		{
			fprintf(fp,"%3d",a[i] [j]);
		}
	/*Ghi ky tu ngat dong*/
	fprintf(fp,"\n");
	}
	/*Dong tap tin*/
	fclose(fp);
	}


