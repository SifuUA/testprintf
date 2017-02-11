/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_with_flags6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 14:06:17 by okres             #+#    #+#             */
/*   Updated: 2017/02/11 14:50:47 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		mod_sharp_h1(t_pf *st)
{
	char	*tmp;
	int		i;

	i = 0;
	if (find(st->flag, '-'))
	{
		if (st->specifier == 'x')
			tmp = ft_strjoin("0x", st->buffer);
		else
			tmp = ft_strjoin("0X", st->buffer);
		i = ft_strlen(tmp);
		st->buffer = tmp;
		if (st->buffer[i - 1] == ' ')
			st->buffer[i - 1] = '\0';
		if (st->buffer[i - 2] == ' ')
			st->buffer[i - 2] = '\0';
	}
	if (find(st->flag, ' '))
		mod_sharp3(st, tmp, i);
	if (find(st->flag, '0'))
		mod_sharp4(st, i);
}

void		mod_sharp_h2(t_pf *st, char *spaces)
{
	char	*tmp;

	if (st->specifier == 'x')
		tmp = ft_strjoin("0x", st->buffer);
	else
		tmp = ft_strjoin("0X", st->buffer);
	spaces += 2;
	st->buffer = ft_strjoin(spaces, tmp);
}

void		mod_sharp_h3(t_pf *st, char *zeros)
{
	char	*tmp;

	tmp = ft_strjoin(zeros, st->buffer);
	if (st->specifier == 'x')
		st->buffer = ft_strjoin("0x", tmp);
	else
		st->buffer = ft_strjoin("0X", tmp);
}

void		mod_sharp_h4(t_pf *st, char *zeros, char *spaces)
{
	char	*tmp;

	tmp = ft_strjoin(zeros, st->buffer);
	if (st->specifier == 'x')
		st->buffer = ft_strjoin("0x", tmp);
	else
		st->buffer = ft_strjoin("0X", tmp);
	spaces += 2;
	tmp = ft_strjoin(spaces, st->buffer);
	st->buffer = tmp;
}

void		mod_sharp_h5(t_pf *st)
{
	if (st->specifier == 'x')
		st->buffer = ft_strjoin("0x", st->buffer);
	else
		st->buffer = ft_strjoin("0X", st->buffer);
}
