/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:35:48 by kkalinic          #+#    #+#             */
/*   Updated: 2021/02/18 18:08:46 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_width(t_key *v, va_list lst, char *s)
{
	s = ft_printsp((char*)s, lst, v);
	if (0 > (v->width))
	{
		v->ljus = 1;
		v->zero = 0;
		v->width *= -1;
	}
	return (s);
}

char		*ft_percision(t_key *v, char *s, va_list lst)
{
	s = ft_printdot(++s, lst, v);
	if (v->perc_q > 0 && *s != '%' &&
			*s != 'c' && *s != 's')
		v->zero = 0;
	return (s);
}

void		ft_itisconv(char a, va_list lst, t_key *v)
{
	char	*s;

	if (a == 'd' || a == 'i')
		ft_convint(v, lst);
	else if (a == 'n')
		ft_convn(v, lst);
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

char		*ft_percent(t_key *v, char *s, va_list lst)
{
	if (!ft_isconv(v->a = *ft_skipall(s)))
		return (NULL);
	s = ft_flag(s, v);
	s = ft_width(v, lst, s);
	if (*s == '.')
		s = ft_percision(v, s, lst);
	s = ft_size(s, v);
	ft_itisconv(v->a, lst, v);
	if (v->a == 's' && v->ctr != -1)
		ft_strprint(v);
	else if (v->ctr != -1)
		ft_printnum(v);
	if (v->ctr == -1)
		return (NULL);
	return (s);
}
