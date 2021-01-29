/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:22:27 by kkalinic          #+#    #+#             */
/*   Updated: 2020/11/23 10:47:23 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	n;
	size_t			len_little;

	if (*little == '\0')
		return (char*)(big);
	n = 0;
	(void)len;
	len_little = ft_strlen(little);
	while (*big != '\0')
	{
		if (n + len_little > len)
			return (NULL);
		if (ft_strncmp(big, little, len_little) == 0)
			return (char*)(big);
		big++;
		n++;
	}
	return (NULL);
}
