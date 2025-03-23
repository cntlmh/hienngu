#include <stdio.h>
int fan_status(char *p_data)
{
	int comma = 0;
	while (0 != *p_data)
	{
		if (',' == *p_data)
		{
			comma++;
		}
		if ((1 == comma) && ('o' == *p_data) && ('n' == *(p_data + 1)))
		{
			return 1;
		}
		else if (1 < comma)
		{
			return 0;
		}
		p_data++;
	}
	return 0;
}

int SoLuongKyTu(char* str)
{
	int sl = 0;
	while (str[sl] != 0)
	{
		sl++;
	}
	return sl;
}

// Chức nâng: dùng để tìm ký tự c trong chuỗi str
// Input:
//	char* chuoi - chuổi cần tìm
//	char c - ký tự cần tìm trong chuổi str
// Output: (char*) địa chỉ của ký tự c trong chuổi str
char* TimKyTu(char* chuoi, char ky_tu)
{
	int chieu_dai_chuoi = SoLuongKyTu(chuoi);
	for (int i = 0; i < chieu_dai_chuoi; i++)
	{
		if (chuoi[i] == ky_tu)
			return chuoi + i;
	}
	return 0;
}

// Chức nâng: dùng để tìm chuỗi subStr trong chuỗi str
// Input:
//	char* str - chuỗi cần tìm
//	char* sub_str - chuỗi từ khóa cần tìm
// Output: (char*) địa chỉ của chuổi sub_str trong str
char* TimChuoi(char* str, char* sub_str)
{
	int chieu_dai_str = SoLuongKyTu(str);
	int chieu_dai_sub_str = SoLuongKyTu(sub_str);
	for (int i = 0; i < chieu_dai_str; i++)
	{
		int j = 0;
		for (j = 0; j < chieu_dai_sub_str; j++)
		{
			if (str[i + j] != sub_str[j])
				break;
		}
		if (j == chieu_dai_sub_str)
			return str + i;
	}
	return 0;
}

// Chức nâng: Lấy trang thái của "fan" trong dữ liệu gửi về từ server
// Input: 
//	char* data - chuỗi dữ liệu dducc lấy về từ server
// Output:
//	0: tương ứng trạng thái "off"
//	1: tương ứng trạng thái "on"
int TrangThaiFan(char* data)
{
	// format data: HTTP1.1 200 OK{"light": "on","fan" : "off","motor" : "off"}
	char fan_state[16] = { 0 };
	// B1:search tới "fan" : "
	char* pattern = "\"fan\" : \"";
	char* sub_pos = TimChuoi(data, pattern);
	sub_pos = sub_pos + SoLuongKyTu(pattern);
	// B2:lấy dữ liệu bỏ vào fan_state đến khi nào găp " thì ngừng lại
	int pos = 0;
	while ('"' != *sub_pos)
	{
		fan_state[pos] = *sub_pos;
		pos++;
		sub_pos++;
	}
	// B3:so sánh với "on" hoặc "off" để return kết quả là 1 hay là 0
	char* p_status = "on";
	if (0==TimChuoi(fan_state, p_status))
	{
		return 0;
	}
	else {
		return 1;
	}
}