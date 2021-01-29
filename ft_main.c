#include "ft_printf.h"
#include <stdio.h>

int     main()
{
 int             a = -4;
        int             b = 0;
        char    c = 'a';
        int             d = 2147483647;
        int             e = -2147483648;
        int             f = 42;
        int             g = 25;
        int             h = 4200;
        int             i = 10;
        int             j = -12;
        int             k = 123456789;
        int             l = 0;
        int             m = -12345678;
        char    *n = "abcdefghijklmnop";
        char    *o = "-a";
        char    *p = "-12";
        char    *q = "0";
        char    *r = "%%";
        char    *s = "-2147483648";
        char    *t = "0x12345678";
        char    *u = "-0";

       printf(" --- Return : %d\n", printf("Simple input test"));
        ft_printf(" --- Return : %d\n", ft_printf("Simple input test"));
	printf("\n----------------------\n");
        printf(" --- Return : %d\n", printf("%0i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j)); //T2
        ft_printf(" --- Return : %d\n", ft_printf("%0i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j)); //T2
	printf("\n----------------------\n");
       	printf(" --- Return : %d\n", printf("%-5i, %-5d, %-5d, %-5d, %-5d, %-5d, %-5d, %-5d", i, j, k, l, m, c, e, d)); //T3
       	ft_printf(" --- Return : %d\n", ft_printf("%-5i, %-5d, %-5d, %-5d, %-5d, %-5d, %-5d, %-5d", i, j, k, l, m, c, e, d)); //T3
	printf("\n----------------------\n");
	printf("%*i, %10.5i, %*i, %.*i.\n", i, i, i, i, i, i, i);
	ft_printf("%*i, %10.5i, %*i, %.*i.\n", i, i, i, i, i, i, i);
	printf("\n----------------------\n");
	printf(" --- Return : %d\n", printf("%-0.1i, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d", i, j, k, l, m, c, e, d)); //T30
	ft_printf(" --- Return : %d\n", ft_printf("%-0.1i, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d", i, j, k, l, m, c, e, d)); //T30
	printf("\n----------------------\n");
        printf(" --- Return : %d\n", printf("%-1.0i, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d", i, j, k, l, m, c, e, d)); //T31
        ft_printf(" --- Return : %d\n", ft_printf("%-1.0i, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d", i, j, k, l, m, c, e, d)); //T31
	printf("\n----------------------\n");
        printf(" --- Return : %d\n", printf("%-1.1i, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d", i, j, k, l, m, c, e, d)); //T32
        ft_printf(" --- Return : %d\n", ft_printf("%-1.1i, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d", i, j, k, l, m, c, e, d)); //T32
	printf("\n----------------------\n");
        printf(" --- Return : %d\n", printf("%1.0i, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d", i, j, k, l, m, c, e, d)); //T33
        ft_printf(" --- Return : %d\n", ft_printf("%1.0i, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d", i, j, k, l, m, c, e, d)); //T33 
 	while (a < 5) //T34-69
        {
                printf(" --- Return : %d\n", printf("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		ft_printf(" --- Return : %d\n", ft_printf("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		printf("\n----------------------\n");
                printf(" --- Return : %d\n", printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
                ft_printf(" --- Return : %d\n", ft_printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		printf("\n----------------------\n");
                printf(" --- Return : %d\n", printf("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
                ft_printf(" --- Return : %d\n", ft_printf("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		printf("\n----------------------\n");
                printf(" --- Return : %d\n", printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
                ft_printf(" --- Return : %d\n", ft_printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		printf("\n----------------------\n");
                a++;
        }
	 printf(" --- Return : %d\n", printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c, e, d)); //T12
	 ft_printf(" --- Return : %d\n", ft_printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c, e, d)); //T12
	printf("\n----------------------\n");
 	printf(" --- Return : %d\n", printf("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d", i, j, k, l, m, c, e, d)); //T17
 	ft_printf(" --- Return : %d\n", ft_printf("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d", i, j, k, l, m, c, e, d)); //T17
	printf("\n----------------------\n");
        printf(" --- Return : %d\n", printf("%-.0i, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d", i, j, k, l, m, c, e, d)); //T18
        ft_printf(" --- Return : %d\n", ft_printf("%-.0i, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d", i, j, k, l, m, c, e, d)); //T18
	a = 1;
	printf(" --- Good return : %d\n", printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
ft_printf(" --- Return : %d\n", ft_printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));


	printf("%010d\n", -12);
	ft_printf("%010d\n", -12);
 while(a < 5) //T70-177
        {
                b = -2;
                while (b < 5)
                {
                        printf(" --- Return : %d\n", printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
                        ft_printf(" --- Return : %d\n", ft_printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	printf("\n----------(%i) a-----(%i) b-------\n", a, b);
                        printf(" --- Return : %d\n", printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
                        ft_printf(" --- Return : %d\n", ft_printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	printf("\n----------(%i) a-----(%i) b-------\n", a, b);
                        printf(" --- Return : %d\n", printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
                        ft_printf(" --- Return : %d\n", ft_printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	printf("\n----------(%i) a-----(%i) b-------\n", a, b);
                        b++;
                }
                a++;
        }
        a = 2;
        b = 1;
        printf(" --- Return : %d\n", printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c, e, d));
        ft_printf(" --- Return : %d\n", ft_printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c, e, d));
	printf("\n----------------------\n");

        a = -1;
        while (a++ < 2)
        {
                printf("%%, \t, \\, \", \', +\n");
                ft_printf("%%,\n");
        }


}
