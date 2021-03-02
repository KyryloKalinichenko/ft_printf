#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <wchar.h>
#include <locale.h>



int main(void)
{
	unsigned long long int h;
	char i[4];
	int p;

	h = ULONG_MAX + 1;
	p = 5;

	setlocale(LC_ALL, "");

	/*TEST(15, print(" %#-03.2x ", 1));
	TEST(16, print(" %#-03.*x ", 2, 1));
*/
	//printf("%s", ft_itoa(h, 2));
	printf(" %x ", h);
	printf("\n---------\n");
	ft_printf(" %x ", h );
	
	

}
