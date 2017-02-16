/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 21:51:08 by okres             #+#    #+#             */
/*   Updated: 2017/02/16 15:01:36 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list			vl;
	static t_pf		*st;

	va_start(vl, format);
	st = (t_pf *)malloc(sizeof(t_pf));
	memory_allocate(st);
	st->str = ft_strdup((char *)format);
	ft_printf_1(st, vl);
	write(1, st->res, (int)ft_strlen(st->res) + st->uk);
	return (ft_strlen(st->res) + st->uk);
}

void	ft_printf_2(t_pf *st)
{
	int	j;

	j = lentoc(st->str, '%');
	st->tmp = ft_strsub(st->str, 0, j);
	st->res = ft_strjoin(st->res, st->tmp);
	(st->str) += j;
}

void	ft_printf_1(t_pf *st, va_list vl)
{
	int		j;

	j = 0;
	while (*(st->str))
	{
		if (*(st->str) == '%')
		{
			(st->str)++;
			j = len_to_spec(st->str);
			st->tmp = ft_strdup(st->str);
			st->str[j] = '\0';
			if (fill_struct(st, vl) == 0)
				modif_buff(st);
			if (*(st->buffer) == '\0' && ft_strlen(st->tmp) == 1 &&
					st->specifier == '\0' && *(st->flag) == '\0')
				st->str = st->tmp;
			else
				st->str = st->tmp + j;
			st->res = ft_strjoin(st->res, st->buffer);
			free_s(st);
		}
		else
			ft_printf_2(st);
	}
}
