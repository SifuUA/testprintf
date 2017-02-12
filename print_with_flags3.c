/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_with_flags3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 14:01:54 by okres             #+#    #+#             */
/*   Updated: 2017/02/12 12:26:23 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		mod_sharp4(t_pf *st, int i)
{
	i = 0;
	if (st->buffer[i] == '0')
	{
		st->buffer[i + 1] = 'x';
	}
}

void		mod_sharp3(t_pf *st, char *tmp, int i)
{
	if (find(st->flag, '-'))
	{
		(st->buffer)++;
		if (st->width > st->precision && st->precision != 0)
		{
			tmp = ft_strjoin(st->buffer, " ");
			st->buffer = tmp;
		}
		if (st->buffer[0] != '0')
		{
			tmp = ft_strjoin("0", st->buffer);
			st->buffer = tmp;
		}
	}
	{
		while (st->buffer[i] == ' ')
			i++;
		if (i > 0 && st->buffer[i] != '0')
			st->buffer[i - 1] = '0';
		else if (st->buffer[i] != '0')
			st->buffer = ft_strjoin("0x", st->buffer);
		else if (st->precision > st->width)
			(st->buffer)++;
	}
}

void		mod_sharp2(t_pf *st, char *zeros, char *spaces)
{
	if (st->specifier == 'x' || st->specifier == 'X')
	{
		if (*(st->buffer) == '\0' && st->point == 1)
			return ;
		if (ft_atoi(st->buffer) == 0 && st->point != 1)
		{
			st->buffer = "0";
			return ;
		}
		if (find(st->flag, '-') || find(st->flag, ' ') || find(st->flag, '0'))
			mod_sharp_h1(st);
		else
		{
			if (st->width > (int)ft_strlen(st->buffer) && zeros == NULL)
				mod_sharp_h2(st, spaces);
			else if (st->precision > st->width)
				mod_sharp_h3(st, zeros);
			else if (st->width > st->precision)
				mod_sharp_h4(st, zeros, spaces);
			else
				mod_sharp_h5(st);
		}
	}
}
