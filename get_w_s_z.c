/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_w_s_z.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 22:00:31 by okres             #+#    #+#             */
/*   Updated: 2017/02/12 15:43:57 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_width(t_pf *st)
{
	int w_str;

	if ((st->specifier == 's' || st->specifier == 'c' || st->specifier == 'C' ||
				*(st->buffer) == '%') && st->width > (int)ft_strlen(st->buffer))
		w_str = st->width;
	else if (st->width > st->precision && st->width >
			(int)ft_strlen(st->buffer))
		w_str = st->width;
	else if (st->precision > st->width && st->precision >
			(int)ft_strlen(st->buffer) && *(st->buffer) != '%')
		w_str = st->precision;
	else
		w_str = ft_strlen(st->buffer);
	return (w_str);
}

char	*get_zero(t_pf *st, char a)
{
	int		space_c;
	int		zero_c;
	char	*n_str;
	int		i;

	i = 0;
	n_str = NULL;
	if (st->precision == -1)
		st->precision = 0;
	if (st->precision > (int)ft_strlen(st->buffer))
		space_c = get_width(st) - st->precision;
	else
		space_c = get_width(st) - ft_strlen(st->buffer);
	zero_c = get_width(st) - (space_c + ft_strlen(st->buffer));
	if (zero_c > 0)
	{
		n_str = ft_strnew(zero_c);
		a = (st->specifier == 'c' || st->specifier == 's' || st->specifier == 'C') ? ' ' : '0';
		while (i < zero_c)
		{
			n_str[i] = a;
			i++;
		}
	}
	return (n_str);
}

int		help_g(t_pf *st)
{
	int		i;
	int		j;
	int		count;

	j = 0;
	count = 0;
	i = get_width(st) - ft_strlen(st->buffer);
	while (st->buffer[j])
	{
		if (ft_isalpha(st->buffer[j]))
			count++;
		j++;
	}
	if (i > 0 && st->precision == 0 && st->specifier == '\0'
			&& count > 0)
		i += count;
	return (i);

}

char	*get_space(t_pf *st)
{
	int		space_c;
	char	*n_str;
	int		i;

	i = 0;
	n_str = NULL;
	if (st->precision == -1)
		st->precision = 0;
	if ((st->specifier == 'c' || st->specifier == 'C') && st->precision != 0)
		return (n_str);
	if (st->precision > (int)ft_strlen(st->buffer) && st->specifier != 's' &&
			st->specifier != 'c' && st->specifier != 'C' && *(st->buffer) != '%')
		space_c = get_width(st) - st->precision;
	else
		space_c = help_g(st);
	n_str = ft_strnew(space_c);
	if (st->specifier == 'c' && *(st->buffer) == '\0')
		space_c--;
	while (i < space_c)
	{
		n_str[i] = ' ';
		i++;
	}
	return (n_str);
}
