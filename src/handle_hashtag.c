/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hashtag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 09:01:28 by llopez            #+#    #+#             */
/*   Updated: 2018/02/23 10:48:36 by llopez           ###   ########.fr       */
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
	int			lenght;
	char		*str;
	uintmax_t	nb;

	lenght = 0;
	if (format[0] == 'x' || format[0] == 'X')
	{
		nb = ft_printf_unsigned(ap, fg);
		str = ft_printf_itoa_base(nb, 16, format[0]);
		lenght += ft_printf_width_str(fg, 0, str);
		if (fg->hfound == 1 && nb != 0)
		{
			ft_putchar('0');
			ft_putchar(format[0]);
			lenght += 2;
		}
		lenght += ft_printf_precision(fg, (int)ft_strlen(str));
		lenght += (fg->precision == 0 && nb == 0)?0:ft_printf_putlstr(str);
		lenght += ft_printf_width_str(fg, 1, str);
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

	lenght = 0;
	if (format[0] == 'o' || format[0] == 'O')
	{
		preci = fg->precision;
		fg->zero = (fg->precision > -1 || fg->hfound)?0:fg->zero;
		nb = ft_printf_unsigned(ap, fg);
		str = ft_printf_itoa_base(nb, 8, format[0]);
		lenght += ft_printf_width(fg, 0, NULL, (int)ft_strlen(str)+(nb != 0?fg->hfound:0));
		fg->precision = (fg->precision > -1)?\
						fg->precision - (int)ft_strlen(str):fg->precision;
		fg->precision = (fg->hfound && nb != 0)?fg->precision-1:fg->precision;
		fg->width = (fg->precision > -1)?fg->width-fg->precision:fg->width;
		while (fg->precision > 0)
		{
			lenght += ft_printf_putlstr("0");
			fg->precision--;
		}
		lenght += (fg->hfound && nb != 0)?ft_printf_putlstr("0"):0;
		lenght += ft_printf_putlstr(str);
		lenght += ft_printf_width(fg, 1, NULL, (int)ft_strlen(str)+(nb != 0?fg->hfound:0));
		*skip += 2;
	}
	return (lenght);
}

int			ft_printf_width(t_arg *fg, int r, char *str, int len)
{
	int lenght;
	int	width;
	int	strlen;

	strlen = (str == NULL)?len:(int)ft_strlen(str);
	width = fg->width;
	width = (fg->width_used)?width - strlen:width;
	width = (fg->width_used && fg->precision > 0)\
			?width - (fg->precision-strlen):width;
	width = (width > 0 && fg->space && fg->zero)?width-1:width;
	lenght = 0;
	while (width > 0 && fg->moins == r)
	{
		lenght += ft_printf_putlstr((fg->zero)?"0":" ");
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
		if (ft_strchr("oOxX", fg->flag) && (fg->hfound || fg->moins))
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
	if (fg->space && fg->width_used && fg->precision > -1)
		return (0);
	if (fg->space && fg->width_used && fg->width <= fg->precision)
		return (0);
	if (fg->space && fg->width_used && fg->width <= (int)ft_strlen(str))
		return (0);
	if (fg->space && fg->plus)
		return (0);
	ft_printf_putlstr(" ");
	return (1);
}
