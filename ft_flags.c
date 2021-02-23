/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:33:45 by kkalinic          #+#    #+#             */
/*   Updated: 2021/02/18 17:59:51 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_printdot(char *s, va_list a, t_key *v)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (ft_isdigit(*s))
	{
		while (*s >= '0' && *s <= '9')
		{
			i = i * 10 + *s - '0';
			s++;
		}
	}
	else if (*s == '*')
	{
		i = (int)(va_arg(a, unsigned int));
		s++;
	}
	v->perc_f = 1;
	v->perc_q = i;
	return (s);
}

static void			ft_printres(t_key *v, int p, int w)
{
	if (v->ljus)
	{
		if (v->perc_f == 1 && p >= 0)
			ft_putstrlm(v->res, p, v);
		else
			ft_putstr(v->res, v);
		while (w-- > 0)
			ft_putchar(' ', v);
	}
	else
	{
		while (w-- > 0)
			ft_putchar(' ', v);
		if (v->perc_f == 1 && p >= 0)
			ft_putstrlm(v->res, p, v);
		else
			ft_putstr(v->res, v);
	}
}

void				ft_strprint(t_key *v)
{
	int len;

	if (v)
	{
		if (!v->res)
		{
			if (!(v->res = ft_strdup("(null)")))
			{
				v->ctr = -1;
				return ;
			}
		}
		len = ft_strlen(v->res);
		if (v->perc_f == 1 && v->perc_q > 0)
		{
			if (v->perc_q <= len)
				v->width -= v->perc_q;
			else if (len < v->perc_q)
				v->width -= len;
		}
		else if (v->perc_f == 0 || v->perc_q < 0)
			v->width -= len;
		ft_printres(v, v->perc_q, v->width);
	}
}

static void			ft_convunsig(t_key *v, va_list lst, char a)
{
	unsigned long long i;

	if (v->sh && a != 'p')
		i = (short unsigned int)va_arg(lst, int);
	else if (a == 'x' || a == 'X' || a == 'u')
		i = va_arg(lst, unsigned int);
	else
		i = va_arg(lst, unsigned long long int);
	ft_print_ptr(i, a, v);
}

void				ft_itisconv(char a, va_list lst, t_key *v)
{
	char	*s;

	if (a == 'd' || a == 'i')
		ft_convint(v, lst);
	else if (a == 'n')
	{
		if (v->sh)
			*(va_arg(lst, int*)) = (short int)v->ctr;
		else
			*(va_arg(lst, int*)) = v->ctr;
	}
	else if (a == 'c' || a == '%')
		ft_convchar(v, lst, a);
	else if (a == 's')
	{
		s = va_arg(lst, char *);
		if (s && !(s = ft_strdup(s)))
			v->ctr = -1;
		else
			v->res = s;
	}
	else if (a == 'x' || a == 'X' || a == 'u' || a == 'p')
		ft_convunsig(v, lst, a);
}
