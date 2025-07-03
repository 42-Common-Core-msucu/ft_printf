NAME = libftprintf.a

SRCS = ft_printf.c ft_put_func.c
OBJS = $(SRCS:.c=.o)

BONUS_DIR = bonus
SRCS_BONUS = $(addprefix $(BONUS_DIR)/, ft_printf_bonus.c ft_extra_func_bonus.c	ft_extra_func_2_bonus.c ft_fill_varpro_bonus.c ft_calculate_len_bonus.c ft_putvar_bonus.c ft_putvar_helper_bonus.c ft_putvar_helper_2_bonus.c)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT_NAME = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT_NAME) $(OBJS)
	cp $(LIBFT_NAME) $(NAME)
	ar -rsc $(NAME) $(OBJS)

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)

$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	$(CC) $(FLAGS) -I libft -c $< -o $@

%.o: %.c
	$(CC) $(FLAGS) -I libft -c $< -o $@

bonus: $(LIBFT_NAME) $(OBJS_BONUS)
	rm -f $(NAME)
	cp $(LIBFT_NAME) $(NAME)
	ar -rsc $(NAME) $(OBJS_BONUS)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus