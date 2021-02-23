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

static int		ft_isflags(char *s)
{
	int			i;
	const char	a[7] = "+ -0#";

	i = -1;
	while (a[++i])
	{
		if (a[i] == *s)
			return (1);
	}
	return (0);
}

static char		*ft_flag(char *s, t_key *v)
{
	while (s && ft_isflags(s))
	{
		if (*s == '+' && !v->plus)
			v->plus = 1;
		else if (*s == '#')
			v->hash = 1;
		else if (*s == ' ' && !v->space)
			v->space = 1;
		else if (*s == '-' && !v->ljus)
			v->ljus = 1;
		else if (*s == '0' && !v->ljus)
			v->zero = 1;
		s++;
	}
	if (v->plus)
		v->space = 0;
	if (v->ljus)
		v->zero = 0;
	return (s);
}

static char		*ft_width(t_key *v, va_list lst, char *s)
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

#include <stdio.h>

char			*ft_size(char *s, t_key *v)
{
	while (s && (*s == 'h' ||
			*s == 'l'))
	{
		if (*s == 'h')
		{
			if (*++s == 'h')
				v->hh = 1;
			else
				v->sh = 1;
		}
		else if (*s == 'l')
		{
			if (*++s == 'l')
				v->ll = 1;
			else
				v->l = 1;
		}
		s++;
	}
	return (s);
}

char			*ft_percent(t_key *v, char *s, va_list lst)
{
	if (!ft_isconv(v->a = *ft_skipall(s)))
		return (NULL);
	s = ft_flag(s, v);
	//printf("//%c//", *s);
	s = ft_width(v, lst, s);
	if (*s == '.')
		s = ft_percision(v, s, lst);
//	if (*s == 'h')
//		v->sh = 1;
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
