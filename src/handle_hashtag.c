/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hashtag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 12:20:16 by llopez            #+#    #+#             */
/*   Updated: 2018/03/19 15:37:29 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_p_details_x(t_arg *fg, intmax_t nb, char const* format)
{
	int	lenght;

	lenght = 0;
	if (fg->hfound == 1 && nb != 0)
	{
		ft_putchar('0');
		ft_putchar(format[0]);
		lenght += 2;
	}
	return (lenght);
}

int			ft_printf_xx(char const*format, va_list ap,\
		int *skip, t_arg *fg)
{
	int			lenght;
	char		*str;
	uintmax_t	nb;
	int			preci;
	int			calc_length;

	lenght = 0;
	preci = fg->precision;
	calc_length = 0;
	if (format[0] == 'x' || format[0] == 'X')
	{
		fg->zero = (fg->precision > -1 || fg->moins)?0:fg->zero;
		nb = ft_printf_unsigned(ap, fg);
		fg->hfound = (nb == 0)?0:fg->hfound;
		str = ft_printf_itoa_base(nb, 16, format[0]);
		calc_length += (fg->precision == 0 && nb == 0)?0:(int)ft_strlen(str);
		lenght += (fg->zero)?ft_p_details_x(fg, nb, format):0;
		calc_length += (fg->hfound == 1 && nb != 0)?2:0;
		calc_length += (fg->precision > calc_length\
				&& nb != 0)?(fg->precision-(int)ft_strlen(str)):0;
		lenght += ft_printf_width(fg, 0, NULL, calc_length);
		lenght += (!fg->zero)?ft_p_details_x(fg, nb, format):0;
		preci = preci-((int)ft_strlen(str));
		while (preci > 0)
		{
			lenght += ft_printf_putlstr("0");
			preci--;
		}
		lenght += (fg->precision == 0 && nb == 0) ? 0 : ft_printf_putlstr(str);
		lenght += ft_printf_width(fg, 1, NULL, calc_length);
		*skip += 2;
	}
	return (lenght);
}

int			ft_printf_oo(char const*format, va_list ap,\
		int *skip, t_arg *fg)
{
	uintmax_t	nb;
	int			lenght;
	char		*str;
	int			preci;
	int			str_len;

	lenght = 0;
	str_len = 0;
	if (format[0] == 'o' || format[0] == 'O')
	{
		preci = fg->precision;
		fg->zero = (fg->precision > -1 || fg->moins)?0:fg->zero;
		nb = ft_printf_unsigned(ap, fg);
		str = ft_printf_itoa_base(nb, 8, format[0]);
		fg->width = (fg->width > 0 && fg->space && fg->zero && nb != 0) ? \
					fg->width-1 : fg->width;
		preci = (preci > -1) ? preci - (int)ft_strlen(str) : preci;
		preci = (fg->hfound && nb != 0) ? preci-1 : preci;
		fg->width = (fg->hfound && nb != 0) ? fg->width-1 : fg->width;
		str_len = (fg->precision == 0 && nb == 0 && !fg->hfound) ? \
				  0 : (int)ft_strlen(str);
		lenght += ft_printf_width(fg, 0, NULL, str_len);
		while (preci > 0)
		{
			lenght += ft_printf_putlstr("0");
			preci--;
		}
		lenght += (fg->hfound && nb != 0) ? ft_printf_putlstr("0") : 0;
		lenght += (fg->precision == 0 && nb == 0 && !fg->hfound) ?\
				  0 : ft_printf_putlstr(str);
		lenght += ft_printf_width(fg, 1, NULL, str_len);
		*skip += 2;
	}
	return (lenght);
}

int			ft_printf_width(t_arg *fg, int r, char *str, int len)
{
	int lenght;
	int	width;
	int	strlen;

	strlen = (str == NULL) ? len : (int)ft_strlen(str);
	width = fg->width;
	lenght = 0;
	if (fg->width_used && fg->moins == r)
	{
		if (fg->precision > -1 && fg->precision > strlen)
			width = fg->width-fg->precision;
		else
			width = width-strlen;
		while (width > 0)
		{
			lenght += ft_printf_putlstr((fg->zero)?"0":" ");
			--width;
		}
	}
	return (lenght);
}

intmax_t	ft_printf_signed(va_list ap, t_arg *fg)
{
	if (fg->z)
		return (va_arg(ap, ssize_t));
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
	if (fg->l || fg->flag == 'O')
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
		if (ft_strchr("oOxX", fg->flag) && !fg->zero && !fg->hfound)
			lenght += ft_printf_putlstr(" ");
		else
			lenght += ft_printf_putlstr("0");
		precision--;
	}
	return (lenght);
}

int			ft_printf_putspace(t_arg *fg, char *str)
{
	(void)str;
	if (!fg->space)
		return (0);
	if (fg->space && fg->width_used)
		return (0);
	if (fg->space && fg->width_used && fg->width <= fg->precision)
		return (0);
	if (fg->space && fg->width_used && fg->width <= (int)ft_strlen(str))
		return (0);
	if (fg->space && fg->plus)
		return (0);
	ft_putchar(' ');
	return (1);
}

int			ft_printf_putspace_d(t_arg *fg, char *str)
{
	(void)str;
	if (!fg->space)
		return (0);
	if (fg->space && fg->width_used && !fg->zero)
		return (0);
	if (fg->space && fg->width_used && fg->width <= fg->precision)
		return (0);
	if (fg->space && fg->width_used && fg->width <= (int)ft_strlen(str))
		return (0);
	if (fg->space && fg->plus)
		return (0);
	ft_putchar(' ');
	return (1);
}
