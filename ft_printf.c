/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:37:44 by kkalinic          #+#    #+#             */
/*   Updated: 2021/02/11 16:56:18 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	const char a[11] = "-. *0+#h\0";

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
	const char a[10] = "dincspuxX\0";
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
		if (v->sh)
			i = (short int)va_arg(lst, int);
		else
			i = va_arg(lst, int);
		if (i < 0)
		{	
			v->neg = 1;
			i *= -1;
		}
		if(!(v->res = ft_itoa(i, 10)))
			return ;
	}
	else if (a == 'n')
		*(va_arg(lst, int*)) = ctr;
	else if (a == 'c')
	{
		if(!(v->res = ft_calloc(2, sizeof(char))))
			return ;
		v->res[0] = (a = va_arg(lst, int));
		v->zerch = 1;
	}
	else if (a == 's')
	{
		if(!(s = ft_strdup((va_arg(lst, char *)))))
			s = NULL;
		v->res = s;
	}
	else if (a == 'x' || a == 'X' || a == 'u' || a == 'p')
	{
		if (v->sh && a != 'p')
			i = (short unsigned int)va_arg(lst, int);
		else
			i = va_arg(lst, int);
		ft_print_ptr(i, a, v);
	}
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
