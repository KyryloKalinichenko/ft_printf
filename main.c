#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <wchar.h>
#include <locale.h>

static int	wchar_to_mb_part_2(char *buffer, wchar_t code_point)
{
	if (code_point <= 0xffff)
	{
		buffer[2] = 0b10000000 | (code_point & 0b111111);
		buffer[1] = 0b10000000 | ((code_point >> 6) & 0b111111);
		buffer[0] = 0b11100000 | (code_point >> 12);
		return (3);
	}
	if (code_point <= 0x10ffff)
	{
		buffer[3] = 0b10000000 | (code_point & 0b111111);
		buffer[2] = 0b10000000 | ((code_point >> 6) & 0b111111);
		buffer[1] = 0b10000000 | ((code_point >> 12) & 0b111111);
		buffer[0] = 0b11110000 | (code_point >> 18);
		return (4);
	}
	return (0);
}

int			ft_wchar_to_mb(char *buffer, wchar_t code_point)
{
	if (code_point < 0)
		return (0);
	if (code_point <= 0x007f)
	{
		buffer[0] = code_point;
		return (1);
	}
	if (code_point <= 0x07ff)
	{
		buffer[1] = 0b10000000 | (code_point & 0b111111);
		buffer[0] = 0b11000000 | (code_point >> 6);
		return (2);
	}
	return (wchar_to_mb_part_2(buffer, code_point));
}

int main(void)
{
	wchar_t h;
	char i[4];
	int p;

	h = 0x007ff;
	p = 5;

	setlocale(LC_ALL, "");
	ft_wchar_to_mb(i, h);


		printf("%s", ft_itoa(h, 2));


/*
	printf("\n-----------\n");
	printf("NUM :%i ", printf("%lc", h));
	write(1, i, ft_wchar_to_mb(i, h));
	ft_printf("%i", sizeof(h));*/

}
