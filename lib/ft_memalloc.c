/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:17:13 by kkalinic          #+#    #+#             */
/*   Updated: 2020/11/23 10:43:58 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *a;

	a = malloc(sizeof(size));
	if (a == NULL || size >= 9223372036854775807L)
		return (NULL);
	ft_bzero(a, size);
	return (a);
}
