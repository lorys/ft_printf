# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llopez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 06:30:23 by llopez            #+#    #+#              #
#    Updated: 2018/01/18 18:43:45 by llopez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

NAMES = ft_printf.c \
			dec_to_hexa.c

CFILES = $(addprefix src/, $(NAMES))

OBJ = $(patsubst %.c, %.o, $(addprefix $(OBJDIR), $(notdir $(CFILES))))

VPATH = $(shell find src -type d)

OBJDIR = obj/

$(OBJDIR)%.o: %.c
	@make -C libft/
	@mkdir -p $(OBJDIR)
	@gcc -o $@ $(FLAGS) -c $< -I includes/ -I libft/
	@echo "\t\t$@ created."

$(NAME): $(OBJ) ft_printf.c
	@echo "libft made."
	@ar rc printf.a $(OBJ)
	@ranlib $(NAME)
	$(shell lipo -create printf.a libft/libft.a -output $(NAME))
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

test: all
	@gcc -o ft_printf_test  main.c $(NAME) $(FLAGS) -L. -lftprintf -fsanitize=address
	@echo "ft_printf_test generated !"
