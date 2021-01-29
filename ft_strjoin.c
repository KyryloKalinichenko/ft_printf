/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:46:33 by kkalinic          #+#    #+#             */
/*   Updated: 2020/12/09 11:52:22 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *a;

	if (s1 && s2)
	{
		a = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (a == NULL)
			return (NULL);
		a[(ft_strlen(s1) + ft_strlen(s2))] = '\0';
		a = ft_strncpy(a, s1, (ft_strlen(s1) + 1));
		a = ft_strcat(a, s2);
		return (a);
	}
	return (NULL);
}
