/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpfunc3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 11:32:43 by okres             #+#    #+#             */
/*   Updated: 2017/02/12 16:17:57 by okres            ###   ########.fr       */
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

void	check_z(t_pf *st)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (st->str[i])
	{
		if (st->str[i] == 'Z')
		{
			(st->str) += (i + 1);
			tmp = ft_strjoin(st->res, "Z");
			free(st->res);
			st->res = tmp;
		}
		i++;
	}
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
