#include "persion_info.h"
void person_info::set_ten(string _ten)
{
	ten =_ten;
}
void person_info::set_tuoi(int _tuoi)
{
	tuoi = _tuoi;
}
void person_info::set_gioitinh(gioi_tinh_e _gioitinh)
{
	gioitinh = _gioitinh;
}
void person_info::ThongTinCaNhan(string _ten, int _tuoi, gioi_tinh_e _goi_tinh)
{
	ten = _ten;
	tuoi = _tuoi;
	gioitinh = _goi_tinh;
}
void person_info::ThongTinCaNhan() {
	ten = nullptr;
	tuoi = 0;
	gioitinh = NAM;
};