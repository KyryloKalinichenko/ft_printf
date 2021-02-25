/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:35:26 by kkalinic          #+#    #+#             */
/*   Updated: 2021/02/18 16:41:47 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_load(t_key *v)
{
	if (v)
	{
		v->ljus = 0;
		v->zero = 0;
		v->width = 0;
		v->perc_q = 1;
		v->neg = 0;
		v->perc_f = 0;
		v->res = NULL;
		v->space = 0;
		v->zerch = 0;
		v->plus = 0;
		v->hash = 0;
		v->hh = 0;
		v->l = 0;
		v->ll = 0;
		v->sh = 0;
	}
}

int			ft_isconv(const char b)
{
	const char	a[11] = "dincspuxX%";
	int			i;

	if (b)
	{
		i = -1;
		while (a[++i])
		{
			if (a[i] == b)
				return (1);
		}
	}
	return (0);
}

int			ft_isforpar(char *s)
{
	int			i;
	const char	a[10] = "-. *0+#hl";

	i = -1;
	while (a[++i])
	{
		if (a[i] == *s)
			return (1);
	}
	return (0);
}

int			ft_isflags(char *s)
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
