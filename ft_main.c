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

  /*     	
        printf(" --- Return : %d\n", printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], o[0], a, p[0], a, q[0], a, r[0], a, c));
	ft_printf(" --- Return : %d\n", ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], o[0], a, p[0], a, q[0], a, r[0], a, c));
        printf("\n----------------\n");
        printf(" --- Return : %d\n", printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], o[0], -a, p[0], -a, q[0], -a, r[0], -a, c));
        ft_printf(" --- Return : %d\n", ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], o[0], -a, p[0], -a, q[0], -a, r[0], -a, c));
	printf("\n----------------\n");
        printf(" --- Return : %d\n", printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], q[0], a, q[0], a, p[0], a, p[0], a, c));
        ft_printf(" --- Return : %d\n", ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], q[0], a, q[0], a, p[0], a, p[0], a, c));
	printf("\n----------------\n");
        printf(" --- Return : %d\n", printf("%c,  %-c, %1c, %*c,  %-*c,  %*c", -12, -1, -255, a, -12, a, -1, a, -255));
	ft_printf(" --- Return : %d\n", ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c", -12, -1, -255, a, -12, a, -1, a, -255));
        printf("\n----------------\n");
        printf(" --- Return : %d\n", printf("%%, \t, \\, \", \', +"));
	ft_printf(" --- Return : %d\n", ft_printf("%%, \t, \\, \", \', +"));
        printf("\n----------------\n");


        printf(" --- Return : %d\n", printf("%%%dbada%s%%**%s**-d%%0*d%-12s0*@", h, "bada", r, p, r, r, i, r, i, r, i));
         ft_printf(" --- Return : %d\n", ft_printf("%%%dbada%s%%**%s**-d%%0*d%-12s0*@", h, "bada", r, p, r, r, i, r, i, r, i));
	printf("\n----------------\n");
        printf(" --- Return : %d\n", printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, i, a, i, a, i, a, i, a, i));
         ft_printf(" --- Return : %d\n", ft_printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, i, a, i, a, i, a, i, a, i));
	printf("\n----------------\n");
        printf(" --- Return : %d\n", printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, j, a, j, a, j, a, j, a, j));
	 ft_printf(" --- Return : %d\n", ft_printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, j, a, j, a, j, a, j, a, j));
        printf("\n----------------\n");
        printf(" --- Return : %d\n", printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, l, a, l, a, l, a, l, a, l));
         ft_printf(" --- Return : %d\n", ft_printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, l, a, l, a, l, a, l, a, l));
       

	printf("\n----------------\n");
        printf(" --- Return : %d\n", printf("%i, %d, %d, %d, %d, %d, %u, %#x, %#X", 0, 0, 0, 0, 0, 0, 0, 10, 10));
        ft_printf(" --- Return : %d\n", ft_printf("%i, %d, %d, %d, %d, %d, %u, %#x, %#X", 0, 0, 0, 0, 0, 0, 0, 10, 10));
	printf("\n----------------\n");
        printf(" --- Return : %d\n", printf("%*i, %*d, %*d, %*d, %*d, %*d, %*u, %#*x, %#*X", a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0));
	ft_printf(" --- Return : %d\n", ft_printf("%*i, %*d, %*d, %*d, %*d, %*d, %*u, %#*x, %#*X", a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0));
        printf("\n----------------\n");
        printf(" --- Return : %d\n", printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0));
	 ft_printf(" --- Return : %d\n", ft_printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0));
        printf("\n----------------\n");

      //ft_printf("%s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s\n", NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL);

   
        printf("\n----------------\n");
        // ^ Theoriquement un comportement indefini mais testé par la moulinette
        printf(" --- Return : %d\n", printf("(null)"));
        ft_printf(" --- Return : %d\n", ft_printf("(null)"));
	printf("\n----------------\n");
        printf(" --- Return : %d\n", printf(""));
        ft_printf(" --- Return : %d\n", ft_printf(""));
        	ft_printf("It is my  : %c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %:5c, %3c, %-*c, %-*c, %*c, %*c\n", 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
    printf("\n----------------\n");
	printf("It is orig: %c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n", 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);

        int lol;
        int* kek;

       lol = 1477189484;
        kek = &lol;
                printf("%c\n", 250);
               ft_printf("%c\n", 250);
        lol = (int)lol;
         ft_printf("42%20.*d42\n", 20, 147718);
              ft_printf("42%20.20hn42\n", kek);
              lol = 1477189484;
                printf("42%20.20hn42\n", kek);
         //     ft_printf("Hello.");
         lol = 0;
        while(lol++ != 200)
        {
			printf("Orig: %c\n", lol);
			ft_printf("Mine: %c\n", lol);
        }
        */
       float lol;
       lol = 12345.60;

      // printf("%f\n", lol);
      while (lol > 0)
      {
         printf("%s\n", ft_itoa_float(lol));
         lol /= 10;
      }
}
