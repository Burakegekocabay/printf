NAME = libftprintf.a

SRC = 	ft_printf.c 	\
		get_numbers.c	\
		get_hex.c		\
		get_words.c		\
		get_pointer.c

CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all