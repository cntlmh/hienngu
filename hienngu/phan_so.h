#pragma once
class phan_so
{
public:
	// đặc điểm -biến -thuộc tính
	int tu;
	int mau;
	// hành vi - hàm - phương thức:
	phan_so operator*(phan_so khac);
	phan_so operator/(phan_so khac);
	phan_so operator+(phan_so khac);
	phan_so operator-(phan_so khac);
	phan_so rut_gon();
	bool operator>(phan_so khac);
	bool operator<(phan_so khac);
	bool operator>=(phan_so khac);
	bool operator<=(phan_so khac);
	bool operator=(phan_so khac);

};

