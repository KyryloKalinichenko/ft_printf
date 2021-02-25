/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:54:33 by kkalinic          #+#    #+#             */
/*   Updated: 2021/02/18 16:00:34 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putstr(const char *str, t_key *v)
{
	int i;

	i = -1;
	if (str)
	{
		while (str[++i])
			ft_putchar(str[i], v);
	}
}

void			ft_putstrlm(const char *str, int lm, t_key *v)
{
	int i;

	i = -1;
	if (str && lm > 0)
	{
		while (str[++i] && lm-- > 0)
			ft_putchar(str[i], v);
	}
}

void			ft_printres(t_key *v, int p, int w)
{
	if (v->zero)
		v->a = '0';
	else
		v->a = ' ';
	if (v->ljus)
	{
		if (v->perc_f == 1 && p >= 0)
			ft_putstrlm(v->res, p, v);
		else
			ft_putstr(v->res, v);
		while (w-- > 0)
			ft_putchar(v->a, v);
	}
	else
	{
		while (w-- > 0)
			ft_putchar(v->a, v);
		if (v->perc_f == 1 && p >= 0)
			ft_putstrlm(v->res, p, v);
		else
			ft_putstr(v->res, v);
	}
	free(v->res);
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
