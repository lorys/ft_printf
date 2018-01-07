# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llopez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 06:30:23 by llopez            #+#    #+#              #
#    Updated: 2018/01/07 00:58:52 by llopez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFILES = ft_printf.c tools/dec_to_hexa.c

OFILES = ft_printf.o tools/dec_to_hexa.o

$(NAME): ft_printf.c
	@make -C libft/
	@gcc -c $(CFILES) -I libft/ -I . -Wall -Wextra -Werror
	@ar rc $(NAME) $(CFILES) libft/libft.a
	@ranlib $(NAME)

all: $(NAME)

test: all
	gcc main.c $(NAME) -I libft/ -Llibft/ -lft -Wall -Werror -Wextra

clean:
	@make -C libft clean
	@rm -f ft_printf.o

fclean: clean
	@make -C libft fclean
	@rm libftprintf.a

re: fclean all
