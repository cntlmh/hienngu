#include<stdio.h>
#include "toan.h"
#include "chuoi.h"
#include "23032025.h"



void main()
{
	phan_so_t a = { 6,8 };
	phan_so_t b = { .tu = 1, .mau = 2};
	phan_so_t kq = nhan_hai_phan_so(a, b);
	printf("ket qua nhan hai phan so la: %d/%d\r\n", kq.tu, kq.mau);
	kq = chia_hai_phan_so(a, b);
	printf("ket qua chia hai phan so la: %d/%d\r\n", kq.tu, kq.mau);
	kq = cong_hai_phan_so(a, b);
	printf("ket qua cong hai phan so la: %d/%d\r\n", kq.tu, kq.mau);
	kq = tru_hai_phan_so(a, b);
	printf("ket qua tru hai phan so la: %d/%d\r\n", kq.tu, kq.mau);
	kq = rut_gon_phan_so(a);
	printf("ket qua rut gon hai phan so la: %d/%d\r\n", kq.tu, kq.mau);
	st_hoc_sinh danh_sach_hoc_sinh[100];
	int so_luong_nhap = 0;
	nhap_hoc_sinh(danh_sach_hoc_sinh, &so_luong_nhap);
	in_danh_sach_hoc_sinh(danh_sach_hoc_sinh, so_luong_nhap);
	in_hoc_sinh_co_diem_tb_cao_nhat(danh_sach_hoc_sinh, so_luong_nhap);
}