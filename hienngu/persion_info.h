#pragma once
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;
enum gioi_tinh_e
{
	NAM,
	NU
};
class person_info
{
	string ten;
	int tuoi;
	gioi_tinh_e gioitinh;
public:
	void set_ten(string _ten);
	void set_tuoi(int _tuoi);
	void set_gioitinh(gioi_tinh_e _gioitinh);
	void ThongTinCaNhan();
	void ThongTinCaNhan(string _ten, int _tuoi, gioi_tinh_e _goi_tinh);

};

