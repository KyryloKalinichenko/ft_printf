/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:33:58 by kkalinic          #+#    #+#             */
/*   Updated: 2020/12/09 12:02:52 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*a;

	i = 0;
	if (s && f) 
	{
		a = malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (a == NULL)
			return (NULL);
		while (s[i])
		{
			a[i] = (*f)(i, s[i]);
			i++;
		}
		a[i] = '\0';
		return (a);
	}
	return (NULL);
}
