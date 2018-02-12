/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 21:40:01 by llopez            #+#    #+#             */
/*   Updated: 2018/02/12 21:30:23 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_printf_itoa_base(uintmax_t nb, unsigned int base,\
		int type)
{
	int				i;
	static char		str[64];

	i = 62;
	if (nb == 0)
		return (ft_strdup("0"));
	while (nb > 0 && i > 0)
	{
		if (type >= 'A' && type <= 'Z')
			str[i] = "0123456789ABCDEF"[nb % base];
		else if (type >= 'a' && type <= 'z')
			str[i] = "0123456789abcdef"[nb % base];
		nb /= base;
		--i;
	}
	return (str + i + 1);
}

int					ft_printf_p(const char *format, va_list ap,\
		int *skip, t_arg *fg)
{
	int		i;
	void 	*nb;
	char	*conv;

	i = 0;
	if (format[0] == 'p')
	{
		nb = va_arg(ap, void *);
		conv = ft_printf_itoa_base((uintmax_t)nb, 16, 'a');
		*skip += 2;
		fg->width = (fg->width > 0 && fg->width > (int)ft_strlen(conv))?\
					fg->width-(int)ft_strlen(conv)-2:0;
		i += ft_printf_width(fg, 0);
		i += ft_printf_putlstr("0x");
		i += ft_printf_putlstr(conv);
		i += ft_printf_width(fg, 1);
	}
	return (i);
}

int					ft_printf_putnbr_base(long nb, unsigned int base)
{
	int		i;

	if (nb < 0)
	{
		nb *= -1;
		i = ft_printf_putlstr("-");
	}
	else
		i = 0;
	i += ft_printf_putlstr(ft_printf_itoa_base(nb, base, 'a'));
	return (i);
}

int					ft_printf_d(const char* format, va_list ap, int *skip,\
		t_arg *fg)
{
	int				lenght;
	intmax_t		nb;
	char			*str;

	lenght = 0;
	nb = 0;
	if (format[0] == 'd' || format[0] == 'D' || format[0] == 'i')
	{
		fg->l = (fg->l ==  0 && format[0] == 'D')?1:fg->l;
		*skip += 2;
		nb = ft_printf_signed(ap, fg);
		str = ft_printf_itoa_base((nb < 0)?nb * -1:nb, 10, 'a');
		fg->zero = (fg->precision > 0)?0:fg->zero;
		fg->width = (fg->width > 0)?fg->width - (int)ft_strlen(str):fg->width;
		fg->width = (fg->width > 0 && fg->precision > 0)\
				?fg->width - (fg->precision-(int)ft_strlen(str)):fg->width;
		fg->width = (fg->width > 0 && (nb < 0 || fg->plus)\
				&& fg->precision < fg->width) ?fg->width - 1 : fg->width;
		fg->width = (fg->width > 0 && fg->space && fg->zero)?fg->width-1:fg->width;
		lenght += ft_printf_putspace(fg, str);
		lenght += (fg->plus && nb >= 0 && fg->width == 0)?ft_printf_putlstr("+"):0;
		lenght += (!fg->zero)?ft_printf_width(fg, 0):0;
		lenght += (fg->plus && nb >= 0 && fg->width > 0)?ft_printf_putlstr("+"):0;
		lenght += (nb < 0)?ft_printf_putlstr("-"):0;
		lenght += (fg->zero && fg->width > 0)?ft_printf_width(fg, 0):ft_printf_precision(fg, (int)ft_strlen(str));
		lenght += (nb == 0 && fg->precision == 0)?0:ft_printf_putlstr(str);
		lenght += ft_printf_width(fg, 1);
		ft_initialize_struct(fg);
	}
	return (lenght);
}

int					ft_get_precision(const char *str)
{
	int		i;

	i = 1;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	return (ft_atoi(ft_strndup(&str[1], i-1)));
}

int					ft_get_width(const char *str, t_arg *fg)
{
	int		i;
	int		b;

	b = 0;
	while (ft_strchr("#0-+ hljz", str[b]))
		b++;
	i = b;
	while (ft_isdigit(str[i]))
		i++;
	if (i == 0)
		return (0);
	fg->width_used = 1;
	return (ft_atoi(ft_strndup(&str[b], i)));
}
