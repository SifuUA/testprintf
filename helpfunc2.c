/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpfunc2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 11:30:59 by okres             #+#    #+#             */
/*   Updated: 2017/02/11 14:38:18 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_flag(char *str, char *flags)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (find(flags, str[i]))
		{
			if (str[i] == '0' && ft_isdigit(str[i - 1]))
				;
			else
				count++;
		}
		i++;
	}
	return (count > 0 ? 1 : 0);
}

int		find_num(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int		len_to_spec(char *s)
{
	char	*spec;
	int		i;

	spec = "sSpdDioOuUxXcCdfFeEgGaApn%";
	i = 0;
	while (s[i])
	{
		if (find(spec, s[i]))
			return (++i);
		i++;
	}
	return (i);
}

int		lentoc(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}
