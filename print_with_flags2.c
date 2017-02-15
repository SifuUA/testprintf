/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_with_flags2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:48:42 by okres             #+#    #+#             */
/*   Updated: 2017/02/15 22:10:51 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mod_plus1(t_pf *st, char *spaces, char *zeros, long long znak)
{
	char	*tmp;
	char	*tmp1;

	if (zeros != NULL && ft_strlen(zeros) > 0)
	{
		if (znak >= 0)
			tmp = ft_strjoin("+", zeros);
		else
			tmp = ft_strjoin("-", zeros);
		ft_strdel(&zeros);
		spaces++;
		tmp1 = ft_strjoin(spaces, tmp);
		ft_strdel(&tmp);
		tmp = ft_strjoin(tmp1, st->buffer);
		ft_strdel(&tmp1);
		st->buffer = tmp;
	}
	else
	{
		if (znak >= 0)
			tmp = ft_strjoin("+", st->buffer);
		else
			tmp = ft_strjoin("-", st->buffer);
		st->buffer = tmp;
	}
}

void	mod_plus(t_pf *st, char *spaces, char *zeros, long long znak)
{
	char	*tmp;

	if (find(st->flag, '-') || find(st->flag, '0'))
		mod_plus2(st, znak);
	else if (ft_strlen(spaces) > 0 && zeros == NULL && spaces != NULL)
	{
		if (znak >= 0)
			tmp = ft_strjoin("+", st->buffer);
		else
			tmp = ft_strjoin("-", st->buffer);
		st->ptr++;
		st->buffer = ft_strjoin(st->ptr, tmp);
		ft_strdel(&(tmp));
	}
	else
		mod_plus1(st, spaces, zeros, znak);
	if (st->specifier == 'u' || st->specifier == 'x' || st->specifier == 'X'
			|| st->specifier == 'o' || st->specifier == 'p' || st->specifier
			== 'O' || st->specifier == 's' || st->specifier == 'S')
		(st->buffer)++;
}

void	mod_sharp1(t_pf *st, char *tmp, int i)
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
	else
	{
		while (st->buffer[i] == ' ')
			i++;
		if (i > 0 && st->buffer[i] != '0')
			st->buffer[i - 1] = '0';
		else if (st->buffer[i] != '0')
			st->buffer = ft_strjoin("0", st->buffer);
		else if (st->precision > st->width)
			(st->buffer)++;
	}
}

void	mod_sharp(t_pf *st, char *zeros, char *spaces, int i)
{
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (st->specifier == 'd' || st->specifier == 'D')
		return ;
	if (st->specifier != 'x' && st->specifier != 'X')
	{
		if (find(st->flag, '-') || find(st->flag, ' ') || find(st->flag, '0'))
		{
			if (find(st->flag, '-'))
			{
				if (st->buffer[0] != '0' && !find(st->flag, ' '))
					help_sharp(st);
			}
			if (find(st->flag, ' '))
				mod_sharp1(st, tmp, i);
		}
		else
			mod_sharp5(st, zeros, spaces);
	}
	else
		mod_sharp2(st, zeros, spaces);
}

void	mod_sharp5(t_pf *st, char *zeros, char *spaces)
{
	char	*tmp;

	if (st->width > (int)ft_strlen(st->buffer) && zeros == NULL)
	{
		tmp = ft_strjoin("0", st->buffer);
		spaces++;
		st->buffer = ft_strjoin(spaces, tmp);
	}
	else if (st->precision > st->width)
	{
		tmp = ft_strjoin(zeros, st->buffer);
		st->buffer = tmp;
	}
	else if (st->width > st->precision)
	{
		tmp = ft_strjoin(spaces, zeros);
		st->buffer = ft_strjoin(tmp, st->buffer);
	}
	else if (st->specifier != 'x' && st->specifier != 'X')
		st->buffer = ft_strjoin("0", st->buffer);
}
