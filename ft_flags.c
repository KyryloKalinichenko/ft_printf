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

static void		ft_printres(t_key *v, int p, int w)
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

void			ft_strprint(t_key *v)
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
