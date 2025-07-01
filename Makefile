NAME = libftprintf.a

SRCS = ft_printf.c ft_extra_func.c ft_extra_func_2.c ft_fill_varpro.c ft_calculate_len.c \
	ft_putvar.c ft_putvar_helper.c ft_putvar_helper_2.c
OBJS = $(SRCS:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT_NAME = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT_NAME) $(OBJS)
	cp $(LIBFT_NAME) $(NAME)
	ar -rs $(NAME) $(OBJS)

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

bonus: re

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus