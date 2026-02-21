CC = cc
CFLAGS = -Wall -Wextra -Werror 
# LDLIBS = .
NAME = libftprintf.a
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
includes = .

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(includes)

$(NAME): $(OBJS)
	ar rcs $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
