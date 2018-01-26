/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 06:39:39 by llopez            #+#    #+#             */
/*   Updated: 2018/01/26 18:09:40 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

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
	int				hfound;
	int				moins;
	int				plus;
}					t_arg;

int					ft_printf(const char*format, ...);
int					ft_printf_s(const char*format, va_list ap, int *skip);
int					ft_printf_putlstr(char *str);
int					ft_printf_p(const char *format, va_list ap,\
		int *skip);
int					ft_printf_d(const char *format, va_list ap,\
		int *skip);
int			ft_printf_c(char const* format, va_list ap, int *skip);
char			*ft_printf_itoa_base(uintmax_t nb, unsigned int base,\
		int	type);
int				ft_printf_flags(char const*format, va_list ap,\
		int *skip, t_arg *fg);
int				ft_printf_xX(char const* format, va_list ap,\
		int *skip);
int				ft_printf_oO(char const* format, va_list ap,\
		int *skip);
int				ft_printf_o(char const*format, va_list ap, int *skip);
int				ft_printf_u(char const*format, va_list ap, int *skip);
int				ft_printf_i(char const*format, va_list ap, int *skipi);

#endif
