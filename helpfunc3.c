/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpfunc3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 22:30:21 by okres             #+#    #+#             */
/*   Updated: 2017/02/15 22:30:29 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_s(t_pf *st)
{
	st->width = 0;
	st->precision = -1;
	ft_bzero(st->flag, ft_strlen(st->flag));
	st->znak = 0;
	ft_bzero(st->size, ft_strlen(st->size));
}

int		find_char(char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
			j++;
		i++;
	}
	return (j);
}

void	fill_help(t_pf *st)
{
	int i;

	i = 0;
	if (!find(st->a_flags, *(st->str)))
	{
		while (*(st->str) != '%' && *(st->str))
		{
			st->buffer[i] = *(st->str);
			i++;
			(st->str)++;
		}
	}
	if (*(st->str) != '%' && *(st->str))
		(st->str)++;
}
