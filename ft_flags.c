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

char				*ft_printsp(char *s, va_list lst, t_key *v)
{
	int		i;

	i = 0;
	if (s && ft_isdigit(*s))
	{
		while (*s >= '0' && *s <= '9')
		{
			i = i * 10 + *s - '0';
			s++;
		}
	}
	else if (s && *s == '*')
	{
		i = va_arg(lst, int);
		s++;
	}
	v->width = i;
	return (s);
}

char				*ft_size(char *s, t_key *v)
{
	while (s && (*s == 'h' ||
			*s == 'l'))
	{
		if (*s == 'h' && v->sh)
			{
				v->sh = 0;
				v->hh = 1;
			}
		else if (*s == 'h')
			v->sh = 1;
		if (*s == 'l' && v->l)
		{
			v->l = 0;
			v->ll = 1;
		}
		else if (*s == 'l')
			v->l = 1;
		s++;
	}
	return (s);
}

char				*ft_flag(char *s, t_key *v)
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
