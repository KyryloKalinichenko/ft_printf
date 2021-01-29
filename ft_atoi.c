/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:28:52 by kkalinic          #+#    #+#             */
/*   Updated: 2020/11/25 14:10:03 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_isotherwhitespace(char c)
{
	return (c == '\v' || c == '\f' || c == '\r');
}

static int		ft_isstrwhitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int		ft_iswhitespace(char c)
{
	return (ft_isstrwhitespace(c) || ft_isotherwhitespace(c));
}

int				ft_atoi(const char *str)
{
	int				i;
	long long int	nbr;
	long long int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	if (str)
	{
		while (ft_iswhitespace(str[i]))
			i++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign = -1;
			i++;
		}
		while (str[i] && ft_isdigit(str[i]))
		{
			nbr = nbr * 10 + str[i] - '0';
			i++;
			if ((nbr * sign) > 2147483647)
				return (-1);
			if ((nbr * sign) < -2147483648)
				return (0);
		}
		return (nbr * sign);
	}
	return (0);
}
