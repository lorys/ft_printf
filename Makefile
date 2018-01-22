# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llopez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 06:30:23 by llopez            #+#    #+#              #
#    Updated: 2018/01/22 14:33:43 by llopez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

NAMES = ft_printf.c \
			dec_to_hexa.c

CFILES = $(addprefix src/, $(NAMES))

OBJ = $(patsubst %.c, %.o, $(addprefix $(OBJDIR), $(NAMES)))

VPATH = $(shell find src -type d)

OBJDIR = obj/

$(OBJDIR)%.o: %.c
	@make -C libft/
	@mkdir -p $(OBJDIR)
	@gcc -o $@ $(FLAGS) -c $< -I includes/ -I libft/
	@echo "\t\t$@ created."

$(NAME): $(OBJ) ft_printf.c
	@echo "libft made."
	@ar rc $(NAME) $(OBJ) libft/libft.a
	@ranlib $(NAME)
	@echo "$(NAME) created !"

all: $(NAME)

clean:
	@echo "Cleaning libft..."
	@make -C libft clean
	@echo "libft cleaned."
	@rm -rf obj/
	@echo "objects dir deleted."

fclean: clean
	@make -C libft fclean
	@rm -rf libftprintf.a

re: fclean all

test:
	@gcc  main.c src/dec_to_hexa.c src/ft_printf.c src/handle.c -I includes -Llibft -lft
	@echo "ft_printf_test generated !"
