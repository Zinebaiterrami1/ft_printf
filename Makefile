NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c helper_functions.c main.c\

OBJ = ${SRC:.c=.o}

all : $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re