#include "ft_printf.h"

void		mod_zer(t_pf *st, char *spaces, char *zeros, char *ptr, long long znak)
{
	char	*tmp;
	int		i;

	i = ft_strlen(ptr);
	if (st->specifier == 'd' && (st->precision == -1 || st->precision == 0) && st->point == 1)
	{
		st->buffer = ft_strjoin(spaces, st->buffer);
		return ;
	}
	if (find(st->flag, '0') == 1)
	{
		if (st->precision < ft_strlen(st->buffer) && st->precision != 0)
			tmp = ft_strjoin(ptr, st->buffer);
		else if (st->precision > ft_strlen(st->buffer) && st->precision < st->width)
			tmp = ft_strjoin(ptr, st->buffer);
		else
		{
			while (--i >= 0)
				ptr[i] = '0';
			if (*(st->buffer) == '0')
				ptr++;
			tmp = ft_strjoin(ptr, st->buffer);
		}
			st->buffer = tmp;
		i = 0;
		if (znak < 0)
		{
			if(st->buffer[0] == ' ')
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
}
void		mod_min(t_pf *st, char *spaces, char *zeros, char *ptr, long long znak)
{
	char	*tmp;
	char	*tmp1;
	int		i;

	i = 0;
	if (find(st->flag, '-') == 1)
	{
		if (st->width >= st->precision && st->specifier != 'p')
		{
			tmp = ft_strjoin(st->buffer, spaces);
			st->buffer = ft_strjoin(zeros, tmp);
			if (znak < 0)
			{
				i = ft_strlen(st->buffer);
				if (st->buffer[i - 1] == ' ')
					st->buffer[i - 1] = '\0';
				tmp = ft_strjoin("-", st->buffer);
				st->buffer = tmp;
			}
		}
		else
		{
			tmp = ft_strjoin(ptr, st->buffer);
			if (znak < 0)
			{
				st->buffer = ft_strjoin("-", tmp);
				free(tmp);
			}
			else
			{
				st->buffer = tmp;
				if (st->specifier == 'p')
				;//st->buffer = ft_strjoin("0x", st->buffer);
			}

		}
	}
	else 
		mod_zer(st, spaces, zeros, ptr, znak);		
}


void		mod_sp1(t_pf *st, char *spaces, char *zeros, long long znak)
{
	char	*tmp;
	char	*tmp1;

	if (st->precision >= st->width)
	{
		if (znak >= 0)
			tmp = ft_strjoin(" ", st->buffer);
		else
			tmp = ft_strjoin("-", st->buffer);
	}
	else
	{
		tmp1 = ft_strjoin(spaces, zeros);
		tmp = ft_strjoin(tmp1, st->buffer);
	}
	st->buffer = tmp;
}

void		mod_sp(t_pf *st, char *spaces, char *zeros, long long znak)
{
	char	*tmp;
	int		i;
	
	i = 0;
	if (st->specifier == '\0' || st->specifier == '%')
		return ;
	if (st->specifier == 'u')
		return ;
	if (find (st->flag, '-') == 1 || find (st->flag, '0') == 1)
	{
		if (znak > 0)
		{
			if (st->buffer[0] == ' ')
				return ;
			tmp = ft_strjoin(" ", st->buffer);
			i = ft_strlen(tmp);
			if (tmp[i - 1] == ' ')
				tmp[i - 1] = '\0';
			st->buffer = tmp;
		}
	}
	else
	{
		if (ft_strlen(spaces) > 0 && spaces != NULL && (zeros == NULL || *zeros == '\0'))
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
}

void		modif_buff(t_pf *st)
{
	char		a;
	char		*spaces;
	char		*zeros;
	char		*ptr;
	long long	znak;
	
	if (find(st->buffer, '-'))
	{
		(st->buffer) += 1;
		znak = -1;
	}
	if (st->specifier == 'c' && (*st->buffer) =='\0' && st->width == 0)
		return ;
	if (st->specifier == '%' || (*st->buffer) == '%')
	{
		//if ((*st->buffer) == '%')
		//	;//ft_bzero(st->buffer, ft_strlen(st->buffer));
		 if (find_char(st->str, '%'))
		{
			st->buffer = "%";
		}
		else
			st->buffer = "\0";
	}
	spaces = get_space(st);
	zeros = get_zero(st, a);
	ptr = ft_strjoin(spaces, zeros);
	if (find(st->flag, '-') == 1 || find(st->flag, '0') == 1)
		mod_min(st, spaces, zeros, ptr, znak);
	if (find(st->flag, '+') == 1)
		mod_plus(st, spaces, zeros, ptr, znak);
	else if (find(st->flag, ' ') == 1)
		mod_sp(st, spaces, zeros, znak);
	if (find(st->flag, '#'))
		mod_sharp(st, zeros, spaces);
	if (st->flag[0] == '\0')
	{
		if (st->specifier != 'c' && st->specifier != 's' && *(st->buffer) != '%')
		{
			if (znak >= 0)
			{
				if (st->specifier == 'p')
				{
					if (*(st->buffer) == '\0')
					{
						st->buffer = ft_strjoin("0x", st->buffer);
						if (ft_strlen(spaces) >= 2)
							spaces += 2;
						st->buffer = ft_strjoin(st->buffer, ft_strjoin(spaces, zeros));
					}
					else if (st->precision > st->width)
					{
						st->buffer = ft_strjoin(ft_strjoin(spaces, zeros), st->buffer);
						st->buffer = ft_strjoin("0x", st->buffer);
					}
					else
					st->buffer = ft_strjoin(ft_strjoin(spaces, zeros), st->buffer);


				}
				else
					st->buffer = ft_strjoin(ft_strjoin(spaces, zeros), st->buffer);
			}
			else
			{
				if (st->precision > st->width)
				{
					if (spaces > 0)
						spaces++;
					ptr = ft_strjoin(ft_strjoin(spaces, zeros), st->buffer);
					st->buffer = ft_strjoin("-", ptr);
				}
				else
				{
					if (spaces > 0)
						spaces++;
					ptr = ft_strjoin("-", zeros);
					st->buffer = ft_strjoin(ptr, st->buffer);
					st->buffer = ft_strjoin(spaces, st->buffer);
				}
			}

		}
		else
			st->buffer = ft_strjoin(spaces, st->buffer);
	}
}
