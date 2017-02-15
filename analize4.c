/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analize4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 21:54:56 by okres             #+#    #+#             */
/*   Updated: 2017/02/15 21:54:58 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_16(char *size, va_list vl, char **buffer, t_pf *st)
{
	unsigned int	i;
	unsigned char	c;

	i = 0;
	if (size[0] == '\0')
	{
		i = va_arg(vl, unsigned int);
		if (i == 0 && (find(st->flag, '#') || st->point == 1))
			*(st->buffer) = '\0';
		else
			*buffer = ft_itoa_base_low(i, 16);
	}
	else if (size[0] == 'h' && size[1] == 'h')
	{
		c = va_arg(vl, int);
		*buffer = ft_itoa_base_low(c, 16);
	}
	else if (size[0] == 'h')
		*buffer = ft_itoa_base_low((unsigned short int)(va_arg(vl, int)), 16);
	else if (size[0] == 'j')
		*buffer = ft_itoa_base_unsign_low(va_arg(vl, uintmax_t), 16);
	else if (size[0] == 'l' || size[0] == 'j' || size[0] == 'z' || size[0]
			== 't')
		*buffer = ft_itoa_base_unsign_low(va_arg(vl, unsigned long long int),
				16);
}

char	*bit_move1(int i)
{
	unsigned char	z[4];

	z[0] = (i >> 12) + 224;
	z[1] = i >> 6;
	z[1] = z[1] << 2;
	z[1] = z[1] >> 2;
	z[1] += 128;
	z[2] = i << 2;
	z[2] = (z[2] >> 2) + 128;
	z[3] = 0;
	return (ft_strdup((char *)z));
}

char	*bit_move(int i)
{
	unsigned char	s[3];
	char			*res;

	res = ft_strnew(3);
	if (i < 128)
		*res = i;
	else if (i < 2048)
	{
		s[0] = (i >> 6) + 192;
		s[1] = i << 2;
		s[1] = (s[1] >> 2) + 128;
		s[2] = 0;
		res = ft_strdup((char *)s);
	}
	else if (i > 2048)
		res = bit_move1(i);
	return (res);
}

void	f_19(va_list vl, t_pf *st)
{
	int		j;
	int		tmp;
	int		*i;

	j = 0;
	tmp = 0;
	i = va_arg(vl, int *);
	while (i[j])
	{
		tmp = i[j];
		st->buffer = ft_strjoin(st->buffer, bit_move(tmp));
		j++;
	}
}

void	f_18(va_list vl, t_pf *st)
{
	st->buffer = ft_itoa_base_low(va_arg(vl, int), 2);
}
