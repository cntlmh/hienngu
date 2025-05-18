#include "phan_so.h"
#include <math.h>
phan_so phan_so::operator*(phan_so khac)
{
	phan_so ketqua;
	ketqua.tu = khac.tu * tu;
	ketqua.mau = khac.mau * mau;
	return ketqua;
}

phan_so phan_so::operator/(phan_so khac)
{
	phan_so ketqua;
	ketqua.tu = tu*khac.mau;
	ketqua.mau = mau*khac.tu;
	return ketqua;
}
phan_so phan_so::operator+(phan_so khac)
{
	phan_so ketqua;
	ketqua.tu = tu * khac.mau + mau * khac.tu;
	ketqua.mau = mau * khac.mau;
	return ketqua;
}
phan_so phan_so::operator-(phan_so khac)
{
	phan_so ketqua;
	ketqua.tu = tu * khac.mau - mau * khac.tu;
	ketqua.mau = mau * khac.mau;
	return ketqua;
}
phan_so phan_so::rut_gon()
{
	phan_so ketqua;
	int min = tu < mau ? tu : mau;
	int ucln = 1;
	for (int i = 1; i <= (int)(sqrt(min) + 1); i++)
	{
		if ((tu % i == 0) && (mau % (tu / i) == 0))
		{
			ucln = tu / i;
			break;
		}
	}
	ketqua.tu = tu / ucln;
	ketqua.mau = mau / ucln;
	return ketqua;
}
bool phan_so::operator>(phan_so khac)
{
	return (tu * khac.mau > mau * khac.tu)?true:false;
}
bool phan_so::operator<(phan_so khac)
{
	return (tu * khac.mau < mau * khac.tu) ? true : false;
}
bool phan_so::operator>=(phan_so khac)
{
	return (tu * khac.mau >= mau * khac.tu) ? true : false;
}
bool phan_so::operator<=(phan_so khac)
{
	return (tu * khac.mau <= mau * khac.tu) ? true : false;
}
bool phan_so::operator=(phan_so khac)
{
	return (tu * khac.mau == mau * khac.tu) ? true : false;
}