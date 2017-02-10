#include "ft_printf.h"

int	 		ft_printf(const char * restrict format, ...)
{
	va_list 		vl;
	static t_pf 	*st;
	size_t			count;
	int				i;
	int				j;

	i = 0;
	j = 0;
	va_start (vl, format);
	st = (t_pf *)malloc(sizeof(t_pf));
	memory_allocate(st);
	st->str = ft_strdup((char*) format);
	while (*(st->str))
	{
		check_z(st);
		if (*(st->str) == '%')
		{
			(st->str)++;
			j = len_to_spec(st->str);
			st->tmp = ft_strdup(st->str);
			st->str[j] = '\0';
			if (fill_struct(st, vl) == 0)
				modif_buff(st);
			if (*(st->buffer) == '\0' && ft_strlen(st->tmp) == 1 && st->specifier == '\0' && *(st->flag) == '\0')
				st->str = st->tmp;
			else
				st->str = st->tmp + j;
				st->res = ft_strjoin(st->res, st->buffer);
				free_s(st);
		}
		else
		{
			j = lentoc(st->str, '%');
			st->tmp = ft_strsub(st->str, 0, j);
			st->res = ft_strjoin(st->res, st->tmp);
		(st->str) += j;
		}
	}
    ft_putstr(st->res);
	j = 0;
	if (st->specifier == 'c' && (st->last_buffer == NULL || *(st->last_buffer) == '\0' || *(st->last_buffer) == '0'))
		j = 1;
	return (ft_strlen(st->res) + j);
}
