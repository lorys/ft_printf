# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llopez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 06:30:23 by llopez            #+#    #+#              #
#    Updated: 2018/01/07 22:42:16 by llopez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

CFILES = ft_printf.c \
			dec_to_hexa.c

OBJ = $(CFILES:%.c=$(OBJDIR)%.o)

OBJDIR = obj/

$(OBJDIR)%.o: %.c
	@mkdir -p $(OBJDIR)
	@gcc -o $@ $(FLAGS) -c $< -I libft/ -I .
	@echo "\t\t$@ created."

$(NAME): $(OBJ) ft_printf.c
	@make -C libft/
	@ar rc $(NAME) $(OBJ) libft/libft.a
	@ranlib $(NAME)

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

test: all
	@gcc -o ft_printf_test  main.c $(NAME) -I libft/ -Llibft/ -lft $(FLAGS)
	@echo "ft_printf_test generated !"
