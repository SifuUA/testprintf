/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_with_flags1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:33:49 by okres             #+#    #+#             */
/*   Updated: 2017/02/12 16:11:19 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mod_zer(t_pf *st, char *spaces, long long znak)
{
	char	*tmp;

	if ((st->specifier == 'd' || st->specifier == 'i') && (st->precision == -1
				|| st->precision == 0 || st->precision ==
				(int)ft_strlen(st->buffer)) && st->point == 1)
	{
		st->buffer = ft_strjoin(spaces, st->buffer);
		return ;
	}
	if (find(st->flag, '0') == 1)
	{
		if (st->precision < (int)ft_strlen(st->buffer) && st->precision != 0)
			tmp = ft_strjoin(st->ptr, st->buffer);
		else if (st->precision > (int)ft_strlen(st->buffer) &&
				st->precision < st->width)
			tmp = ft_strjoin(st->ptr, st->buffer);
		else
		{
			mod_zer_2(st);
			tmp = ft_strjoin(st->ptr, st->buffer);
		}
		st->buffer = tmp;
		mod_zer_1(st, znak, tmp);
	}
}

void	mod_min(t_pf *st, char *spaces, char *zeros, long long znak)
{
	char	*tmp;
	int		i;

	i = 0;
	if (find(st->flag, '-') == 1)
	{
		if (st->width >= st->precision && st->specifier != 'p')
		{
			tmp = ft_strjoin(st->buffer, spaces);
			st->buffer = ft_strjoin(zeros, tmp);
			if (znak < 0)
			{
				i = ft_strlen(st->buffer);
				if (st->buffer[i - 1] == ' ')
					st->buffer[i - 1] = '\0';
				tmp = ft_strjoin("-", st->buffer);
				st->buffer = tmp;
			}
		}
		else
			mod_min_1(st, znak);
	}
	else
		mod_zer(st, spaces, znak);
}

void	mod_sp1(t_pf *st, char *spaces, char *zeros, long long znak)
{
	char	*tmp;
	char	*tmp1;

	if (st->precision >= st->width)
	{
		if (znak >= 0)
			tmp = ft_strjoin(" ", st->buffer);
		else
			tmp = ft_strjoin("-", st->buffer);
	}
	else
	{
		tmp1 = ft_strjoin(spaces, zeros);
		tmp = ft_strjoin(tmp1, st->buffer);
	}
	st->buffer = tmp;
}

void	mod_sp(t_pf *st, char *spaces, char *zeros, long long znak)
{
	char	*tmp;
	int		i;

	i = 0;
	if (st->specifier == '\0' || st->specifier == '%')
		return ;
	if (st->specifier == 'u' || st->specifier == 'c' || st->specifier == 'p'
			|| st->specifier == 's' || st->specifier == 'S' || st->specifier == 'o'
			|| st->specifier == 'O' || st->specifier == 'x' || st->specifier == 'X')
		return ;
	if (find(st->flag, '-') == 1 || find(st->flag, '0') == 1)
	{
		if (znak > 0)
		{
			if (st->buffer[0] == ' ')
				return ;
			tmp = ft_strjoin(" ", st->buffer);
			i = ft_strlen(tmp);
			if (tmp[i - 1] == ' ')
				tmp[i - 1] = '\0';
			st->buffer = tmp;
		}
	}
	else
		mod_sp2(st, spaces, zeros, znak);
}

void	modif_buff(t_pf *st)
{
	char		a;
	char		*spaces;
	char		*zeros;
	long long	znak;

	a = '\0';
	if (find(st->buffer, '-') && st->specifier != 'c' && st->specifier != 'C')
	{
		(st->buffer) += 1;
		znak = -1;
	}
	if ((st->specifier == 'c' || st->specifier == 'C') && (*st->buffer) == '\0' && st->width == 0)
		return ;
	if ((st->specifier == '%' || (*st->buffer) == '%')
			&& st->specifier != 'c' && st->specifier != 'C' && *(st->size) == '\0' && *(st->flag) == '\0')
	{
		if (find_char(st->str, '%'))
			st->buffer = "%";
		else
			st->buffer = "\0";
	}
	spaces = get_space(st);
	zeros = get_zero(st, a);
	st->ptr = ft_strjoin(spaces, zeros);
	modif_buff_3(st, spaces, zeros, znak);
}
