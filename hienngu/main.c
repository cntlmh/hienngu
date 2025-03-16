#include<stdio.h>
#include "toan.h"

void main()
{
	//int x, y;
	//printf("Nhap 2 so nguyen x va y: ");
	//scanf_s("%d %d", &x, &y);
	//printf("Cong %d\r\n", cong(x,y));
	//printf("Tru %d\r\n", tru(x, y));\
	//printf("Nhan %d\r\n", nhan(x, y));
	//printf("Chia %0.3f\r\n", chia(x, y));
	//int a[] = { 1, 2, 3, 4, 5 };
	//printf("sum: %d\r\n", sum_array(a, 5));
	//printf("sum array odd number: %d\r\n", sum_array_odd(a, 5));
	int b[] = { 1, 2, 3, 4, 5, 6, 7, 13,17,987};
	//
	//array_negative_replace(b, 5) ;
	//for (int i = 0; i < 5; i++)
	//{
	//	printf("%d ", b[i]);
	//}
	//array_print_odd_number(b, 5);
	//printf("\r\ngia tri le trong mang la: ");
	array_prime_number(b, 10);
	printf("Before change: a = %d, b = %d\r\n", b[0], b[1]);
	hoan_vi_hai_so_nguyen(&b[0], &b[1]);
	printf("After change: a = %d, b = %d", b[0], b[1]);
}