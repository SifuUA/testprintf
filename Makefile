NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
SRC = *.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		clear
		@$(CC) -c $(SRC)
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
d:
	lldb a.out
a:
	clear
	gcc -g *.c 
