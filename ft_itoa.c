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

static int		ft_len(long long n, int base)
{
	long int k;

	k = 1;
	if (n == 0)
		return (1);
	if (n > 0)
	{
		while (n > (base - 1))
		{
			n /= base;
			k++;
		}
	}
	else
	{
		while (n < ((base - 1) * -1))
		{
			n /= base;
			k++;
		}
		k--;
	}
	return (k);
}

char			*ft_sign(char *s, long long n, int len)
{
	while (n <= -10)
	{
		if ((n % 10) >= -10)
			s[len--] = (((n % 10) * -1) + 48);
		n /= 10;
	}
	s[len--] = (n % 10) * -1 + '0';
	return (s);
}

char			*ft_itoa(long long k, int base)
{
	char			*s;
	int				p;

	p = ft_len(k, base);
	if (!(s = malloc(sizeof(char) * (p + 1))))
		return (NULL);
	s[p] = '\0';
	if (k == 0)
		s[0] = '0';
	if (k < 0)
		return (ft_sign(s, k, p));
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
