/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:07:37 by okres             #+#    #+#             */
/*   Updated: 2017/02/03 17:02:34 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*res;

	if (!s)
		return (NULL);
	ptr = ft_strnew(len);
	if (!ptr)
		return (NULL);
	res = ptr;
	while (len > 0)
	{
		*ptr++ = s[start++];
		len--;
	}
	*ptr = '\0';
	return (res);
}
