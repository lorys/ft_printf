/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hashtag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 09:01:28 by llopez            #+#    #+#             */
/*   Updated: 2018/02/12 21:30:04 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_add(int *nb, int plus)
{
	*nb += plus;
	return (1);
}

int			ft_printf_xX(char const*format, va_list ap,\
		int *skip, t_arg *fg)
{
	int		lenght;

	lenght = 0;
	if (format[0] == 'x' || format[0] == 'X')
	{
		if (fg->hfound == 1)
			lenght += ft_printf("0%c", format[0]);
		lenght += ft_printf_putlstr(ft_printf_itoa_base(\
					va_arg(ap, int), 16, format[0]));
		*skip += 2;
	}
	return (lenght);
}

int			ft_printf_oO(char const*format, va_list ap,\
		int *skip, t_arg *fg)
{
	int		lenght;

	lenght = 0;
	if (format[0] == 'o' || format[0] == 'O')
	{
		if (fg->hfound == 1)
			lenght += ft_printf("0");
		if (format[0] == 'o')
			lenght += ft_printf_putlstr(ft_printf_itoa_base(\
						va_arg(ap, uintmax_t), 8, format[0]));
		if (format[0] == 'O')
			lenght += ft_printf_putlstr(ft_printf_itoa_base(\
						va_arg(ap, uintmax_t), 8, format[0]));
		*skip += 2;
	}
	return (lenght);
}

int			ft_printf_width(t_arg *fg, int r)
{
	int lenght;
	int	width;

	width = fg->width;
	lenght = 0;
	while (width > 0 && fg->moins == r)
	{
		if (fg->zero)
			lenght += ft_printf_putlstr("0");
		else
			lenght += ft_printf_putlstr(" ");
		--width;
	}
	return (lenght);
}

intmax_t	ft_printf_signed(va_list ap, t_arg *fg)
{
	if (fg->hh)
		return ((char)va_arg(ap, int));
	if (fg->h)
		return ((short int)va_arg(ap, int));
	if (fg->j)
		return (va_arg(ap, intmax_t));
	if (fg->l)
		return (va_arg(ap, long));
	if (fg->ll)
		return (va_arg(ap, long long));
	return (va_arg(ap, int));
}

uintmax_t	ft_printf_unsigned(va_list ap, t_arg *fg)
{
	if (fg->hh)
		return ((unsigned char)va_arg(ap, unsigned int));
	if (fg->h)
		return ((unsigned short int)va_arg(ap, unsigned int));
	if (fg->j)
		return (va_arg(ap, uintmax_t));
	if (fg->z)
		return (va_arg(ap, size_t));
	if (fg->l)
		return (va_arg(ap, unsigned long));
	if (fg->ll)
		return (va_arg(ap, unsigned long long));
	return (va_arg(ap, unsigned int));
}

int			ft_printf_precision(t_arg *fg, int width)
{
	int lenght;
	int	precision;

	precision = fg->precision - width;
	lenght = 0;
	if (fg->precision < 1)
		return (0);
	while (precision > 0)
	{
		lenght += ft_printf_putlstr("0");
		precision--;
	}
	return (lenght);
}

int			ft_printf_putspace(t_arg *fg, char *str)
{
	(void)str;
	if (fg->space && (fg->precision > -1 && fg->width_used &&\
				(fg->precision == 0 || fg->width == 0)))
		return (0);
	if (!fg->space)
		return (0);
	ft_printf_putlstr(" ");
	return (1);
}
