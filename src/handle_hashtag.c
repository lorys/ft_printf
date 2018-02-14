/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hashtag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 09:01:28 by llopez            #+#    #+#             */
/*   Updated: 2018/02/14 19:49:30 by llopez           ###   ########.fr       */
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
	char	*str;

	lenght = 0;
	if (format[0] == 'x' || format[0] == 'X')
	{
		str = ft_printf_itoa_base(ft_printf_unsigned(ap, fg), 16, format[0]);
		lenght += ft_printf_width_str(fg, 0, str);
		if (fg->hfound == 1)
			lenght += ft_printf("0%c", format[0]);
		lenght += ft_printf_putlstr(str);
		lenght += ft_printf_width_str(fg, 1, str);
		*skip += 2;
	}
	return (lenght);
}

int			ft_printf_oo(char const*format, va_list ap,\
		int *skip, t_arg *fg)
{
	int		lenght;
	char	*str;

	lenght = 0;
	if (format[0] == 'o' || format[0] == 'O')
	{
		fg->zero = (fg->precision > -1)?0:fg->zero;
		str = ft_printf_itoa_base(ft_printf_unsigned(ap, fg), 8, format[0]);
		lenght += ft_printf_width_str(fg, 0, str);
		lenght += ft_printf_precision(fg, (int)ft_strlen(str));
		lenght += ft_printf_putlstr("0");
		lenght += ft_printf_putlstr(str);
		lenght += ft_printf_width_str(fg, 1, str);
		*skip += 2;
	}
	return (lenght);
}

int			ft_printf_width(t_arg *fg, int r, char *str)
{
	int lenght;
	int	width;

	width = fg->width;
	width = (fg->width_used)?width - (int)ft_strlen(str):width;
	width = (fg->width_used && fg->precision > 0)\
			?width - (fg->precision-(int)ft_strlen(str)):width;
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
	if (!fg->space)
		return (0);
	//printf("\nfg->width_used = %d\n", fg->width_used);
	if (fg->space && fg->width_used && fg->precision > -1)
		return (0);
	if (fg->space && fg->width_used && fg->width <= fg->precision)
		return (0);
	if (fg->space && fg->width_used && fg->width <= (int)ft_strlen(str))
		return (0);
	ft_printf_putlstr(" ");
	return (1);
}
