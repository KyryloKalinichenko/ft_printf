/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:38:59 by kkalinic          #+#    #+#             */
/*   Updated: 2021/02/18 18:08:23 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_res(t_key *v)
{
	if (v->zerch && !v->l)
		ft_putchar(v->res[0], v);
	else if (v->zerch && v->l)
		ft_putwchar(v);
	else
		ft_putstr(v->res, v);
	free(v->res);
}

static void		ft_printsg(t_key *v)
{
	if (v->neg)
		ft_putchar('-', v);
	else if (v->plus)
		ft_putchar('+', v);
	else if (v->space)
		ft_putchar(' ', v);
}

void			ft_rjustify(t_key *v, int p, int w)
{
	if (v->neg == 1 || v->space || v->plus)
		w--;
	if (v->zero == 1 && v->perc_q != 0)
		ft_printsg(v);
	if (0 != ft_strcmp("0", v->res) && v->a == 'x' && v->hash)
		ft_putstr("0x", v);
	else if (0 != ft_strcmp("0", v->res) && v->a == 'X' && v->hash)
		ft_putstr("0X", v);
	while (0 < w--)
		ft_putchar(v->b, v);
	if (v->zero == 0 || v->perc_q == 0)
		ft_printsg(v);
	if (v->a == 'p')
		ft_putstr("0x", v);
	if (v->perc_f == 1)
	{
		while (p-- > 0)
			ft_putchar('0', v);
		if (0 != ft_strcmp("0", v->res) || v->perc_q != 0)
			ft_res(v);
		else
			free(v->res);
	}
	else
		ft_res(v);
}

void			ft_ljustify(t_key *v, int p, int w)
{
	if (v->neg || v->plus || v->space)
	{
		ft_printsg(v);
		w--;
	}
	if (v->a == 'p')
		ft_putstr("0x", v);
	if (0 != ft_strcmp("0", v->res) && v->a == 'x' && v->hash)
		ft_putstr("0x", v);
	else if (0 != ft_strcmp("0", v->res) && v->a == 'X' && v->hash)
		ft_putstr("0X", v);
	if (v->perc_f == 1)
	{
		while (p-- > 0)
			ft_putchar('0', v);
		if (0 != ft_strcmp("0", v->res) || v->perc_q != 0)
			ft_res(v);
		else
			free(v->res);
	}
	else
		ft_res(v);
	while (0 < w--)
		ft_putchar(v->b, v);
}

void			ft_printnum(t_key *v)
{
	int p;
	int w;
	int len;

	if (v)
	{
		len = ft_strlen(v->res);
		if (v->hash && (v->a == 'x' || v->a == 'X') && ft_strcmp("0", v->res))
			v->width -= 2;
		p = v->perc_q - len;
		if (v->perc_q == 0 && !ft_strcmp("0", v->res))
			w = v->width;
		else
			w = v->width - len;
		if (p > 0)
			w -= p;
		if (v->zero == 1 && v->perc_q != 0)
			v->b = '0';
		else
			v->b = ' ';
		if (v->ljus == 0)
			ft_rjustify(v, p, w);
		else
			ft_ljustify(v, p, w);
	}
}
