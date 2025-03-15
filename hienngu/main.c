#include<stdio.h>
#include "toan.h"

void main()
{
	int x, y;
	printf("Nhap 2 so nguyen x va y: ");
	scanf_s("%d %d", &x, &y);
	printf("Cong %d\r\n", cong(x,y));
	printf("Tru %d\r\n", tru(x, y));\
	printf("Nhan %d\r\n", nhan(x, y));
	printf("Chia %0.3f\r\n", chia(x, y));
}