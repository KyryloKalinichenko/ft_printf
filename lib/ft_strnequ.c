/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:31:38 by kkalinic          #+#    #+#             */
/*   Updated: 2020/11/23 10:47:53 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	if (s1 && s2)
	{
		i = ft_strncmp(s1, s2, n);
		if (i == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
