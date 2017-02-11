/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analize3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 21:15:45 by okres             #+#    #+#             */
/*   Updated: 2017/02/11 14:33:27 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_11(char *size, va_list vl, char **buffer, t_pf *st)
{
	long long int i;

	i = ft_strlen(size);
	if (i > 2)
		size = ft_strsub(size, i - 2, 2);
	if (size[0] == '\0')
	{
		i = va_arg(vl, long long int);
		if (i == 0 && st->point == 1)
			*buffer = "";
		else
			*buffer = ft_itoa_base(i, 10);
	}
	else if (size[0] == 'h' && size[1] == 'h')
		*buffer = ft_itoa_base((unsigned short int)va_arg(vl, int), 10);
	else if (size[0] == 'h')
		*buffer = ft_itoa_base((short int)(va_arg(vl, int)), 10);
	else if (size[0] == 'l')
		*buffer = ft_itoa_base(va_arg(vl, long long int), 10);
	else if (size[0] == 'j')
		*buffer = ft_itoa_base(va_arg(vl, intmax_t), 10);
	else if (size[0] == 'z' || size[0] == 't')
		*buffer = ft_itoa_base(va_arg(vl, long long int), 10);
}

void	f_12(char *size, va_list vl, char **buffer, t_pf *st)
{
	int i;

	i = 0;
	i = ft_strlen(size);
	if (i > 2)
		size = ft_strsub(size, i - 2, 2);
	if (size[0] == '\0')
	{
		i = va_arg(vl, int);
		if (i == 0 && st->point == 1)
			*buffer = "";
		else
			*buffer = ft_itoa_base(i, 10);
	}
	else if (size[0] == 'h' && size[1] == 'h')
		*buffer = ft_itoa_base((signed char)va_arg(vl, int), 10);
	else if (size[0] == 'h')
		*buffer = ft_itoa_base((short int)(va_arg(vl, int)), 10);
	else if (size[0] == 'l')
		*buffer = ft_itoa_base(va_arg(vl, long long int), 10);
	else if (size[0] == 'j')
		*buffer = ft_itoa_base(va_arg(vl, intmax_t), 10);
	else if (size[0] == 'z' || size[0] == 't')
		*buffer = ft_itoa_base(va_arg(vl, long long int), 10);
}

void	f_13(char *size, va_list vl, char **buffer, t_pf *st)
{
	unsigned int	i;
	unsigned char	c;

	i = 0;
	if (size[0] == '\0')
	{
		i = va_arg(vl, unsigned int);
		if (i == 0 && st->point == 1)
			*buffer = "";
		else
			*buffer = ft_itoa_base_unsign(i, 10);
	}
	else if (size[0] == 'h' && size[1] == 'h')
	{
		c = (va_arg(vl, int));
		*buffer = ft_itoa_base(c, 10);
	}
	else if (size[0] == 'h')
		*buffer = ft_itoa_base_unsign((unsigned short int)(va_arg(vl, int)),
				10);
	else if (size[0] == 'l' || size[0] == 'j' || size[0] == 'z' || size[0]
			== 't')
		*buffer = ft_itoa_base_unsign(va_arg(vl, unsigned long long int),
				10);
}

void	f_14(char *size, va_list vl, char **buffer, t_pf *st)
{
	unsigned int i;

	i = 0;
	if (size[0] == '\0')
	{
		i = va_arg(vl, unsigned int);
		if (i == 0 && st->point == 1)
			*buffer = "";
		else
			*buffer = ft_itoa_base(i, 8);
	}
	else if (size[0] == 'h' && size[1] == 'h')
		*buffer = ft_itoa_base_unsign((unsigned char)(va_arg(vl, int)), 8);
	else if (size[0] == 'h')
		*buffer = ft_itoa_base((unsigned short int)(va_arg(vl, int)), 8);
	else if (size[0] == 'l' || size[0] == 'j' || size[0] == 'z' || size[0]
			== 't')
		*buffer = ft_itoa_base_unsign(va_arg(vl, unsigned long int), 8);
}

void	f_15(char *size, va_list vl, char **buffer)
{
	unsigned int i;

	i = 0;
	if (size[0] == '\0')
	{
		i = va_arg(vl, unsigned int);
		*buffer = ft_itoa_base(i, 8);
	}
	else if (size[0] == 'h' && size[1] == 'h')
		*buffer = ft_itoa_base_unsign((unsigned short int)(va_arg(vl, int)), 8);
	else if (size[0] == 'h')
		*buffer = ft_itoa_base((unsigned short int)(va_arg(vl, int)), 8);
	else if (size[0] == 'l' || size[0] == 'j' || size[0] == 'z' || size[0]
			== 't')
		*buffer = ft_itoa_base_unsign(va_arg(vl, unsigned long int), 8);
}
