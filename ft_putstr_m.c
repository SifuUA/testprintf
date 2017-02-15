/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:38:18 by okres             #+#    #+#             */
/*   Updated: 2017/02/15 15:51:59 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_m(char const *s, int p, t_pf *st)
{
	int		i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar(s[i]);
		if (p > 0 && s[i + 2] == '\0')
		{
			ft_putchar('\0');
			p = 0;
		}
		i++;
	}
	if (st->specifier == 'C' && p == 1)
		ft_putchar('\0');
}
