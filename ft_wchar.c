/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 12:54:49 by kkalinic          #+#    #+#             */
/*   Updated: 2021/02/28 12:54:51 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	wchar_to_mb_part_2(char *buffer, wchar_t code_point)
{
	if (code_point <= 0xffff)
	{
		buffer[2] = 0b10000000 | (code_point & 0b111111);
		buffer[1] = 0b10000000 | ((code_point >> 6) & 0b111111);
		buffer[0] = 0b11100000 | (code_point >> 12);
		return (3);
	}
	if (code_point <= 0x10ffff)
	{
		buffer[3] = 0b10000000 | (code_point & 0b111111);
		buffer[2] = 0b10000000 | ((code_point >> 6) & 0b111111);
		buffer[1] = 0b10000000 | ((code_point >> 12) & 0b111111);
		buffer[0] = 0b11110000 | (code_point >> 18);
		return (4);
	}
	return (0);
}

int			ft_wchar_to_mb(char *buffer, wchar_t code_point)
{
	if (code_point < 0)
		return (0);
	if (code_point <= 0x007f)
	{
		buffer[0] = code_point;
		return (1);
	}
	if (code_point <= 0x07ff)
	{
		buffer[1] = 0b10000000 | (code_point & 0b111111);
		buffer[0] = 0b11000000 | (code_point >> 6);
		return (2);
	}
	return (wchar_to_mb_part_2(buffer, code_point));
}

void		ft_wchar_str(wchar_t *src, t_key *v)
{
	char	buff[5];
	int		size;

	buff[4] = '\0';
	while (*src && (v->perc_f == 0 || 0 < v->perc_q))
	{
		size = ft_wchar_to_mb(buff, *src++);
		write(1, buff, size);
		v->perc_q -= size;
		v->ctr += size;
	}
}
