/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:29:47 by kkalinic          #+#    #+#             */
/*   Updated: 2021/02/25 11:29:49 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_skipnum(char *s)
{
	int i;

	i = -1;
	if (s)
	{
		while (ft_isdigit(s[++i]))
			;
		return (&s[i]);
	}
	return (NULL);
}

char	*ft_skipf(char *s)
{
	while (s && ft_isforpar(s))
		s++;
	return (s);
}

char	*ft_skipstar(char *s)
{
	if (s && *s == '*')
		s++;
	return (s);
}

char	*ft_skipall(char *s)
{
	if (s)
	{
		while (s && (ft_isdigit(*s) || ft_isforpar(s)))
			s++;
	}
	return (s);
}
