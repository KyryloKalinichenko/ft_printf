/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:35:48 by kkalinic          #+#    #+#             */
/*   Updated: 2021/02/17 17:35:24 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

static int	ft_isflags(char *s)
{
	int i;
	const char a[7] = "+ -h0#";

	i = -1;
	while(a[++i])
	{
		if (a[i] == *s)
			return (1);
	}
	return (0);
}

static char	*ft_flag(char *s, t_key *v)
{
	while(s && ft_isflags(s))
	{
		if (*s == '+' && !v->plus)
			v->plus = 1;
		else if (*s == 'h')
			v->sh = 1;
		else if (*s == '#')
			v->hash = 1;
		else if (*s == ' ' && !v->space)
			v->space = 1;
		else if (*s == '-' && !v->fl)
			v->fl = 1;
		else if (*s == '0' && !v->fl)
			v->fl2 = 1;
		s++;
	}
	if (v->plus)
		v->space = 0;
	if (v->fl)
		v->fl2 = 0;
	return (s);
}

static void	ft_width(t_key *v, va_list lst, char *s)
{
	if (0 > (v->diff = ft_printsp((char*)s, lst, v)))
		{
			v->fl = 1;
			v->fl2 = 0;
			v->diff *= -1;
		}
}

char	*ft_percision(t_key *v, char *s, va_list lst)
{
	v->diff2 = ft_printdot((char*)++s, lst, v);
	if (ft_isdigit(*s))
		s = ft_skipnum((char*)s);
	else if (*s == '*')
		s++;
	if (v->diff2 > 0 && *s != '%' && 
			*s != 'c' && *s != 's')
		v->fl2 = 0;
	return (s);
}

char	*ft_percent(t_key *v, char *s, va_list lst)
{
	v->a = *ft_skipall(s);
	if (v->a == 'n')
	{
		ft_itisconv(v->a, lst, v);
		return (ft_skipall(s));
	}
	s = ft_flag(s, v);
	if (ft_isdigit(*s) || *s == '*')
	{
		ft_width(v, lst, s);
		if (v->ctr == -1)
			return (NULL);
	}
	if (*(s = ft_skipnum((char*)s)) == '.'		
		|| *(s = ft_skipstar((char*)s)) == '.')
		if ((s = ft_percision(v, s, lst)) && v->ctr == -1)
			return (NULL);
	s = ft_flag(s, v);
	if (ft_isconv((char*)s))
	{
		ft_itisconv(v->a, lst, v);
		if (v->ctr == -1)
			return (NULL);
	}
	if (v->a == 's')
	{
		//printf("---%s---", v->res)
		ft_strprint(v);
		if (v->ctr == -1)
			return (NULL);
	}
	else
		ft_star(v);
	return(ft_skipall((char*)s));
}
