/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 06:39:39 by llopez            #+#    #+#             */
/*   Updated: 2018/02/21 20:37:37 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>
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
	int				space;
	int				zero;
	int				width_used;
	int				flag;
}					t_arg;

int					ft_printf(const char*format, ...);
int					ft_printf_s(const char*format, va_list ap,\
						int *skip, t_arg *fg);
int					ft_printf_putlstr(char *str);
int					ft_printf_p(const char *format, va_list ap,\
						int *skip, t_arg *fg);
int					ft_printf_d(const char *format, va_list ap,\
						int *skip, t_arg *fg);
int					ft_printf_c(char const* format, va_list ap,\
						int *skip, t_arg *fg);
char				*ft_printf_itoa_base(uintmax_t nb, unsigned int base,\
						int	type);
int					ft_printf_flags(char const*format, int *skip, t_arg *fg);
int					ft_printf_xX(char const* format, va_list ap,\
						int *skip, t_arg *fg);
int					ft_printf_oo(char const* format, va_list ap,\
						int *skip, t_arg *fg);
int					ft_printf_oO(char const*format, va_list ap, int *skip,\
						t_arg *fg);
int					ft_printf_uu(char const*format, va_list ap, int *skip,\
						t_arg *fg);
void				ft_initialize_struct(t_arg *fg);
int					ft_add(int *nb, int plus);
int					ft_printf_width(t_arg *fg, int r, char *str, int len);
int					ft_get_precision(const char *str);
int					ft_get_width(const char *str, t_arg *fg);
int					ft_printf_percent(char const*format, int *skip, t_arg *fg);
intmax_t			ft_printf_signed(va_list ap, t_arg *fg);
uintmax_t			ft_printf_unsigned(va_list ap, t_arg *fg);
int					ft_printf_precision(t_arg *fg, int width);
int					ft_printf_putspace(t_arg *fg, char *str);
int					ft_printf_width_str(t_arg *fg, int r, char *str);

#endif
