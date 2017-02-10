#include "ft_printf.h"

void	f_11(char cpecif, char *size, va_list vl, char **buffer, t_pf *st)
{
	long long int i;

	i = ft_strlen(size);
	if (i > 2)
		size = ft_strsub(size, i - 2, 2);
	if (size[0] == '\0')
	{
		i = va_arg(vl, long long int);
		if (i == 0 && st->point == 1)
			*buffer = "";
		else
			*buffer = ft_itoa_base(i, 10);
	}
	else if (size[0] == 'h' && size[1] == 'h')
		*buffer = ft_itoa_base((unsigned short int)va_arg(vl, int), 10);
	else if (size[0] == 'h')
		*buffer = ft_itoa_base((short int)(va_arg(vl, int)) , 10);
	else if (size[0] == 'l')
		*buffer = ft_itoa_base(va_arg(vl, long long int), 10);
	else if (size[0] == 'j')
		*buffer = ft_itoa_base(va_arg(vl,intmax_t), 10);
	else if (size[0] == 'z' || size[0] == 't')
		*buffer = ft_itoa_base(va_arg(vl, long long int), 10);
}

void	f_12(char cpecif, char *size, va_list vl, char **buffer, t_pf *st)
{
	wchar_t c;

	c = va_arg(vl, wchar_t);
	c = (char)c;
	**buffer = c;
}

