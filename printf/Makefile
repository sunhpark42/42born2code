NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c ft_printf_parsing.c ft_printf_c.c ft_printf_s.c ft_printf_percent.c ft_printf_d.c ft_printf_u.c ft_printf_x.c ft_printf_p.c ft_printf_utils.c ft_printf_utils2.c libft1.c libft2.c
OBJS = $(SRCS:.c=.o)

.PHONY : all bonus clean fclean re

all : $(NAME)

bonus : all

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

.c.o :
	$(CC) -c $(CFLAGS) -o $@ $<

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

