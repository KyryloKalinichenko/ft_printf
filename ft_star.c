/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:38:59 by kkalinic          #+#    #+#             */
/*   Updated: 2021/02/05 17:39:12 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static	void	ft_res(t_key *v)
{
	if (v->zerch)
		ft_putchar(v->res[0], v);
	else
		ft_putstr(v->res, v);
}

static void	ft_printsg(t_key *v)
{
	if (v->neg)
		ft_putchar('-', v);
	else if (v->plus)
		ft_putchar('+', v);
	else if (v->space)
		ft_putchar(' ', v);
}

void    ft_rjustify(t_key *v, int k, int p)
{
    if (v->neg == 1)
			p--;
	if (v->fl2 == 1 && v->diff2 != 0)
    		ft_printsg(v);
	while (0 < p--)
		ft_putchar(v->a, v);
	if (v->fl2 == 0 || v->diff2 == 0)
		ft_printsg(v);
	if (v->fl3 == 1)
	{	
		while (k-- > 0)
			ft_putchar('0', v);
		if (0 != ft_strcmp("0", v->res) || v->diff2 != 0)
			ft_res(v);
	}
	else
		ft_res(v);
}

void	ft_ljustify(t_key *v, int k, int p)
{
    if (v->neg || v->plus)
	{
		ft_printsg(v);
		p--;
	}
	if (v->fl3 == 1)
	{
		while (k-- > 0)
			ft_putchar('0', v);
		if (0 != ft_strcmp("0", v->res) || v->diff2 != 0)
			ft_res(v);
	}
	else
		ft_res(v);
	while (0 < p--)
		ft_putchar(v->a, v);
}

void	ft_star(t_key *v)
{
	int k;
	int p;
	int len;

	if (v)
	{
		len = ft_strlen(v->res);
        k = v->diff2 - len;
		if (v->diff2 == 0 && !ft_strcmp("0", v->res))
			p = v->diff;
		else
			p = v->diff - len;
		if (k > 0)
			p -= k;
		if (v->fl2 == 1 && v->diff2 != 0)
			v->a = '0';
		else 
			v->a = ' ';
		if (v->fl == 0)
            ft_rjustify(v, k, p);
		else if (v->fl == 1)
            ft_ljustify(v, k, p);
	}
}
