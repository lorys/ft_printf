/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 06:39:39 by llopez            #+#    #+#             */
/*   Updated: 2018/01/22 16:20:59 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct		s_arg
{
	int				hh;
	int				h;
	int				l;
	int				ll;
	int				j;
	int				z;
	int				width;
	int				precision;
	int				min;
	int				max;
}					t_arg;

int					ft_printf(const char*restrict format, ...);
int					ft_printf_s(const char*format, va_list ap, int *skip);
int					ft_printf_putlstr(char *str);
int					ft_printf_p(const char *format, va_list ap,\
		int *skip);
int					ft_printf_d(const char *format, va_list ap,\
		int *skip);

#endif
