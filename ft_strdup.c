/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:47:37 by kkalinic          #+#    #+#             */
/*   Updated: 2020/11/20 11:48:15 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;
	int p;

	if (s)
	{
		p = ft_strlen((char*)s) + 1;
		i = -1;
		dup = malloc(sizeof(char) * p);
		if (dup == NULL)
			return (NULL);
		while (s[++i])
			dup[i] = s[i];
		dup[i] = '\0';
		return (dup);
	}
	return (NULL);
}
