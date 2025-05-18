#include <stdio.h>
#include "phan_so.h"

int main()
{
	phan_so A;
	A.tu = 1;
	A.mau = 3;
	phan_so B;
	B.tu = 3;
	B.mau = 8;
	phan_so C = A * B;
	phan_so F = A / B;
	phan_so D = A + B;
	phan_so E = A - B;
	bool lon_hon = A > B;
	bool nho_hon = A < B;
	bool lon_bang = A >= B;
	bool nho_bang = A <= B;
	bool bang = (A = B);
	phan_so rut_gon_C = C.rut_gon();
	return 0;
}