/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:41:25 by kkalinic          #+#    #+#             */
/*   Updated: 2020/11/20 13:14:07 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			a[i] = (*f)(s[i]);
			i++;
		}
		a[i] = '\0';
		return (a);
	}
	return (NULL);
}
