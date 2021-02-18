/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:23:44 by kkalinic          #+#    #+#             */
/*   Updated: 2020/12/09 11:52:01 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strncpy(char *dest, const char *src, size_t n)
{
	int				i;
	const char		*b;

	if (!dest || !src)
		return (NULL);
	b = (char*)src;
	i = 0;
	while (b[i] != '\0' && n)
	{
		dest[i] = b[i];
		n--;
		i++;
	}
	while (n)
	{
		dest[i] = '\0';
		i++;
		n--;
	}
	return (dest);
}
