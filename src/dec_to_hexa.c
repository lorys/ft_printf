/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 21:40:01 by llopez            #+#    #+#             */
/*   Updated: 2018/01/22 16:28:30 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_printf_itoa_base(uintmax_t nb, unsigned int base,\
		int type)
{
	int				i;
	static char		str[64];

	i = 62;
	while (nb > 0 && i > 0)
	{
		if (type == 'A')
			str[i] = "0123456789ABCDEF"[nb % base];
		else
			str[i] = "0123456789abcdef"[nb % base];
		nb /= base;
		--i;
	}
	return (str + i + 1);
}

int					ft_printf_p(const char *format, va_list ap,\
		int *skip)
{
	int		i;

	if (format[1] == 'p')
	{
		*skip += 2;
		i = ft_printf_putlstr("0x");
		i += ft_printf_putlstr(ft_printf_itoa_base((uintmax_t)va_arg(ap, void *),\
					16, 'a'));
		return (i);
	}
	return (0);
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

int					ft_printf_d(const char* format, va_list ap, int *skip)
{
	int		lenght;
	int		nb;

	lenght = 0;
	if (format[1] == 'd')
	{
		nb = va_arg(ap, int);
		*skip += 2;
		lenght += ft_intlen(nb);
		ft_putnbr(nb);
	}
	return (lenght);
}
