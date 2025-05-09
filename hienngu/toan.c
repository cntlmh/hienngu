#include<stdio.h>
#include<math.h>
#include <stdbool.h>
/*
Chức năng: Cộng 2 số nguyên
Input:
	int a, int b là 2 số nguyên bất kỳ
Output: Trả về tổng của a và b
*/

int cong(int a, int b) {
	return a+b;
}

/*
Chức năng: Trừ 2 số nguyên
Input:
	int a, int b là 2 số nguyên bất kỳ
Output: Trả về hiệu của a và b
*/
int tru(int a, int b) {
	return a - b;
}

/*
Chức năng: Nhân 2 số nguyên
Input:
	int a, int b là 2 số nguyên bất kỳ
Output: Trả về tích của a và b
*/
int nhan(int a, int b) {
	return a * b;
}

/*
Chuc nang: Chia 2 so nguyen
Input:
	int a, int b la 2 so nguyen bat ky
Output: Tra ve thuong cua a va b
*/
float chia(int a, int b) {
	return (float)a / b;
}



//Bài 1: Xây dựng hàm.tính tổng các giá trị trong mảng arr
/*
Chuc nang: tính tổng các giá trị trong mảng arr
Input:
	int arr[] là mảng số nguyên
	int n là số phần tử của mảng
Output: trả về tổng các giá trị trong mảng
*/
int sum_array(int arr[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = sum + arr[i];
	}
	return sum;
}

//Bai 2: tinh trung binh cong cac so le trong mang
/*
Chuc nang: tính trung bình cộng các số lẻ trong mảng
Input:
	int arr[] là mảng số nguyên
	int n là số phần tử của mảng
Output: trả về trung bình cộng các số lẻ trong mảng
*/
int sum_array_odd(int arr[], int n)
{
	int sum_odd = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 != 0)
		{
			sum_odd = sum_odd + arr[i];
		}
	}
	return sum_odd;
}

//Bai 3: In ra cac vi tri cua so lon nhat trong mang
//Bài 7: Xây dựng hàm.in ra giá trị lớn nhất trong mảng arr
/*
Chuc nang: In ra các vị trí của số lớn nhất trong mảng
Input:
	int a[] là mảng số nguyên
	int n là số phần tử của mảng	
Output: In ra các vị trí, giá trị của số lớn nhất trong mảng và trả về giá trị lớn nhất đó
*/
int array_max_number(int a[], int n) {
	int max = a[0];
	int pos = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
			pos = i;
		}
	}
	printf("Vi tri cua so lon nhat la: %d",pos);
	printf("Gia tri so lon nhat trong mang la: %d", max);
	return max;
}

//Bai 4: Thay the cac so am trong mang bang 0
/*
Chuc nang: Thay thế các số âm trong mảng bằng 0
Input:
	int a[] là mảng số nguyên
	int n là số phần tử của mảng
Output: Mảng sau khi thay thế các số âm bằng 0
*/
void array_negative_replace(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 0)
		{
			arr[i] = 0;
		}
	}
}

//Bài 5: Xây dụng hàm. in ra các giá trị LẼ trong mảng arr
/*
Chuc nang: In ra các giá trị lẻ trong mảng
Input:
	int arr[] là mảng số nguyên
	int n là số phần tử của mảng
Output: In ra các giá trị lẻ trong mảng
*/
void array_print_odd_number(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 != 0)
		{
			printf("%d ", arr[i]);
		}
	}

}

// Bài 6: Xây dụng hàm. in ra các giá trị là số nguyên tố trong mảng arr
/*
Chuc nang: in ra các giá trị là số nguyên tố trong mảng arr
Input:
	int arr[] là mảng số nguyên
	int n là số phần tử của mảng
Output: In ra các giá trị là số nguyên tố trong mảng
*/
void array_prime_number(int arr[], int n)
{
	bool snt = true;
	for (int i = 0; i < n; i++)
	{
		int can_bac_hai = (int)sqrt(arr[i]);
		for (int j = 2; j <=can_bac_hai; j++)
		{
			if (arr[i] % j == 0)
			{
				snt = false;
				break;
			}
		}
		if (true == snt)
		{
			printf("arr[%d] = %d la mot so nguyen to\r\n", i, arr[i]);
		}
		else
		{
			snt = true;
		}
	}
}

//Bai 8: Viet Ham Hoan Vi 2 so nguyen
/*
Chuc nang: Hoán vị 2 số nguyên
Input:
	int a, int b là 2 số nguyên bất kỳ
Output: Trả về giá trị của a và b sau khi hoán vị
*/
void hoan_vi_hai_so_nguyen(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// Bài 9: Xây dựng hàm. Sắp xếp mảng arr theo giá trị tăng dần
/*
Chuc nang: Sắp xếp mảng arr theo giá trị tăng dần
Input:
	int arr[] là mảng số nguyên
	int n là số phần tử của mảng	
Output: Mảng sau khi sắp xếp theo giá trị tăng dần
*/
