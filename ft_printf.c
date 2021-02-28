/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:37:44 by kkalinic          #+#    #+#             */
/*   Updated: 2021/02/18 18:32:12 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char a, t_key *v)
{
	write(1, &a, 1);
	v->ctr++;
}

void	ft_putwchar(t_key *v)
{
	if (v->res && v->l)
	{
		write(1, v->res, v->l);
		v->ctr++;
	}
}

int		ft_printf(const char *s, ...)
{
	va_list	lst;
	t_key	*v;
	int		i;

	i = 0;
	va_start(lst, s);
	if (!s || !(v = malloc(sizeof(t_key))))
		return (-1);
	v->ctr = 0;
	while (*s)
	{
		if (*s == '%')
		{
			ft_load(v);
			if (!(s = ft_percent(v, (char*)++s, lst)))
				break ;
		}
		else
			ft_putchar(*s, v);
		s++;
	}
	i = v->ctr;
	free(v);
	va_end(lst);
	return (i);
}
