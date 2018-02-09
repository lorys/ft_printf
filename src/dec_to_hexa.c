/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 21:40:01 by llopez            #+#    #+#             */
/*   Updated: 2018/02/09 19:04:14 by llopez           ###   ########.fr       */
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

int					ft_printf_ld(const char* format, va_list ap, int *skip,\
		t_arg *fg)
{
	int		lenght;
	long	nb;
	char	*str;

	lenght = 0;
	nb = 0;
	if (format[0] == 'D')
	{
		*skip += 2;
		nb = va_arg(ap, long);
		str = ft_printf_itoa_base((nb < 0)?nb * -1:nb, 10, 'a');
		fg->width = (fg->width > 0) ? fg->width - ft_strlen(str) : fg->width;
		fg->width = (fg->width > 0 && nb < 0) ? fg->width - 1 : fg->width;
		if (fg->space == 1 && fg->width == 0)
			lenght += ft_printf_putlstr(" ");
		if (fg->plus && nb >= 0)
			lenght += ft_printf_putlstr("+");
		lenght += ft_printf_width(fg, 0);
		lenght += (nb < 0)?ft_printf_putlstr("-"):0;
		lenght += ft_printf_putlstr(str);
		lenght += ft_printf_width(fg, 1);
		ft_initialize_struct(fg);
	}
	return (lenght);
}
int					ft_printf_d(const char* format, va_list ap, int *skip,\
		t_arg *fg)
{
	int				lenght;
	intmax_t		nb;
	char			*str;

	lenght = 0;
	nb = 0;
	if (format[0] == 'd' || format[0] == 'i')
	{
		if (fg->l)
			return (ft_printf_ld("D", ap, skip, fg));
		*skip += 2;
		nb = ft_printf_signed(ap, fg);
		str = ft_printf_itoa_base((nb < 0)?nb * -1:nb, 10, 'a');
		fg->width = (fg->width > 0) ? fg->width - ft_strlen(str) : fg->width;
		fg->width = (fg->width > 0 && nb < 0) ? fg->width - 1 : fg->width;
		if (fg->space == 1 && fg->width == 0)
			lenght += ft_printf_putlstr(" ");
		if (fg->plus && nb >= 0)
			lenght += ft_printf_putlstr("+");
		lenght += ft_printf_width(fg, 0);
		lenght += (nb < 0)?ft_printf_putlstr("-"):0;
		lenght += ft_printf_putlstr(str);
		lenght += ft_printf_width(fg, 1);
		ft_initialize_struct(fg);
	}
	return (lenght);
}

int					ft_get_precision(const char *str)
{
	int		i;

	i = 1;
	while (ft_isdigit(str[i]))
		i++;
	return (ft_atoi(ft_strndup(&str[1], i-1)));
}

int					ft_get_width(const char *str)
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
	return (ft_atoi(ft_strndup(&str[b], i)));
}
