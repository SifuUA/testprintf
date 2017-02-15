/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analize5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 22:32:40 by okres             #+#    #+#             */
/*   Updated: 2017/02/15 22:32:43 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_17(va_list vl, t_pf *st)
{
	char		*ptr;
	size_t		len;

	len = ft_strlen(st->res);
	ptr = (char*)va_arg(vl, void*);
	if (st->size[0] == '\0')
		*ptr = (int)len;
	else if (st->size[0] == 'h' && st->size[1] == 'h')
		*ptr = (signed char)len;
	else if (st->size[0] == 'h')
		*ptr = (short int)len;
	else if (st->size[0] == 'l')
		*ptr = (long)len;
	else if (st->size[0] == 'l' && st->size[1] == 'l')
		*ptr = (long long)len;
	else
		*ptr = (size_t)len;
	if (st->buffer)
		free(st->buffer);
}
