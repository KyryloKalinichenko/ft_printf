/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 10:56:12 by kkalinic          #+#    #+#             */
/*   Updated: 2021/02/18 15:28:50 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_len(long int n, int base)
{
	long int k;
	long int p;

	k = 1;
	p = 0;
	if (n == 0)
		return (1);
	while (n > (base - 1))
	{
		n /= base;
		k++;
	}
	return (k + p);
}

char			*ft_itoa(long int n, int base)
{
	char			*s;
	int				p;
	long long		k;

	k = n;
	p = ft_len(k, base);
	s = malloc(sizeof(char) * (p + 1));
	if (s == NULL)
		return (NULL);
	s[p] = '\0';
	if (k == 0)
		s[0] = '0';
	while (k > 0)
	{
		p--;
		if ((k % base) < 10)
			s[p] = ((k % base) + 48);
		else if ((k % base) <= 15 && (k % base) > 9)
			s[p] = (((k % base) - 9) + 96);
		k /= base;
	}
	return (s);
}
