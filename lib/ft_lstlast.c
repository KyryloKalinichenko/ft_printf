/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:56:36 by kkalinic          #+#    #+#             */
/*   Updated: 2020/12/09 11:27:12 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *tmp;

	if (lst)
	{
		tmp = lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		return (tmp);
	}
	return (NULL);
}
