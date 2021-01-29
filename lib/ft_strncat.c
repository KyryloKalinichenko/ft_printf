/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:35:00 by kkalinic          #+#    #+#             */
/*   Updated: 2020/11/20 11:36:02 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*a;
	int		i;
	int		p;

	i = 0;
	a = (char*)src;
	p = ft_strlen(a) + 1;
	while (dest[i] != '\0')
		i++;
	while (--p && n)
	{
		dest[i] = *a;
		i++;
		a++;
		n--;
	}
	dest[i] = '\0';
	return (dest);
}
