#include "ft_printf.h"
#include <stdio.h>

int ctr;

void	ft_putchar(char a)
{
	write(1, &a, 1);
	ctr++;
}

int	ft_isflag(char *s)
{
	int i;
	const char a[4] = "-.*";

	i = -1;
	while(a[++i])
	{
		if (a[i] == *s)
			return (1);
	}
	return (0);
}

int	ft_isconv(const char *b)
{
	const char a[9] = "dicspuxX\0";
	int i;

	if (b)
	{
		i = -1;
		while (a[++i])
		{
			if (a[i] == *b)
				return(1);
		}
	}
	return (0);
}

void	ft_itisconv(char a, va_list lst, t_key *v)
{
	long long i;
	char *s;

	if (a == 'd' || a == 'i')
	{
		if (0 > (i = va_arg(lst, int)))
		{
			v->neg = 1;
			i *= -1;
		}
		if(!(v->res = ft_itoa(i, 10)))
			return ;
	}
	else if (a == 'c')
	{
		if(!(v->res = ft_calloc(2, a)))
			return ;
		v->res[0] = va_arg(lst, int);
	}
	else if (a == 's')
	{
	//	s = va_arg(lst, char *);
	//	printf("---%s---", s);
		if(!(s = ft_strdup((va_arg(lst, char *)))))
			s = NULL;
		v->res = s;
	}
	else if (a == 'x' || a == 'X' || a == 'p' || a == 'u')
		ft_print_ptr(va_arg(lst, int), a, v);
}

int	ft_printf(const char *s, ...)
{
	va_list lst;
	t_key *v;

	ctr = 0;
	va_start(lst, s);
	if (!s || !(v = malloc(sizeof(t_key))))
		return (0);
	while (*s)
	{
		ft_load(v);
		if (*s == '%' && ft_isconv(ft_skipall((char*)++s)))
		{
			s = ft_percent(v, (char*)s, lst);
			//ft_putstr(v->res);
			if (v->res)
				free(v->res);
		}
		else
			ft_putchar(*s);
		s++;
	}
	free(v);
	va_end(lst);
	return (ctr);
}