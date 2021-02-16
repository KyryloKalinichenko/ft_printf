/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:33:45 by kkalinic          #+#    #+#             */
/*   Updated: 2021/02/05 18:07:28 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

int	ft_printdot(char *s, va_list a, t_key *v)
{
	char *tmp;
	int i;
	
	i = 0;
	if (!s)
		return (0);
	if (ft_isdigit(*s))
	{
		if (!(tmp = ft_substr(s, 0, ft_skipnum(s) - s)))
		{
			v->ctr = -1;
			return (0);
		}
		i = ft_atoi(tmp);
		free(tmp);
	}
	else if(*s == '*')
		i = (int)(va_arg(a, int));
	v->fl3 = 1;
	return (i);
}

static void		ft_printres(t_key *v, int p, int w)
{
	if (v->fl)
	{
		if (v->fl3 == 1 && p >= 0)
			ft_putstrlm(v->res, p, v);
		else 
			ft_putstr(v->res, v);
		while (w-- > 0)
			ft_putchar(' ', v);
	}
	else if (!v->fl)
	{
		while (w-- > 0)
			ft_putchar(' ', v);
		if (v->fl3 == 1 && p >= 0)
			ft_putstrlm(v->res, p, v);
		else
			ft_putstr(v->res, v);
	}
}

void	ft_strprint(t_key *v)
{
	int w;
	int p;
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
		p = v->diff2;
		w = v->diff;
		printf("%i", w);
		if (v->fl3 == 1 && p > 0)
		{
			if (p <= len)
				w -= p;
			else if (len < p)
				w -= len;
		}
		else if (v->fl3 == 0 || p < 0)
				w -= len;
		ft_printres(v, p, w);
	}
}
