/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_with_flags5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 14:04:42 by okres             #+#    #+#             */
/*   Updated: 2017/02/12 12:11:14 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	modif_buff_1(t_pf *st, char *spaces, char *zeros)
{
	if (st->specifier == 'p')
	{
		if (*(st->buffer) == '\0')
		{
			st->buffer = ft_strjoin("0x", st->buffer);
			if (ft_strlen(spaces) >= 2)
				spaces += 2;
			st->buffer = ft_strjoin(st->buffer, ft_strjoin(spaces, zeros));
		}
		else if (st->precision > st->width)
		{
			st->buffer = ft_strjoin(ft_strjoin(spaces, zeros), st->buffer);
			st->buffer = ft_strjoin("0x", st->buffer);
		}
		else
			st->buffer = ft_strjoin(ft_strjoin(spaces, zeros), st->buffer);
	}
	else
		st->buffer = ft_strjoin(ft_strjoin(spaces, zeros), st->buffer);
}

void	modif_buff_2(t_pf *st, char *spaces, char *zeros)
{
	if (st->precision > st->width)
	{
		if (spaces > 0)
			spaces++;
		st->ptr = ft_strjoin(ft_strjoin(spaces, zeros), st->buffer);
		st->buffer = ft_strjoin("-", st->ptr);
	}
	else
	{
		if (spaces > 0)
			spaces++;
		st->ptr = ft_strjoin("-", zeros);
		st->buffer = ft_strjoin(st->ptr, st->buffer);
		st->buffer = ft_strjoin(spaces, st->buffer);
	}
}

void	modif_buff_3(t_pf *st, char *spaces, char *zeros, long long znak)
{
	int i;

	i = 0;
	if (find(st->flag, '-') == 1 || find(st->flag, '0') == 1)
		mod_min(st, spaces, zeros, znak);
	if (find(st->flag, '+') == 1)
		mod_plus(st, spaces, zeros, znak);
	else if (find(st->flag, ' ') == 1)
		mod_sp(st, spaces, zeros, znak);
	if (find(st->flag, '#'))
		mod_sharp(st, zeros, spaces, i);
	if (st->flag[0] == '\0')
	{
		if (st->specifier != 'c' && st->specifier != 's' &&
				*(st->buffer) != '%' && st->specifier != 'C')
		{
			if (znak >= 0)
				modif_buff_1(st, spaces, zeros);
			else
				modif_buff_2(st, spaces, zeros);
		}
		else
			st->buffer = ft_strjoin(spaces, st->buffer);
	}
}

void	mod_plus2(t_pf *st, long long znak)
{
	char	*tmp;

	if (znak >= 0)
	{
		if (st->buffer[0] == '0' && find(st->flag, '0'))
		{
			if (*(st->last_buffer) != '0')
				(st->buffer)++;
			tmp = ft_strjoin("+", st->buffer);
		}
		else
		{
			if (st->buffer[ft_strlen(st->buffer) - 1] == ' ')
				st->buffer[ft_strlen(st->buffer) - 1] = '\0';
			tmp = ft_strjoin("+", st->buffer);
		}
		st->buffer = tmp;
	}
}
