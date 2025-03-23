#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
// Bài 1: Xây dụng hàm. dùng để điếm số ký tự trong chuỗi
/*
Chưc năng: Dùng để điếm số ký tự trong chuỗi
Input: chuỗi ký tự
Ouput: số ký tự trong chuỗi
*/
int dem_chuoi_ky_tu(char* p_chuoi_ky_tu)
{
	int count = 0;
	//while (0 != p_chuoi_ky_tu[count])
	while (0 != *p_chuoi_ky_tu)
	{
		p_chuoi_ky_tu++;
		count++;
	}
	return count;
}

// Bài 2: Xây dựng hàm. dùng để điếm có bao nhiêu ký tự space (dấu cách) trong chuỗi
/*
Chưc năng: Dùng để điếm có bao nhiêu ký tự space (dấu cách) trong chuỗi
Input: chuỗi ký tự
Ouput: so ky tu space trong chuoi
*/
int dem_space_chuoi_ky_tu(char* p_chuoi_ky_tu)
{
	int count = 0;
	while (0 != *p_chuoi_ky_tu)
	{
		//if (32 == *p_chuoi_ky_tu)
		if (' ' == *p_chuoi_ky_tu)
		{
			count++;
		}
		p_chuoi_ky_tu++;
	}
	return count;
}

//Bài 3: Xây dụng hàm, dùng để chuyễn chữ thường thành chư IN HOA
/*
Chưc năng: Dùng để chuyễn chữ thường thành chư IN HOA
Input: chuỗi ký tự bất kỳ
Ouput: trả về chuỗi viết hoa
*/
void all_to_upper_case(char* p_chuoi_ky_tu)
{
	while (0!=*p_chuoi_ky_tu)
	{

		if ((*p_chuoi_ky_tu >= 97) && (*p_chuoi_ky_tu <= 122))
		{
			*p_chuoi_ky_tu = *p_chuoi_ky_tu - 32;
		}
		p_chuoi_ky_tu++;
	}
}

//Bài 4: Xây dựng hàm. dùng để điếm số từ (word) trong chuỗi
/*
Chưc năng: Dùng để điếm số từ (word) trong chuỗi
Input: chuỗi ký tự bất kỳ
Ouput: số từ (word) trong chuỗi
*/
int count_word(char* p_chuoi_ky_tu)
{
	int count = 0;
	while (0 != *p_chuoi_ky_tu)
	{

		if (((' ' != *p_chuoi_ky_tu) && (' ' == *(p_chuoi_ky_tu + 1))) ||\
			((' ' != *p_chuoi_ky_tu) && (0 == *(p_chuoi_ky_tu + 1))))
		{
			count++;
		}
		p_chuoi_ky_tu++;
	}
	return count;
}

//Bài 5: Xây dụng hàm. dùng để in hoa chữ cái đầu tiên của từ trong chuỗi str
/*
Chưc năng: Dùng để in hoa chữ cái đầu tiên của từ trong chuỗi str
Input: chuỗi ký tự bất kỳ
Ouput: viết hoa ký tự đầu tiên của từ trong chuỗi
*/
void capitalize_each_word(char* p_chuoi_ky_tu)
{
	int pos = 0;
	bool condition;
	while (0 != p_chuoi_ky_tu[pos])
	{
		condition = (p_chuoi_ky_tu[pos] >= 97) && (p_chuoi_ky_tu[pos] <= 122);
		if((0==pos) && condition)
		{
			p_chuoi_ky_tu[pos] = p_chuoi_ky_tu[pos] - 32;
		}
		else if (((' ' == p_chuoi_ky_tu[pos - 1]) && condition))
		{
			p_chuoi_ky_tu[pos] = p_chuoi_ky_tu[pos] - 32;
		}
		pos++;
	}
}

//Bài 6: Xây dựng hàm. dùng để tìm ký tự c trong chuỗi str. hàm trả về địa chỉ của ký tự c trong chuỗi str
/*
Chưc năng: Dùng để tìm ký tự c trong chuỗi str. hàm trả về địa chỉ của ký tự c trong chuỗi str
Input: chuỗi ký tự bất kỳ
Ouput: list of địa chỉ của ký tự ky_tu trong chuỗi
*/
void find_character(char * p_chuoi_ky_tu, char ky_tu, char ** p_ky_tu_c, int *count)
{
	*count = 0;
	while (0 != *p_chuoi_ky_tu)
	{
		if (ky_tu == *p_chuoi_ky_tu)
		{
			p_ky_tu_c[*count] = p_chuoi_ky_tu;
			(*count)++;
		}
		p_chuoi_ky_tu++;
	}
}

//bài 7: Xây dựng hàm. dùng để tìm chuỗi subStr trong chuỗi str. hàm trả về địa chỉ bất đầu của subStr trong chuỗi str
/*
Chưc năng: Dùng để tìm chuỗi subStr trong chuỗi str. hàm trả về địa chỉ bất đầu của subStr trong chuỗi str
Input: chuỗi ký tự bất kỳ
Ouput: vị trí chuỗi con trong chuỗi
*/
char * find_sub_string(char* p_chuoi_ky_tu, char * p_sub_chuoi)
{
	int so_ky_tu_sub_chuoi = dem_chuoi_ky_tu(p_sub_chuoi);
	int pos = 0;
	int count = 0;
	while (0 != p_chuoi_ky_tu[pos])
	{
		if (p_chuoi_ky_tu[pos] == p_sub_chuoi[count])
		{
			count++;
			if (count == so_ky_tu_sub_chuoi)
			{
				return p_chuoi_ky_tu + pos - so_ky_tu_sub_chuoi + 1;
			}
		}
		else
		{
			count = 0;
		}
		pos++;
	}
	return NULL;
}

