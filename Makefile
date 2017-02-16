# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okres <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/11 14:27:01 by okres             #+#    #+#              #
#    Updated: 2017/02/16 10:52:25 by okres            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror -c
SRC =	analize1.c\
		analize2.c\
		analize3.c\
		analize4.c\
		analize5.c\
		dub_float.c\
		fill.c\
		ft_atoi.c\
		ft_bzero.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_itoa_base.c\
		ft_itoa_base_low.c\
		ft_itoa_base_unsign.c\
		ft_itoa_base_unsign_low.c\
		ft_itoa_mod.c\
		ft_pow.c\
		ft_isalpha.c\
		ft_printf.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_putstr_m.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_strlen.c\
		ft_strncpy.c\
		ft_strnew.c\
		ft_strsub.c\
		get_w_s_z.c\
		helpfunc1.c\
		helpfunc2.c\
		helpfunc3.c\
		print_with_flags1.c\
		print_with_flags2.c\
		print_with_flags3.c\
		print_with_flags4.c\
		print_with_flags5.c\
		print_with_flags6.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(SRC)
		@ar rc $(NAME) $(OBJ)
		
clean:
		@rm -f $(OBJ)
		
fclean:
		@make clean
		@rm -f $(NAME)		
re:
		@make fclean
		@make all
		@ar rc $(NAME) $(OBJ)
