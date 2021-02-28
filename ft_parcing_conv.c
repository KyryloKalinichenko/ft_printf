/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:19:55 by kkalinic          #+#    #+#             */
/*   Updated: 2021/02/25 11:19:57 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_convint(t_key *v, va_list lst)
{
	long long i;

	if (v->sh)
		i = (short int)va_arg(lst, int);
	else if (v->hh)
		i = (char)va_arg(lst, int);
	else if (v->l)
		i = va_arg(lst, long);
	else if (v->ll)
		i = va_arg(lst, long long);
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

void			ft_convchar(t_key *v, va_list lst, char a)
{
	if (!(v->res = ft_calloc(4, sizeof(char))))
		v->ctr = -1;
	else if (!v->l)
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
	else
	{
		v->l = va_arg(lst, wchar_t);
		if (!(v->l = ft_wchar_to_mb(v->res, v->l)))
			v->ctr = -1;
	}
}

void			ft_convunsig(t_key *v, va_list lst, char a)
{
	unsigned long long i;

	if (v->sh && a != 'p')
		i = (unsigned short)va_arg(lst, int);
	else if (v->hh && a != 'p')
		i = (unsigned char)va_arg(lst, unsigned int);
	else if (v->l && a != 'p')
		i = va_arg(lst, unsigned long);
	else if (v->ll && a != 'p')
		i = va_arg(lst, unsigned long long);
	else if (a == 'x' || a == 'X' || a == 'u')
		i = va_arg(lst, unsigned int);
	else
		i = va_arg(lst, unsigned long long int);
	ft_print_ptr(i, a, v);
}

void			ft_convn(t_key *v, va_list lst)
{
	if (v->sh)
		*(va_arg(lst, int*)) = (short int)v->ctr;
	else if (v->hh)
		*(va_arg(lst, char*)) = v->ctr;
	else if (v->l)
		*(va_arg(lst, long*)) = v->ctr;
	else if (v->hh)
		*(va_arg(lst, long long*)) = v->ctr;
	else
		*(va_arg(lst, int*)) = v->ctr;
}
