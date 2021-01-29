/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:30:58 by kkalinic          #+#    #+#             */
/*   Updated: 2020/11/23 10:47:35 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *a;

	a = malloc(sizeof(char) * (size + 1));
	if (a == NULL)
		return (NULL);
	ft_bzero(a, size + 1);
	a[size] = '\0';
	return (a);
}
