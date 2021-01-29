/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:52:55 by kkalinic          #+#    #+#             */
/*   Updated: 2020/12/09 11:49:30 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *tmp;

	if (lst && (*lst != NULL))
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			ft_lstdelone(*lst, (*del));
			(*lst) = tmp;
		}
	}
}
