# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llopez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 06:30:23 by llopez            #+#    #+#              #
#    Updated: 2017/12/18 07:52:24 by llopez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

$(NAME):
	@make -C libft/
	@gcc -o ft_printf.o -c ft_printf.c -I libft/
	@ar rc $(NAME) ft_printf.o libft/obj/*.o
	@ranlib $(NAME)

all: $(NAME)

clean:
	@make -C libft clean
	@rm -f ft_printf.o

fclean: clean
	@make -C libft fclean
	@rm libftprintf.a

re: fclean all
