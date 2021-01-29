/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:11:12 by kkalinic          #+#    #+#             */
/*   Updated: 2020/12/09 11:54:27 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_set(char c, char const *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s, char const *set)
{
	unsigned int	i;
	unsigned int	b;
	char			*a;

	if (!s || !set)
		return (NULL);
	i = 0;
	b = (ft_strlen(s + 1));
	while (s[i] && ft_set(s[i], set))
		i++;
	if (i == ft_strlen(s))
		return (ft_calloc(1, 1));
	while (s[b] && ft_set(s[b], set))
		b--;
	if (!(a = ft_substr(s, i, (b - i + 1))))
		return (NULL);
	return (a);
}
