# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llopez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 06:30:23 by llopez            #+#    #+#              #
#    Updated: 2018/03/19 16:36:27 by llopez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

NAMES = 	ft_printf.c \
			dec_to_hexa.c \
			handle.c \
			handle_hashtag.c \
			bigs.c

CFILES = $(addprefix src/, $(NAMES))

OBJ = $(patsubst %.c, %.o, $(addprefix $(OBJDIR), $(NAMES)))

VPATH = $(shell find src -type d)

OBJDIR = obj/

$(OBJDIR)%.o: %.c
	@make -C libft_src/
	@mkdir -p $(OBJDIR)
	@gcc -o $@ $(FLAGS) -c $< -I includes/ -I libft_src
	@echo "\t\t$@ created."

$(NAME): $(OBJ) ft_printf.c
	@echo "libft made."
	@ar rc printf.a $(OBJ)
	@libtool -static -o $(NAME) printf.a libft_src/libft.a
	@rm -rf printf.a
	@ranlib $(NAME)
	@echo "$(NAME) created !"

all: $(NAME)

clean:
	@echo "Cleaning libft..."
	@make -C libft_src clean
	@echo "libft cleaned."
	@rm -rf obj/
	@echo "objects dir deleted."

fclean: clean
	@make -C libft_src fclean
	@rm -rf libftprintf.a

re: fclean all

test: $(NAME)
	@gcc main.c -I libft_src/ libftprintf.a
	@echo "ft_printf_test generated !"
