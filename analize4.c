/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analize4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 21:20:07 by okres             #+#    #+#             */
/*   Updated: 2017/02/10 21:20:47 by okres            ###   ########.fr       */
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
		if (i == 0 && st->point == 1)
			*buffer = "";
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
