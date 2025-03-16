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