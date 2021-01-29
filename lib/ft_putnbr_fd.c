/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:08:13 by kkalinic          #+#    #+#             */
/*   Updated: 2020/12/09 12:04:18 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	long	k;

	i = 0;
	k = n;
	if (k < 0)
	{
		ft_putchar_fd('-', fd);
		k *= -1;
	}
	if (k > 9)
	{
		i = k % 10;
		ft_putnbr_fd(((k - i) / 10), fd);
		ft_putchar_fd(i + 48, fd);
	}
	if (k > -1 && k < 10)
		ft_putchar_fd(k + 48, fd);
}
