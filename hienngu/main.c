#include<stdio.h>
#include "toan.h"
#include "chuoi.h"
#define MAX_SIZE 100

void main()
{
	char str[] = "Xin Chao Mot Ngay Moi Tot Lanh";
	in_chu_viet_hoa(str);
	chuyen_chu_viet_hoa(str);
	system("pause");
}