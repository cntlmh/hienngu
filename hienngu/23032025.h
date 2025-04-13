#pragma once
typedef struct pin_ptr
{
	int tu;
	int mau;
} phan_so_t;

typedef struct hoc_sinh_t
{
	char ten[50];
	int tuoi;
	float diem_toan;
	float diem_van;
	float trung_binh;
	char xep_loai[11];
} st_hoc_sinh;
//-------------------------------------------- Bai Tap --------------------------------------------
phan_so_t nhan_hai_phan_so(phan_so_t a, phan_so_t b);
phan_so_t chia_hai_phan_so(phan_so_t a, phan_so_t b);
phan_so_t cong_hai_phan_so(phan_so_t a, phan_so_t b);
phan_so_t tru_hai_phan_so(phan_so_t a, phan_so_t b);
phan_so_t rut_gon_phan_so(phan_so_t a);
void nhap_hoc_sinh(st_hoc_sinh* danh_sach_hoc_sinh, int* so_luong_nhap);
void in_danh_sach_hoc_sinh(st_hoc_sinh* danh_sach_hoc_sinh, int so_hoc_sinh);
void in_hoc_sinh_co_diem_tb_cao_nhat(st_hoc_sinh* danh_sach_hoc_sinh, int so_hoc_sinh);
//-------------------------------------------- Bai Hoc --------------------------------------------
int fan_status(char* p_data);
int TrangThaiFan(char* data);