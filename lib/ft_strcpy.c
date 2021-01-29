/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:00:40 by kkalinic          #+#    #+#             */
/*   Updated: 2020/11/20 11:51:11 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int count;

	count = 0;
	while (src[count] != '\0')
	{
		dst[count] = (char)src[count];
		count++;
	}
	dst[count] = '\0';
	return (dst);
}
