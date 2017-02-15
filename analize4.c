/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analize4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 21:20:07 by okres             #+#    #+#             */
/*   Updated: 2017/02/15 15:05:09 by okres            ###   ########.fr       */
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

void	f_17(va_list vl, t_pf *st)
{
//	size_t		*i;
	signed char	*c;
	int			a;
	
	a = ft_strlen(st->res);
	if (st->size[0] == 'h' && st->size[1] == 'h')
	{
		c = (signed char *)va_arg(vl, void*);
		*c = a;
	}
	else
	{
		st->n = (size_t *)va_arg(vl, void*);
		*(st->n) = a;
	}
//	if (st->buffer)
//		free(st->buffer);
}

char	*bit_move(int i)
{
	unsigned char	s[3];
	unsigned char	z[4];
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
	{
		z[0] = (i >> 12) + 224;
		z[1] = i >> 6;
		z[1] = z[1] << 2;
		z[1] = z[1] >> 2;
	   	z[1] += 128;
		z[2] = i << 2;
		z[2] = (z[2] >> 2) + 128;
		z[3] = 0;
		res = ft_strdup((char *)z);
	}
	return (res);
}

void	f_18(va_list vl, t_pf *st)
{
	st->buffer = ft_itoa_base_low(va_arg(vl, int), 2);
}

/*void	f_19(va_list vl, t_pf *st)
{
	int		j;
	int		tmp;
	int		*i;
	
	j = 0;
	tmp = 0;
	i = (int *)va_arg(vl, char *);
	while (i[j])
	{
		tmp = i[j];
		st->buffer = ft_strjoin(st->buffer, bit_move(tmp));
		j++;
	}
}*/
