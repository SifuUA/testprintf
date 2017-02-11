/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_with_flags4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 14:03:31 by okres             #+#    #+#             */
/*   Updated: 2017/02/11 15:02:27 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mod_zer_1(t_pf *st, long long znak, char *tmp)
{
	int		i;

	i = 0;
	if (znak < 0)
	{
		if (st->buffer[0] == ' ')
		{
			while (st->buffer[i] == ' ')
				i++;
			tmp[i - 1] = '-';
			st->buffer = tmp;
		}
		else
		{
			if (st->buffer[0] == '0')
				(st->buffer)++;
			tmp = ft_strjoin("-", st->buffer);
			st->buffer = tmp;
		}
	}
}

void	mod_zer_2(t_pf *st)
{
	int		i;

	i = ft_strlen(st->ptr);
	while (--i >= 0)
		st->ptr[i] = '0';
	if (*(st->buffer) == '0')
		(st->ptr)++;
}

void	mod_min_1(t_pf *st, long long znak)
{
	char	*tmp;

	if (st->specifier == 'p')
		tmp = ft_strjoin(st->buffer, st->ptr);
	else
		tmp = ft_strjoin(st->ptr, st->buffer);
	if (znak < 0)
	{
		st->buffer = ft_strjoin("-", tmp);
		free(tmp);
	}
	else
		st->buffer = tmp;
}

void	mod_sp2(t_pf *st, char *spaces, char *zeros, long long znak)
{
	char	*tmp;

	if (ft_strlen(spaces) > 0 && spaces != NULL && (zeros == NULL
				|| *zeros == '\0'))
	{
		tmp = ft_strjoin(spaces, st->buffer);
		st->buffer = tmp;
	}
	else if (zeros != NULL && (spaces == NULL || *spaces == '\0'))
	{
		tmp = ft_strjoin(zeros, st->buffer);
		st->buffer = ft_strjoin(" ", tmp);
	}
	else
		mod_sp1(st, spaces, zeros, znak);
}
