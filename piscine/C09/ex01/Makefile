NAME = libft.a
SRC = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c \
      srcs/ft_strlen.c srcs/ft_strcmp.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

srcs/%.o : srcs/%.c includes/ft.h
	$(CC) $(CFLAGS) -I includes -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
