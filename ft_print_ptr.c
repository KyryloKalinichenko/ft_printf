/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:42:03 by kkalinic          #+#    #+#             */
/*   Updated: 2021/02/16 16:38:07 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_p(t_key *v, unsigned long long int addr)
{
	char *tmp;

	if (!addr && v->perc_f)
	{
		if (!(v->res = ft_strdup("0x")))
			v->ctr = -1;
		v->perc_q = 0;
		v->perc_f = 0;
	}
	else
	{
		v->res = "0x";
		tmp = ft_itoa_max(addr, 16);
		if (!(v->res = ft_strjoin(v->res, tmp)))
			v->ctr = -1;
		free(tmp);
	}
}

static void	ft_reg(char a, char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (a == 'X' && ft_isalpha(s[i]))
				s[i] = ft_toupper(s[i]);
			else if (a == 'x' && ft_isalpha(s[i]))
				s[i] = ft_tolower(s[i]);
			i++;
		}
	}
}

void	ft_print_ptr(unsigned long long int addr, char a, t_key *v)
{
	char *s;
//	char *tmp;

	if (a == 'p')
        ft_p(v, addr);
	else if (a == 'u')
        {
		    if (!(v->res = ft_itoa(addr, 10)))
                v->ctr = -1;
        }
	else if (a == 'X' || a == 'x')
	{
		if ((s = ft_itoa(addr, 16)))
		{
			/*if (v->hash && addr)
			{
				if ((tmp = ft_strjoin("0x", s)))
				{
					free (s);
					s = tmp;
				}
				else
				{
					v->ctr = -1;
					return ;
				}
			}*/
            ft_reg(a, s);
		}
		else
			v->ctr = -1;
		v->res = s;
	}
}
