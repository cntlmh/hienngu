#include <stdint.h>

void dem_so_ky_tu(char str[])
{
	int pos = 0;
	while (str[pos] != 0)
	{
		pos++;
	}
	printf("Co %d ky tu trong chuoi %s\r\n", pos + 1, str);
}

void in_chu_viet_hoa(char str[])
{
	int pos = 0;
	printf("In chu hoa only trong chuoi: %s\r\n",str);
	while (str[pos] != 0)
	{
		
		if ((str[pos] >= 65) && (str[pos] <= 90))
		{
			printf("%c",str[pos]);
		}
		pos++;
	}
	printf("\r\n");
}