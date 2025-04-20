﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

float fx(float x)
{
	return x * x;
}

float gx(float x)
{
	return 2 * x * x + x + 1;
}

float tx(float x)
{
	return 2 * sin(x) + 1;
}

float tinhTichPhan(float a, float b, float (*fp) (float))
{
	float S = 0;
	float h = (b - a) / 1000;
	for (int i = 0; i < 1000; i++)
	{
		float db = fp(a + h * i);
		float dl = fp(a + (i + 1) * h);
		S += ((dl + db) / 2) * h;
	}
	return S;
}

typedef float (*ham_t)(int, char);

float function(int x, char y)
{
	printf("Ham function da duoc chay (x = %d) ...\n", x);
}


void function_1()
{
	printf("Day la function_1 \n");
}


void main()
{
	
}