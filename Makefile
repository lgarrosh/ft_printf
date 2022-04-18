NAME = libftprintf.a
SRC_F = ft_printf.c \
		srcs/ft_other.c \
		srcs/ft_print.c \
		srcs/ft_print_c.c \
		srcs/ft_print_d.c \
		srcs/ft_print_i.c \
		srcs/ft_print_p.c \
		srcs/ft_print_s.c \
		srcs/ft_print_x.c \
		srcs/ft_print_u.c \
		srcs/ft_printf_X.c \
		srcs/init.c

OBJ_F = $(SRC_F:.c=.o)

HEADER = ft_printf.h

CFLAGS = -Wall -Werror -Wextra -I ${HEADER}

all: $(NAME)

$(NAME): $(OBJ_F) ${HEADER}
	$(MAKE) -C libft
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJ_F)

.PHONY	:	all clean fclean re bonus

%.o: %.c ${HEADER}
	cc $(CFLAGS) -c $< -o $@

bonus: $(NAME)

clean:
	rm -rf $(OBJ_F)
	$(MAKE) clean -C libft

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C libft

re: fclean all
	
