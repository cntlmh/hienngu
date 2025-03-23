#include<stdio.h>
#include "toan.h"
#include "chuoi.h"
#define MAX_SIZE 100

void main()
{
	char str[] = "What do you want to do in the new morning?";
	int count = dem_chuoi_ky_tu(str);
	printf("B1. So ky tu trong chuoi \"%s\" la: % d\r\n", str, count);
	printf("B2. So luong space trong trong chuoi sau la: % d\r\n\"%s\"\r\n", dem_space_chuoi_ky_tu(str), str);

	char str_bai_3[] = "Xin Chao moi nguoi ^ %$";
	all_to_upper_case(str_bai_3);
	printf("B3. Chuoi da cho chuyen qua chu viet hoa la: %s\r\n", str_bai_3);

	char str_bai_4[] = "     this is     a    string    ";
	printf("B4. So luong word trong trong chuoi sau la: % d\r\n\"%s\"\r\n", count_word(str_bai_4), str_bai_4);

	char str_bai_5[] = "nguyen van a";
	capitalize_each_word(str_bai_5);
	printf("B5. Chuoi sau khi viet hoa chu cai dau cua moi tu la: %s\r\n", str_bai_5);


#define MAX_SIZE  100
	char str_bai_6[] = "Chu chin noi chu Trung ve con cho cua chu ay?";
	char* p_ky_tu_c[MAX_SIZE];
	int count_c=0;
	find_character(str_bai_6,'c', p_ky_tu_c, &count_c);
	if (0 == count_c)
	{
		printf("khong tim thay ky tu c trong chuoi\r\n");
	}
	else
	{
		printf("Tim thay %d ky tu c trong chuoi\r\n", count_c);
		for (int i = 0; i < count_c; i++)
		{
			printf("Vi tri cua ky tu c thu %d la: %p\r\n", i, p_ky_tu_c[i]);
		}
	}

	char* posistion = find_sub_string(str_bai_6, "Trung");
	printf("B7. Vi tri bat dau cua chuoi con trong chuoi la: %p\r\n", posistion);
}