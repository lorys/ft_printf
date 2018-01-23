/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:52:06 by llopez            #+#    #+#             */
/*   Updated: 2018/01/23 14:09:19 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_s(char const*format, va_list ap, int *skip)
{
	char	*str;

	if (format[1] == 's')
	{
		str = va_arg(ap, char *);
		*skip += 2;
		return (ft_printf_putlstr(str));
	}
	return (0);
}

int			ft_printf_c(char const*format, va_list ap, int *skip)
{
	if (format[1] == 'c')
	{
		*skip += 2;
		ft_putchar(va_arg(ap, int));
		return (1);
	}
	return (0);
}

int			ft_printf_hashtag(char const*format, va_list ap, int *skip)
{
	int		lenght;

	lenght = 0;
	if (format[1] == '#')
	{
		lenght += ft_printf_hashtag_xX(&format[2], ap, skip);
		lenght += ft_printf_hashtag_oO(&format[2], ap, skip);
	}
	return (lenght);
}

int			ft_printf_o(char const*format, va_list ap, int *skip)
{
	if (format[1] == 'o')
	{
		*skip += 2;
		return (ft_printf_putlstr(ft_printf_itoa_base(va_arg(ap, uintmax_t), 8,\
						'a')));
	}
	return (0);
}
