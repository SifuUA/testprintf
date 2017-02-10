/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 18:05:11 by okres             #+#    #+#             */
/*   Updated: 2017/02/10 17:06:16 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_1(char cpecif, char *size, va_list vl, char **buffer, t_pf *st)
{
	int i;

	i = 0;
	if (cpecif == 'd' || cpecif == 'D' || cpecif == 'i')
	{
		if (cpecif == 'D')
			f_11(cpecif, size, vl, buffer, st);
		else
		{	
		i = ft_strlen(size);
		if (i > 2)
			size = ft_strsub(size, i - 2, 2);
		if (size[0] == '\0')
		{
			i = va_arg(vl, int);
			if (i == 0 && st->point == 1)
				*buffer = "";
			else
				*buffer = ft_itoa_base(i, 10);
		}
		else if (size[0] == 'h' && size[1] == 'h')
			*buffer = ft_itoa_base((signed char)va_arg(vl, int), 10);
		else if (size[0] == 'h')
			*buffer = ft_itoa_base((short int)(va_arg(vl, int)) , 10);
		else if (size[0] == 'l')
			*buffer = ft_itoa_base(va_arg(vl, long long int), 10);
		else if (size[0] == 'j')
			*buffer = ft_itoa_base(va_arg(vl,intmax_t), 10);
		else if (size[0] == 'z' || size[0] == 't')
			*buffer = ft_itoa_base(va_arg(vl, long long int), 10);
		}
	}
	else if (cpecif == 'u' || cpecif == 'U' || cpecif == 'o' || cpecif == 'O' || cpecif == 'x' || cpecif == 'X')
		f_2(cpecif, size, vl, buffer, st);
	else if (cpecif == 'f' || cpecif == 'F' || cpecif == 'e' || cpecif == 'E'
	|| cpecif == 'g' || cpecif == 'G' || cpecif == 'a' || cpecif == 'A')
		f_4(cpecif, size, vl, buffer);
	else if (cpecif == 'c' || cpecif == 'C' || cpecif == 's' || cpecif == 'S')
		f_7(cpecif, size, vl, buffer, st);
	else if (cpecif == 'p')
		f_8(cpecif, size, vl, buffer, st);
}

void	f_2(char cpecif, char *size, va_list vl, char **buffer, t_pf *st)
{
	unsigned int i;
	unsigned char c;

	i = 0;
	if (cpecif == 'u')
	{
		if (size[0] == '\0')
		{
			i = va_arg(vl, unsigned int);
			if (i == 0 && st->point == 1)
				*buffer = "";
			else
				*buffer = ft_itoa_base_unsign(i, 10);
		}
		else if (size[0] == 'h' && size[1] == 'h')
		{
			c = (va_arg(vl, int));
			*buffer = ft_itoa_base(c, 10);
		}
		else if (size[0] == 'h')
			*buffer = ft_itoa_base_unsign((unsigned short int)(va_arg(vl, int)), 10);
		else if (size[0] == 'l' || size[0] == 'j' || size[0] == 'z' || size[0] == 't')
			*buffer = ft_itoa_base_unsign(va_arg(vl, unsigned long long int), 10);
	}
	else if (cpecif == 'U')
	{
		*buffer = ft_itoa_base_unsign(va_arg(vl, unsigned long long int), 10);
	}
	else if (cpecif == 'o')
	{
		if (size[0] == '\0')
		{
			i = va_arg(vl, unsigned int);
			if (i == 0 && st->point == 1)
				*buffer = "";
			else
				*buffer = ft_itoa_base(i, 8);
		}
		else if (size[0] == 'h' && size[1] == 'h')
			*buffer = ft_itoa_base_unsign((unsigned char)(va_arg(vl, int)), 8);
		else if (size[0] == 'h')
			*buffer = ft_itoa_base((unsigned short int)(va_arg(vl, int)), 8);
		else if (size[0] == 'l' || size[0] == 'j' || size[0] == 'z' || size[0] == 't')
			*buffer = ft_itoa_base_unsign(va_arg(vl, unsigned long int), 8);
	}
	else if (cpecif == 'O')
	{
		if (size[0] == '\0')
		{
			i = va_arg(vl, unsigned int);
			*buffer = ft_itoa_base(i, 8);
		}
		else if (size[0] == 'h' && size[1] == 'h')
			*buffer = ft_itoa_base_unsign((unsigned short int)(va_arg(vl, int)), 8);
		else if (size[0] == 'h')
			*buffer = ft_itoa_base((unsigned short int)(va_arg(vl, int)), 8);
		else if (size[0] == 'l' || size[0] == 'j' || size[0] == 'z' || size[0] == 't')
			*buffer = ft_itoa_base_unsign(va_arg(vl, unsigned long int), 8);
	}

	else
		f_3(cpecif, size, vl, buffer, st);
}

void	f_3(char cpecif, char *size, va_list vl, char **buffer, t_pf *st)
{
	unsigned int i;
	unsigned char c;

	i = 0;
	if (cpecif == 'x')
	{
		if (size[0] == '\0')
		{
			i = va_arg(vl, unsigned int);
			if (i == 0 && st->point == 1)
				*buffer = "";
			else
				*buffer = ft_itoa_base_low(i, 16);
		}
		else if (size[0] == 'h' && size[1] == 'h')
		{
			c = va_arg(vl, int);
			*buffer = ft_itoa_base_low(c, 16);

		}
		else if (size[0] == 'h')
			*buffer = ft_itoa_base_low((unsigned short int)(va_arg(vl, int)), 16);
		else if (size[0] == 'j')
			*buffer = ft_itoa_base_unsign_low(va_arg(vl,uintmax_t), 16);
		else if (size[0] == 'l' || size[0] == 'j' || size[0] == 'z' || size[0] == 't')
			*buffer = ft_itoa_base_unsign_low(va_arg(vl, unsigned long long int), 16);
	}
	else if (cpecif == 'X')
	{
		if (size[0] == '\0')
			*buffer = ft_itoa_base(va_arg(vl, unsigned int), 16);
		else if (size[0] == 'h' && size[1] == 'h')
			*buffer = ft_itoa_base_unsign((unsigned char)(va_arg(vl, int)), 16);
		else if (size[0] == 'h')
			*buffer = ft_itoa_base((unsigned short int)(va_arg(vl, int)), 16);
		else if (size[0] == 'l' || size[0] == 'j' || size[0] == 'z' || size[0] == 't')
			*buffer = ft_itoa_base_unsign(va_arg(vl, unsigned long int), 16);
	}
}

void	f_4(char cpecif, char *size, va_list vl, char **buffer)
{
	double		tmp;
	size_t		value;
	char		*ptr;
	char		*ptr1;

	if (cpecif == 'f')
	{
		if (size[0] == '\0')
		{
			tmp = (double)va_arg(vl, double);
			value = tmp;
			*buffer = ft_itoa_mod(value);
			ptr = *buffer;
			ptr1 = ft_itoa_base((tmp * ft_pow(10, num_len(tmp))), 10);
			//printf ("ptr = %s ptr1 = %s\n", ptr, ptr1);
			ptr1 += (ft_strlen(ptr) - 1);
			*buffer = ft_strcat(ptr, ptr1);
		}
		else if (size[0] == 'L')
			f_5(cpecif, size, vl, buffer);
	}
	else
		f_5(cpecif, size, vl, buffer);
}

void	f_5(char cpecif, char *size, va_list vl, char **buffer)
{
	double		tmp;
	size_t		value;
	char		*ptr;
	char		*ptr1;

	if (cpecif == 'f' || cpecif == 'F')
	{
		if (size[0] == '\0' || size[0] == 'L')
		{
			tmp = (long double)va_arg(vl, long double);
			value = tmp;
			*buffer = ft_itoa_mod(value);
			ptr = *buffer;
			ptr1 = ft_itoa_base((tmp * ft_pow(10, num_len(tmp))), 10);
		//	printf ("ptr = %s ptr1 = %s\n", ptr, ptr1);
			ptr1 += (ft_strlen(ptr) - 1);
			*buffer = ft_strcat(ptr, ptr1);
			ft_strdel(&ptr);
		}
	}
	else
		f_6(cpecif, size, vl, buffer);
}
