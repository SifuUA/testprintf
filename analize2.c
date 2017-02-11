/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analize2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 21:14:44 by okres             #+#    #+#             */
/*   Updated: 2017/02/11 20:51:25 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_6(char *size, va_list vl, char **buffer, t_pf *st)
{
	char	*tmp;

	if (size[0] == '\0')
	{
		*buffer = va_arg(vl, char *);
		if (*buffer == NULL)
			*buffer = "(null)";
		if (st->precision < (int)ft_strlen(*buffer) && st->precision > 0)
		{
			tmp = ft_strnew(st->precision);
			tmp = ft_strncpy(tmp, st->buffer, st->precision);
			st->buffer = tmp;
		}
		else if (st->precision < (int)ft_strlen(*buffer))
		{
			tmp = ft_strdup(*buffer);
			tmp[st->precision] = '\0';
			*buffer = tmp;
		}
		else
			st->precision = 0;
	}
}

void	f_7(char *size, va_list vl, char **buffer, t_pf *st)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (st->specifier == 'c' || st->specifier == 'C')
	{
		if (size[0] == '\0' || size[0] == 'l')
		{
			i = va_arg(vl, int);
			if (i == 0)
				st->uk = 1;
			**buffer = (char)i;
		}
	}
	else if (st->specifier == 's' || st->specifier == 'S')
		f_6(size, vl, buffer, st);
}

void	f_9(va_list vl, char **buffer)
{
	wchar_t	*s;
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	s = va_arg(vl, wchar_t*);
	while (s[i] != '\0')
	{
		i++;
	}
	res = (char *)malloc(sizeof(char) * i + 1);
	while (j < i)
	{
		res[j] = (char)s[j];
		j++;
	}
	res[j] = '\0';
	*buffer = res;
}

void	f_10(char *size, char **buffer, t_pf *st)
{
	char *tmp;

	if (size[0] == '\0')
	{
		if (*buffer == NULL)
			*buffer = "(null)";
		if (st->precision < (int)ft_strlen(*buffer) && st->precision > 0)
		{
			tmp = ft_strnew(st->precision);
			tmp = ft_strncpy(tmp, st->buffer, st->precision);
			st->buffer = tmp;
		}
		else if (st->precision < (int)ft_strlen(*buffer))
		{
			tmp = ft_strdup(*buffer);
			tmp[st->precision] = '\0';
			*buffer = tmp;
		}
		else
			st->precision = 0;
	}
}

void	f_8(va_list vl, char **buffer, t_pf *st)
{
	char	*tmp;
	void	*i;
	
	if (st->specifier == 'n')
		f_17(vl, st);
	else
	{
		i = va_arg(vl, void*);
		if (i == 0 && st->point == 1)
		{
			*buffer = "";
		}
		else if (st->width > st->precision)
		{
			*buffer = ft_itoa_base_low((long long)i, 16);
			tmp = ft_strjoin("0x", *buffer);
			*buffer = tmp;
		}
		else
			*buffer = ft_itoa_base_low((long long)i, 16);
	}
}
