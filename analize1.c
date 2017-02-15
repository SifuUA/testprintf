/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analize1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 21:08:23 by okres             #+#    #+#             */
/*   Updated: 2017/02/15 23:05:15 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_1(char *size, va_list vl, char **buffer, t_pf *st)
{
	int i;

	i = 0;
	if (st->specifier == 'd' || st->specifier == 'D' || st->specifier == 'i')
	{
		if (st->specifier == 'D')
			f_11(size, vl, buffer, st);
		else
			f_12(size, vl, buffer, st);
	}
	else if (st->specifier == 'u' || st->specifier == 'U' ||
			st->specifier == 'o' || st->specifier == 'O' || st->specifier == 'x'
			|| st->specifier == 'X')
		f_2(size, vl, buffer, st);
	else if (st->specifier == 'f' || st->specifier == 'F' ||
			st->specifier == 'e' || st->specifier == 'E' || st->specifier == 'g'
			|| st->specifier == 'G' || st->specifier == 'a' ||
			st->specifier == 'A')
		f_4(size, vl, buffer, st);
	else if (st->specifier == 'c' || st->specifier == 'C' ||
			st->specifier == 's' || st->specifier == 'S')
		f_7(size, vl, buffer, st);
	else if (st->specifier == 'p' || st->specifier == 'n' ||
			st->specifier == 'b')
		f_8(vl, buffer, st);
}

void	f_2(char *size, va_list vl, char **buffer, t_pf *st)
{
	if (st->specifier == 'u')
		f_13(size, vl, buffer, st);
	else if (st->specifier == 'U')
		*buffer = ft_itoa_base_unsign(va_arg(vl, unsigned long long int), 10);
	else if (st->specifier == 'o')
		f_14(size, vl, buffer, st);
	else if (st->specifier == 'O')
		f_15(size, vl, buffer, st);
	else
		f_3(size, vl, buffer, st);
}

void	f_3(char *size, va_list vl, char **buffer, t_pf *st)
{
	unsigned int i;

	i = 0;
	if (st->specifier == 'x')
		f_16(size, vl, buffer, st);
	else if (st->specifier == 'X')
	{
		if (size[0] == '\0')
		{
			i = va_arg(vl, unsigned int);
			if (i == 0 && (find(st->flag, '#') || st->point == 1))
				*(st->buffer) = '\0';
			else
				*buffer = ft_itoa_base(i, 16);
		}
		else if (size[0] == 'h' && size[1] == 'h')
			*buffer = ft_itoa_base_unsign((unsigned char)(va_arg(vl, int)), 16);
		else if (size[0] == 'h')
			*buffer = ft_itoa_base((unsigned short int)(va_arg(vl, int)), 16);
		else if (size[0] == 'l' || size[0] == 'j' || size[0] == 'z' ||
				size[0] == 't')
			*buffer = ft_itoa_base_unsign(va_arg(vl, unsigned long int), 16);
	}
}

void	f_4_dop(t_pf *st, char *ptr)
{
	int tmp;

	tmp = 0;
	st->i = (int)ft_strlen(st->float_dec);
	st->buffer = ft_strcat(ptr, st->float_dec);
		tmp = st->precision > st->i ? st->precision - st->i : 6 - st->i;
		while (tmp > 0)
		{
			st->buffer = ft_strjoin(st->buffer, "0");
			tmp--;
		}
}

void	f_4(char *size, va_list vl, char **buffer, t_pf *st)
{
	double		tmp;
	size_t		value;
	char		*ptr;
	
	if (st->specifier == 'f' || st->specifier == 'F')
	{
		if (size[0] == '\0')
		{
			tmp = (double)va_arg(vl, double);
			value = tmp;
			*buffer = ft_itoa_mod(value);
			ptr = *buffer;
			st->float_dec = ft_itoa_base((tmp * ft_pow(10, num_len(tmp))), 10);
			st->float_dec += (ft_strlen(ptr) - 1);
			if (st->precision >= 0 && st->precision <= (int)ft_strlen(st->float_dec))
			{
				st->float_dec[st->precision] = '\0';
				st->buffer = ft_strcat(ptr, st->float_dec);
			}
			else
				f_4_dop(st, ptr);
		}
	}
}
