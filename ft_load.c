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

void	ft_load(t_key *v)
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
		v->sh = 0;
	}
}

char	*ft_skipnum(char *s)
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

int		ft_printsp(char *s, va_list lst, t_key *v)
{
	char	*str;
	int		i;

	i = 1;
	if (s && ft_isdigit(*s))
	{
		if (!(str = ft_substr(s, 0, (int)(ft_skipnum(s) - s))))
		{
			v->ctr = -1;
			return (0);
		}
		i = ft_atoi(str);
		free(str);
		return (i);
	}
	else if (s && *s == '*')
		i = va_arg(lst, int);
	return (i);
}
