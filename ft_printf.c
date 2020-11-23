#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(int n)
{
	int i;
	
	i = 1;
	if (n < 0)
	{
		i = -1;
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr((n - (n % 10)) / 10);
		ft_putchar(48 + (n % 10));
	}
	if (n > -1 && n < 10)
		ft_putchar(48 + n);

}

void	ft_putstr(char *s)
{
	while(*s)
		ft_putchar(*s++);
}

int	ft_printf(const char *s, ...)
{
	va_list lst;
	int i;
	int p;

	va_start(lst, s); 
	p = -1;
	while (*s)
	{
		if (*s++ == '%')
		{
			if (*s == 'd' || *s == 'i')
				ft_putnbr(va_arg(lst, int));
			else if (*s == 'c')
				ft_putchar(va_arg(lst, int));
			else if (*s == 's')
				ft_putstr(va_arg(lst, char *));
		}
		else
			write(1, --s, 1);
		s++;
	}
	va_end(lst);
	return (0);

}

int	main()
{
	ft_printf("Hey %s lnlbn", "lol");
}
