/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 14:11:53 by okres             #+#    #+#             */
/*   Updated: 2017/02/15 15:52:07 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

typedef struct		s_pf
{
	char			*str;
	char			*buffer;
	char			*res;
	char			*ptr;
	long long		znak;
	int				point;
	char			*tmp;
	char			*last_buffer;
	int				p;
	int				uk;
	char			*a_spec;
	char			*a_sizes;
	char			*a_flags;
	char			*flag;
	int				width;
	int				precision;
	char			*size;
	char			specifier;
	size_t			*n;
}					t_pf;

int					ft_printf(const char *restrict format, ...);
void				ft_printf_1(t_pf *st, va_list vl);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isdigit(int c);
size_t				ft_pow(size_t nb, size_t pow);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putstr_m(char const *s, int p, t_pf *st);
char				*ft_strcat(char *restrict str1, const char *restrict str2);
void				ft_strdel(char **as);
char				*ft_strdup(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *str);
char				*ft_strnew(size_t size);
char				*ft_strchr(const char *s, int c);
int					ft_isascii(int c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_isalpha(int c);

char				*ft_itoa_mod(int n);
char				*ft_itoa_base(long long int value, long long int base);
char				*ft_itoa_base_low(long long int value, long long int base);
char				*ft_itoa_base_unsign(unsigned long long int value,
					unsigned long long int base);
char				*ft_itoa_base_unsign_low(unsigned long long int value,
					unsigned long long int base);
long long int		ft_atoi_mod(const char *str);

int					num_len(double num);
int					find(char *str, char c);
int					find_mod(char *a, char *b, char *c, char tmp);
char				*upper_case(char **str);
void				memory_allocate(t_pf *st);
int					len_to_spec(char *s);
int					lentoc(char *s, char c);
void				free_s(t_pf *st);
int					check_flag(char *str, char *flags);
int					find_num(char *str);
int					two_perc(t_pf *st);
void				check_z(t_pf *s);
int					find_char(char *str, char c);

int					fill_struct(t_pf *st, va_list vl);
void				fill_flags(t_pf *st, char *flags);
void				fill_width(char **str, int *width, va_list vl, t_pf *st);
void				fill_precision(char **str, int *precision, va_list vl,
					t_pf *st);

void				fill_size(char **str, char *sizes, char *size, t_pf *st);
void				f_1(char *size, va_list vl, char **buffer, t_pf *st);
void				f_2(char *size, va_list vl, char **buffer, t_pf *st);
void				f_3(char *size, va_list vl, char **buffer, t_pf *st);
void				f_4(char *size, va_list vl, char **buffer, t_pf *st);
void				f_5(char *size, va_list vl, char **buffer, t_pf *st);
void				f_6(char *size, va_list vl, char **buffer, t_pf *st);
void				f_7(char *size, va_list vl, char **buffer, t_pf *st);
void				f_8(va_list vl, char **buffer, t_pf *st);
void				f_10(char *size, char **buffer, t_pf *st);
void				f_11(char *size, va_list vl, char **buffer, t_pf *st);
void				f_12(char *size, va_list vl, char **buffer, t_pf *st);
void				f_13(char *size, va_list vl, char **buffer, t_pf *st);
void				f_14(char *size, va_list vl, char **buffer, t_pf *st);
void				f_15(char *size, va_list vl, char **buffer, t_pf *st);
void				f_16(char *size, va_list vl, char **buffer, t_pf *st);
void				f_17(va_list vl, t_pf *st);
void				f_18(va_list vl, t_pf *st);
void				f_19(va_list vl, t_pf *st);
char				*bit_move(int i);

void				modif_buff(t_pf *st);
void				modif_buff_1(t_pf *st, char	*spaces, char *zeros);
void				modif_buff_2(t_pf *st, char	*spaces, char *zeros);
void				modif_buff_3(t_pf *st, char	*spaces, char *zeros,
					long long znak);
char				*get_zero(t_pf *st, char a);
char				*get_space(t_pf *st);

void				mod_zer(t_pf *st, char *spaces, long long znak);
void				mod_zer_1(t_pf *st, long long znak, char *tmp);
void				mod_zer_2(t_pf *st);
void				mod_min(t_pf *st, char *spaces, char *zeros,
					long long znak);
void				mod_min_1(t_pf *st, long long znak);
void				mod_plus(t_pf *st, char *spaces, char *zeros,
					long long znak);
void				mod_plus1(t_pf *st, char *spaces, char *zeros,
					long long znak);
void				mod_plus2(t_pf *st, long long znak);
void				mod_plus3(t_pf *st, char *spaces, char *zeros,
					long long znak);
void				mod_sp(t_pf *st, char *spaces, char *zeros,
					long long znak);
void				mod_sp1(t_pf *st, char *spaces, char *zeros,
					long long znak);
void				mod_sp2(t_pf *st, char *spaces, char *zeros,
					long long znak);
void				mod_sharp(t_pf *st, char *zeros, char *spaces, int i);
void				mod_sharp1(t_pf *st, char *tmp, int i);
void				mod_sharp2(t_pf *st, char *zeros, char *spaces);
void				mod_sharp3(t_pf *st, char *tmp, int i);
void				mod_sharp4(t_pf *st, int i);
void				mod_sharp5(t_pf *st, char *zeros, char *spaces);
void				mod_sharp_h1(t_pf *st);
void				mod_sharp_h2(t_pf *st, char *spaces);
void				mod_sharp_h3(t_pf *st, char *zeros);
void				mod_sharp_h4(t_pf *st, char *zeros, char *spaces);
void				mod_sharp_h5(t_pf *st);

#endif
