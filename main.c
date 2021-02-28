#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <wchar.h>
#include <locale.h>



int main(void)
{
	long long int h;
	char i[4];
	int p;

	h = UCHAR_MAX;
	p = 5;

	setlocale(LC_ALL, "");



	//printf("%s", ft_itoa(h, 2));



	//while(h < INT32_MIN - 1)
	//{
		   printf(" NUM ORIG:%i ",    printf("SYMBOL :%-.d", 0));
		   printf("\n-----------\n");
		ft_printf(" NUM     :%i ", ft_printf("SYMBOL :%-.d", 0));
		printf("\n-----------\n");
	//	h++;
	//}
	//ft_printf("%i", sizeof(h));

}
