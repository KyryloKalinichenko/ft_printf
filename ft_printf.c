/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:37:44 by kkalinic          #+#    #+#             */
/*   Updated: 2021/02/18 18:32:12 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char a, t_key *v)
{
	write(1, &a, 1);
	v->ctr++;
}

int		ft_isflag(char *s)
{
	int			i;
	const char	a[9] = "-. *0+#h";

	i = -1;
	while (a[++i])
	{
		if (a[i] == *s)
			return (1);
	}
	return (0);
}

int		ft_isconv(const char *b)
{
	const char	a[11] = "dincspuxX%";
	int			i;

	if (b)
	{
		i = -1;
		while (a[++i])
		{
			if (a[i] == *b)
				return (1);
		}
	}
	return (0);
}

void	ft_itisconv(char a, va_list lst, t_key *v)
{
	long long	i;
	char		*s;

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
		if (!(v->res = ft_itoa(i, 10)))
			v->ctr = -1;
	}
	else if (a == 'n')
	{
		if (v->sh)
			*(va_arg(lst, int*)) = (short int)v->ctr;
		else
			*(va_arg(lst, int*)) = v->ctr;
	}
	else if (a == 'c' || a == '%')
	{
		if (!(v->res = ft_calloc(2, sizeof(char))))
			v->ctr = -1;
		else
		{
			if (a == 'c')
				a = (char)va_arg(lst, int);
			else
			{
				v->perc_f = 0;
				v->perc_q = 1;
			}
			v->res[0] = a;
			v->zerch = 1;
		}
	}
	else if (a == 's')
	{
		s = va_arg(lst, char *);
		if (s && !(s = ft_strdup(s)))
			v->ctr = -1;
		else
			v->res = s;
	}
	else if (a == 'x' || a == 'X' || a == 'u' || a == 'p')
	{
		if (v->sh && a != 'p')
			i = (short unsigned int)va_arg(lst, int);
		else if (a == 'x' || a == 'X' || a == 'u')
			i = va_arg(lst, unsigned int);
		else
			i = va_arg(lst, unsigned long long int);
		ft_print_ptr(i, a, v);
	}
}

int		ft_printf(const char *s, ...)
{
	va_list	lst;
	t_key	*v;
	int		i;

	i = 0;
	va_start(lst, s);
	if (!s || !(v = malloc(sizeof(t_key))))
		return (-1);
	v->ctr = 0;
	while (*s)
	{
		ft_load(v);
		if (*s == '%' && ft_isconv(ft_skipall((char*)++s)))
		{
			if (!(s = ft_percent(v, (char*)s, lst)))
				break ;
			if (v->res)
				free(v->res);
		}
		else
			ft_putchar(*s, v);
		s++;
	}
	i += v->ctr;
	free(v);
	va_end(lst);
	return (i);
}
