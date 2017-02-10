#include "ft_printf.h"

void		mod_plus1(t_pf *st, char *spaces, char *zeros, char *ptr, long long znak)
{
	char	*tmp;
	char	*tmp1;

	if (zeros != NULL && ft_strlen(zeros) > 0)
	{
		if (znak >= 0)
			tmp = ft_strjoin("+", zeros);
		else
			tmp = ft_strjoin("-", zeros);
		ft_strdel(&zeros);
		spaces++;
		tmp1 = ft_strjoin(spaces, tmp);
		ft_strdel(&tmp);
		tmp = ft_strjoin(tmp1, st->buffer);
		ft_strdel(&tmp1);
		st->buffer = tmp;
	}
	else
	{
		if(znak >= 0)
			tmp = ft_strjoin("+", st->buffer);
		else
			tmp = ft_strjoin("-", st->buffer);
		//ft_strdel(&(st->buffer));
		st->buffer = tmp;
	}
}

void		mod_plus(t_pf *st, char *spaces, char *zeros, char *ptr, long long znak)
{
	char	*tmp;

		if (find(st->flag, '-') || find(st->flag, '0'))
		{
			if (znak >= 0)
			{
				if (st->buffer[0] == '0' && find(st->flag, '0'))
				{
					if (*(st->last_buffer) != '0')
						(st->buffer)++;
					tmp = ft_strjoin("+", st->buffer);
				}
				else	
				{
					if (st->buffer[ft_strlen(st->buffer) - 1] == ' ')
						st->buffer[ft_strlen(st->buffer) - 1] = '\0';
					tmp = ft_strjoin("+", st->buffer);
			//if (st->width > st->precision && st->width > ft_strlen(st->buffer))
			//	tmp[ft_strlen(tmp) - 1] = '\0';
				}
			st->buffer = tmp;
			}
		}
		else if (ft_strlen(spaces) > 0 && zeros == NULL && spaces != NULL)
		{
			if (znak >= 0)
				tmp = ft_strjoin("+", st->buffer);
			else
				tmp = ft_strjoin("-", st->buffer);
			ptr++;
			st->buffer = ft_strjoin(ptr, tmp);
			ft_strdel(&(tmp));
		}
		else
			mod_plus1(st, spaces, zeros, ptr, znak);
	if (st->specifier =='u' || st->specifier == 'x' || st->specifier =='X' || st->specifier == 'o')
		(st->buffer)++;
}

void		mod_sharp1(t_pf *st, char *tmp, int i)
{
	if (find(st->flag, '-'))
	{
		(st->buffer)++;
		if (st->width > st->precision && st->precision != 0)
		{
			tmp = ft_strjoin(st->buffer, " ");
			st->buffer = tmp;
		}
		if (st->buffer[0] != '0')
		{
			tmp = ft_strjoin("0", st->buffer);
			st->buffer = tmp;
		}
	}
	else
	{
		while (st->buffer[i] == ' ')
			i++;
		if (i > 0 && st->buffer[i] != '0')
			st->buffer[i - 1] = '0';
		else if (st->buffer[i] != '0')
			st->buffer = ft_strjoin("0", st->buffer);
		else if (st->precision > st->width)
			(st->buffer)++;
	}
}

void		mod_sharp(t_pf *st, char *zeros, char *spaces)
{
	char	*tmp;
	int		i;

	i = 0;
	//tmp = ft_strchr
	if (st->specifier == 'o')
	{
		if (find(st->flag, '-') || find(st->flag, ' ') || find(st->flag, '0'))
		{
			if (find (st->flag, '-'))
			{
				if (st->buffer[0] != '0' && !find(st->flag, ' '))
				{	
					tmp = ft_strjoin("0", st->buffer);
					st->buffer = tmp;
					if (st->buffer[ft_strlen(st->buffer) - 1] == ' ')
						st->buffer[ft_strlen(st->buffer) - 1] = '\0';
				}
			}
			if (find (st->flag, ' '))
				mod_sharp1(st, tmp, i);
		}
		else
		{
			if (st->width > ft_strlen(st->buffer) && zeros == NULL)
			{
				tmp = ft_strjoin("0", st->buffer);
				spaces++;
				st->buffer = ft_strjoin(spaces, tmp);
			}
			else if (st->precision > st->width)
			{
				tmp = ft_strjoin(zeros, st->buffer);
				st->buffer = tmp;
			}
			else if (st->width > st->precision)
			{
				tmp = ft_strjoin(spaces, zeros);
				st->buffer = ft_strjoin(tmp, st->buffer);
			}
			else
				st->buffer = ft_strjoin("0", st->buffer);
		}
	}
	else
		mod_sharp2(st, zeros, spaces);
}

