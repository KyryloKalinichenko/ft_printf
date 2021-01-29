/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:57:30 by kkalinic          #+#    #+#             */
/*   Updated: 2020/12/09 11:25:59 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *cont)
{
	t_list	*temp;
	void	*ver;

	ver = cont;
	if (!(temp = malloc(sizeof(t_list))))
		return (NULL);
	temp->content = cont;
	temp->next = NULL;
	return (temp);
}
