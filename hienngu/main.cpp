#include <stdio.h>
#include <iostream>
#include <math.h>
/*
    Bài 1:
    Chức năng: Viết hàm printf in ra màn hình 2 số  gồm 8 bit cao và 8 bit thấp của số nguyên 16 bit
    Input: short number
    Output: void
*/

void print_so_nguyen_16bit(unsigned short number)
{
    typedef struct bit_tag
    {
        unsigned char low;
        unsigned char height;
    }bit;

    bit* temp = (bit*)&number;
    printf("So ban vua nhap vao la %d (%X)\n", number, number);
    printf("\t- 8 bit thap: %d (%X)\n", temp->low, temp->low);
    printf("\t- 8 bit cao: %d (%X)\n", temp->height, temp->height);
}

/*
    Bài 2: Xây dựng class giải phương trình bậc 2
*/
using namespace std;
template <typename T1, typename T2, typename T3>
class giai_phuong_trinh
{
public:
    giai_phuong_trinh(T1 a, T2 b, T3 c)
    {
        float delta = b * b - 4 * a * c;
        printf("Ket qua cua he phuong trinh dua tren thong so ban cung cap:\n");
        if (delta < 0)
        {
            printf("\tPhuong trinh vo nghiem");
        }
        else if (delta == 0)
        {
            printf("\tPhuong trinh co 1 nghiem kep la x = %.2f\n", (float) ((-b) / (2.0 * a)));
        }
        else {
            printf("Phuogn trinh co 2 nghiem phan biet: \n");
            printf("\t- x1 = %.2f\n", (float)(-b - sqrt(delta))/(2*a));
            printf("\t- x2 = %.2f\n", (float)(-b + sqrt(delta)) / (2 * a));
        }
    }
};
/*
    Bài 3: Viết hàm xử lý để lấy trạng thái của thiết bị
*/
typedef struct {
    char light;
    char fan;
    char motor;
}smartHome_t;

char check_on_off(const char* p_data, char status)
{
    char state;
    if (('o' == *p_data) && ('n' == *(p_data + 1)))
    {
        state = 1;
    }
    else if (('o' == *p_data) && ('f' == *(p_data + 1) && ('f' == (*p_data+2))))
    {
        state = 0;
    }
    else
    {
        state = status;
    }
    return state;
}
smartHome_t pair_data(const char* p_data)
{   
    int semicolon = 0;
    int comma = 0;
    smartHome_t status = { 0,0,0 };
    while (0 != *p_data)
    {
        //printf("%c\n", *p_data);
        if (':' == *p_data)
        {
            semicolon++;
        }
        if (',' == *p_data)
        {
            comma++;
        }
        if ((0 == comma) && (1 == semicolon))
        {
            status.light = check_on_off(p_data, status.light);
        }
        else if ((1 == comma) && (2 == semicolon))
        {
            status.fan = check_on_off(p_data, status.fan);
        }
        else if ((2 == comma) && (3 == semicolon))
        {
            status.motor = check_on_off(p_data, status.motor);
        }
        p_data++;
    }
    return status;
}

int main()
{
    printf("Bai tap 1\n");
	unsigned short so_nguyen_16_bit = 1234;
	print_so_nguyen_16bit(so_nguyen_16_bit);
    printf("\nBai tap 2\n");
    giai_phuong_trinh<int, int, int> phuongtrinh_1(1, 2, 1);
    printf("\nBai tap 3\n");
    const char* data = "HTTP1.1 200 OK{"\
        "\"light\": \"off\","\
        "\"fan\" : \"off\","\
        "\"motor\" : \"on\"}";
    smartHome_t x = pair_data(data);
    printf("Trang thai hien tai tu server la:\n\t- light: %d\n\t- fan: %d\n\t- motor: %d\n", x.light, x.fan, x.motor);
	return 0;
}