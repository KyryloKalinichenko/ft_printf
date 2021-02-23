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

void			ft_load(t_key *v)
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

int				ft_isflag(char *s)
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

char			*ft_percision(t_key *v, char *s, va_list lst)
{
	s = ft_printdot(++s, lst, v);
	if (v->perc_q > 0 && *s != '%' &&
			*s != 'c' && *s != 's')
		v->zero = 0;
	return (s);
}

char			*ft_skipnum(char *s)
{
	int i;

	i = -1;
	if (s)
	{
		while (ft_isdigit(s[++i]))
			;
		return (&s[i]);
	}
	return (NULL);
}

char			*ft_printsp(char *s, va_list lst, t_key *v)
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
