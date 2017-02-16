/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dub_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:40:19 by okres             #+#    #+#             */
/*   Updated: 2017/02/16 16:06:04 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_4_dop_1(t_pf *st)
{
	int	tmp;

	tmp = 0;
	if (ft_strlen(st->dec) > 6)
		st->dec[6] = '\0';
	st->i = (int)ft_strlen(st->dec);
	st->buffer = ft_strcat(st->buffer, st->dec);
	tmp = st->precision > st->i ? st->precision - st->i : 6 - st->i;
	while (tmp > 0)
	{
		st->buffer = ft_strjoin(st->buffer, "0");
		tmp--;
	}
}

void	f_4_dop(t_pf *st)
{
	int tmp;

	tmp = 0;
	if (st->precision > 0 && st->precision > st->width)
	{
		st->i = (int)ft_strlen(st->dec);
		st->buffer = ft_strcat(st->buffer, st->dec);
		tmp = st->precision > st->i ? st->precision - st->i : 6 - st->i;
		while (tmp > 0)
		{
			st->buffer = ft_strjoin(st->buffer, "0");
			tmp--;
		}
	}
	else
		f_4_dop_1(st);
}

size_t	all_len(double num)
{
	size_t	tmp;

	if (num < 0)
		num *= -1;
	tmp = num;
	while (num - tmp > 0)
	{
		num = num * 10;
		tmp = num;
	}
	return (tmp);
}

size_t	len_first(long long num)
{
	size_t		tmp;
	size_t		len;

	len = 0;
	if (num < 0)
		num *= -1;
	tmp = num;
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

void	f_4(char *size, va_list vl, char **buffer, t_pf *st)
{
	double		tmp;
	long long	value;

	if (st->specifier == 'f' || st->specifier == 'F')
	{
		if (size[0] == '\0' || size[0] == 'L')
		{
			tmp = (double)va_arg(vl, double);
			st->znak1 = tmp < 0 ? -1 : 1;
			value = tmp;
			*buffer = ft_itoa_mod(value, st->znak1);
			value = len_first(value);
			st->dec = ft_itoa_base_unsign(all_len(tmp), 10);
			st->dec += value;
			if (st->precision >= 0 && st->precision <= (int)ft_strlen(st->dec))
			{
				st->dec[st->precision] = '\0';
				st->buffer = ft_strcat(st->buffer, st->dec);
			}
			else
				f_4_dop(st);
		}
	}
}
