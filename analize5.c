/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analize5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:25:25 by okres             #+#    #+#             */
/*   Updated: 2017/02/15 21:15:06 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_17(va_list vl, t_pf *st)
{
 /*   static size_t		*i;
    signed char			*c;
    int					a;
    size_t				**ptr;
    
    a = ft_strlen(st->res);
    if (st->size[0] == 'h' && st->size[1] == 'h')
    {
        c = (signed char *)va_arg(vl, void*);
        *c = a;
    }
    else
    {
        ptr = &i;
        i = (size_t *)va_arg(vl, void*);
        *i = a;
    }
    if (st->buffer)
        free(st->buffer);
*/
	char	*ptr;
	size_t	len;
	
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
