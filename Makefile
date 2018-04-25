# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llopez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 06:30:23 by llopez            #+#    #+#              #
#    Updated: 2018/04/25 16:28:53 by llopez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

NAMES = 	ft_printf.c \
			bigs.c \
			ft_putlnbr.c \
			get_precision.c \
			get_width.c \
			handle_c.c \
			handle_d.c \
			handle_flags.c \
			get_cast.c \
			handle_p.c \
			handle_percent.c \
			handle_s.c \
			handle_uu.c \
			init_struct.c \
			itoa_base.c \
			putnbr_base.c \
			width_str.c \
			ft_xx_calc_length.c \
			ft_preci_xx.c \
			ft_printf_xx.c \
			ft_preci_oo.c \
			ft_width_oo.c \
			ft_printf_oo.c \
			ft_calc_fg_d.c \
			ft_p_details_x.c \
			ft_printf_precision.c \
			ft_printf_flags_detect.c \
			ft_printf_putspace_d.c \
			ft_printf_width.c \
			ft_printf_putlstr.c \
			ft_printf_getnb.c \
			ft_printf_width_wchar.c \
			ft_fill_null.c \
			ft_wlen.c \
			ft_putwstr.c \
			ft_wchar_one_o.c \
			ft_putwchar.c

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
