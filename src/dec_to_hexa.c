/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 21:40:01 by llopez            #+#    #+#             */
/*   Updated: 2018/02/02 20:07:09 by llopez           ###   ########.fr       */
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
		fg->width = (fg->width > 0 && fg->width > (int)ft_strlen(conv))?fg->width-(int)ft_strlen(conv)-2:0;
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

int					ft_printf_d(const char* format, va_list ap, int *skip, t_arg *fg)
{
	int		lenght;
	int		nb;

	lenght = 0;
	nb = 0;
	if (format[0] == 'd')
	{
		nb = va_arg(ap, int);
		fg->width = (fg->width > 0) ? fg->width - ft_intlen(nb) : fg->width;
		if (fg->space && fg->zero && fg->width > 0 && fg->width--)
			lenght += ft_printf_putlstr(" ");
		*skip += 2;
		ft_printf_width(fg, 1);
		lenght += ft_intlen(nb);
		ft_putnbr(nb);
		ft_printf_width(fg, 0);
		ft_initialize_struct(fg);
	}
	return (lenght);
}
