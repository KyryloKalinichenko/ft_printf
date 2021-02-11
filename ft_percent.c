/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:35:48 by kkalinic          #+#    #+#             */
/*   Updated: 2021/02/05 17:36:18 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

static char	*ft_flag(char *s, t_key *v)
{
	while(s && (*s == '-' ||
		 *s == '0' || *s == '+' || *s == ' ' || *s == '#'))
	{
		if (*s == '+' && !v->plus)
		{
			v->plus = 1;
			s++;
		}
		else if (*s == '#')
		{
			v->hash = 1;
			s++;
		}
		else if (*s == ' ' && !v->space)
		{
			v->space = 1;
			s++;
		}
		else if (*s == '-' && !v->fl)
		{
			v->fl = 1;
			s++;
		}
		else if (*s == '0' && !v->fl)
		{
			v->fl2 = 1;
			s++;
		}
		else
			s++;
	}
	//printf("//%s///", s);
	if (v->plus)
		v->space = 0;
	if (v->fl)
		v->fl2 = 0;
	return (s);
}

static void	ft_width(t_key *v, va_list lst, char *s)
{
	if (0 > (v->diff = ft_printsp((char*)s, lst)))
		{
			v->fl = 1;
			v->fl2 = 0;
			v->diff *= -1;
		}
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
		ft_width(v, lst, s);
	if (*(s = ft_skipnum((char*)s)) == '.'		
		|| *(s = ft_skipstar((char*)s)) == '.')
	{
		v->diff2 = ft_printdot((char*)++s, lst, v);
		if (v->diff2 > 0)
			v->fl2 = 0;
	}
	if (ft_isconv(s = ft_skipnum((char*)s)) || ft_isconv((char*)++s))
		ft_itisconv(v->a, lst, v);
	if (v->a == 's')
		ft_strprint(v);
	else
		ft_star(v);
	return(ft_skipall((char*)s));
}
