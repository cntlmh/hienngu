#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "23032025.h"
#include "math.h"
//-------------------------------------------- Bai Tap --------------------------------------------
// file struct.txt
phan_so_t nhan_hai_phan_so(phan_so_t a, phan_so_t b)
{
	phan_so_t kq;
	kq.tu = a.tu * b.tu;
	kq.mau = a.mau * b.mau;
	return rut_gon_phan_so(kq);
}
phan_so_t chia_hai_phan_so(phan_so_t a, phan_so_t b)
{
	phan_so_t kq;
	kq.tu = a.tu * b.mau;
	kq.mau = a.mau * b.tu;
	return rut_gon_phan_so(kq);
}
phan_so_t cong_hai_phan_so(phan_so_t a, phan_so_t b)
{
	phan_so_t kq;
	kq.tu = a.tu * b.mau + b.tu* a.mau;
	kq.mau = a.mau * b.mau;
	return rut_gon_phan_so(kq);
}
phan_so_t tru_hai_phan_so(phan_so_t a, phan_so_t b)
{
	phan_so_t kq;
	kq.tu = a.tu * b.mau - b.tu * a.mau;
	kq.mau = a.mau * b.mau;
	return rut_gon_phan_so(kq);
}
phan_so_t rut_gon_phan_so(phan_so_t a)
{
	phan_so_t kq;
	int min = a.tu < a.mau ? a.tu : a.mau;
	int ucln = 1;
	for (int i = 1; i <= (int) (sqrt(min)+1); i++)
	{
		if ((a.tu % i == 0) && (a.mau % (a.tu / i) == 0))
		{
			ucln = a.tu / i;
			break;
		}
	}
	kq.tu = a.tu/ucln;
	kq.mau = a.mau/ucln;
	return kq;
}
	
void nhap_hoc_sinh(st_hoc_sinh * danh_sach_hoc_sinh, int * so_luong_nhap)
{
	*so_luong_nhap = 0;
	printf("Nhap so luong hoc sinh ban muon nhap: \r\n");
	scanf_s("%d", so_luong_nhap);
	printf("Vui long nhap thong tin cua %d hoc sinh: \r\n", *so_luong_nhap);
	for (int i = 0; i < *so_luong_nhap; i++)
	{
		printf("Nhap ten hoc sinh thu %d: \r\n",i+1);
		while (getchar() != '\n');
		fgets(danh_sach_hoc_sinh->ten, sizeof(danh_sach_hoc_sinh->ten), stdin);
		//scanf("%[^\n]", danh_sach_hoc_sinh->ten);
		while (getchar() != '\n');
		printf("Nhap tuoi hoc sinh: \r\n");
		scanf_s("%d", &danh_sach_hoc_sinh->tuoi);
		printf("Nhap diem toan hoc sinh: \r\n");
		scanf_s("%f", &danh_sach_hoc_sinh->diem_toan);
		printf("Nhap diem van hoc sinh: \r\n");
		scanf_s("%f", &danh_sach_hoc_sinh->diem_van);
		danh_sach_hoc_sinh->trung_binh = (danh_sach_hoc_sinh->diem_toan + danh_sach_hoc_sinh->diem_van) / 2;
		if (danh_sach_hoc_sinh->trung_binh >= 8)
		{
			strcpy_s(danh_sach_hoc_sinh->xep_loai,sizeof(danh_sach_hoc_sinh->xep_loai), "Gioi");
		}
		else if (danh_sach_hoc_sinh->trung_binh >= 6.5)
		{
			strcpy_s(danh_sach_hoc_sinh->xep_loai, sizeof(danh_sach_hoc_sinh->xep_loai), "Kha");
		}
		else if (danh_sach_hoc_sinh->trung_binh >= 5)
		{
			strcpy_s(danh_sach_hoc_sinh->xep_loai, sizeof(danh_sach_hoc_sinh->xep_loai), "Trung Binh");
		}
		else
		{
			strcpy_s(danh_sach_hoc_sinh->xep_loai, sizeof(danh_sach_hoc_sinh->xep_loai), "Yeu");
		}
		danh_sach_hoc_sinh++;
	}
}
void in_danh_sach_hoc_sinh(st_hoc_sinh* danh_sach_hoc_sinh, int so_hoc_sinh)
{
	printf("Danh sach hoc sinh: \r\n");
	for (int i = 0; i < so_hoc_sinh; i++)
	{
		printf("Hoc sinh thu %d:\r\n", i + 1);
		printf("\tTen: %s\r\n", danh_sach_hoc_sinh->ten);
		printf("\tTuoi: %d\r\n", danh_sach_hoc_sinh->tuoi);
		printf("\tDiem toan: %.2f\r\n", danh_sach_hoc_sinh->diem_toan);
		printf("\tDiem van: %.2f\r\n", danh_sach_hoc_sinh->diem_van);
		printf("\tDiem trung binh: %.2f\r\n", danh_sach_hoc_sinh->trung_binh);
		printf("\tXep loai: %s\r\n", danh_sach_hoc_sinh->xep_loai);
	}
}
void in_hoc_sinh_co_diem_tb_cao_nhat(st_hoc_sinh* danh_sach_hoc_sinh, int so_hoc_sinh)
{
	int vi_tri = 0;
	float diem_trb_cao_nhat = danh_sach_hoc_sinh[0].trung_binh;
	for (int i = 0; i < so_hoc_sinh; i++)
	{
		if (danh_sach_hoc_sinh[i].trung_binh > diem_trb_cao_nhat)
		{
			diem_trb_cao_nhat = danh_sach_hoc_sinh[i].trung_binh;
			vi_tri = i;
		}
	}
	printf("Hoc sinh co diem trung binh cao nhat la: %f \r\n", diem_trb_cao_nhat);
	printf("\tTen: %s\r\n", danh_sach_hoc_sinh[vi_tri].ten);
	printf("\tTuoi: %d\r\n", danh_sach_hoc_sinh[vi_tri].tuoi);
	printf("\tDiem toan: %.2f\r\n", danh_sach_hoc_sinh[vi_tri].diem_toan);
	printf("\tDiem van: %.2f\r\n", danh_sach_hoc_sinh[vi_tri].diem_van);
	printf("\tDiem trung binh: %.2f\r\n", danh_sach_hoc_sinh[vi_tri].trung_binh);
	printf("\tXep loai: %s\r\n", danh_sach_hoc_sinh[vi_tri].xep_loai);
}
//-------------------------------------------- Bai Hoc --------------------------------------------
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
	// B1:search tới "fan" : "
	char* pattern = "\"fan\" : \"";
	char* sub_pos = TimChuoi(data, pattern);
	sub_pos = sub_pos + SoLuongKyTu(pattern);
	// B2:lấy dữ liệu bỏ vào fan_state đến khi nào găp " thì ngừng lại
	int dem = 0;
	while ('"' != sub_pos[dem])
	{
		dem++;
	}
	char* fan_state = malloc(dem + 1);
	memset(fan_state,0,dem+1);
	memcpy(fan_state, sub_pos, dem);
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

