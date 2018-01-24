# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llopez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 06:30:23 by llopez            #+#    #+#              #
#    Updated: 2018/01/24 16:43:45 by llopez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

SOURCES = ft_atoi.c \
		  ft_bzero.c \
		  ft_isalnum.c \
		  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isprint.c \
		  ft_memccpy.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_memset.c \
		  ft_putchar.c \
		  ft_putstr.c \
		  ft_strlen.c \
		  ft_tolower.c \
		  ft_toupper.c \
		  ft_strncmp.c \
		  ft_strcmp.c \
		  ft_strnstr.c \
		  ft_strstr.c \
		  ft_strrchr.c \
		  ft_strchr.c \
		  ft_strcat.c \
		  ft_strncat.c \
		  ft_strlcat.c \
		  ft_strdup.c \
		  ft_strndup.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strcpy.c \
		  ft_strncpy.c \
		  ft_memalloc.c \
		  ft_memdel.c \
		  ft_strnew.c \
		  ft_strclr.c \
		  ft_strdel.c \
		  ft_striter.c \
		  ft_striteri.c \
		  ft_strmap.c \
		  ft_strmapi.c \
		  ft_strequ.c \
		  ft_strnequ.c \
		  ft_strsub.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_putendl.c \
		  ft_itoa.c \
		  ft_intlen.c \
		  ft_putnbr.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_swap.c \
		  ft_strsplit.c \
		  ft_lstnew.c \
		  ft_lstdelone.c \
		  ft_lstdel.c \
		  ft_lstadd.c \
		  ft_lstiter.c \
		  ft_lstmap.c \
		  ft_realloc.c \
		  ft_sqrt.c

NAMES = 	ft_printf.c \
			dec_to_hexa.c \
			handle.c \
			handle_hashtag.c

CFILES = $(addprefix src/, $(NAMES))

OBJ = $(patsubst %.c, %.o, $(addprefix $(OBJDIR), $(NAMES)))

VPATH = $(shell find src -type d)

OBJDIR = obj/

$(OBJDIR)%.o: %.c
	@make -C libft/
	@mkdir -p $(OBJDIR)
	@gcc -o $@ $(FLAGS) -c $< -I includes/ -I libft
	@echo "\t\t$@ created."

$(NAME): $(OBJ) ft_printf.c
	@echo "libft made."
	$(shell cd obj/ && ar -x ../libft/libft.a)
	@ar rc $(NAME) $(OBJ) $(addprefix obj/, $(patsubst %.c, %.o, $(SOURCES)))
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
	@gcc  main.c src/dec_to_hexa.c src/handle_hashtag.c src/ft_printf.c src/handle.c -I libft -I includes -Llibft -lft $(FLAGS)
	@echo "ft_printf_test generated !"
