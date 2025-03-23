#include<stdio.h>
#include "toan.h"
#include "chuoi.h"
#include "23032025.h"
#define MAX_SIZE 100

void main()
{
	printf("Checking fan status\r\n");
	char data[] = "HTTP1.1 200 OK{"\
		"\"light\": \"on\","\
		"\"fan\" : \"off\","\
		"\"motor\" : \"off\"}";
	int status = fan_status(data);
	printf("Fan status: %d\r\n", status);
	int status1 = TrangThaiFan(data);
	printf("Fan status1: %d\r\n", status1);
	system("pause");
}