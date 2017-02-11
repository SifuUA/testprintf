/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:10:42 by okres             #+#    #+#             */
/*   Updated: 2017/02/10 21:45:26 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_of_words(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i += 1;
		n = -n;
	}
	while ((n = n / 10) != 0)
		i++;
	return (i);
}

static void	write_in_ar(int n, char *ptr, int i)
{
	if (n < 0)
	{
		ptr[0] = '-';
		n = -n;
	}
	ptr[i + 1] = '\0';
	ptr[i--] = '.';
	while (n != 0)
	{
		ptr[i--] = (n % 10 + '0');
		n = n / 10;
	}
}

char		*ft_itoa_mod(int n)
{
	char	*ptr;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	i = count_of_words(n);
	ptr = (char*)malloc(sizeof(char) * i + 2);
	if (!ptr)
		return (0);
	write_in_ar(n, ptr, i);
	return (ptr);
}
