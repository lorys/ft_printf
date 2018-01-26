/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:52:06 by llopez            #+#    #+#             */
/*   Updated: 2018/01/26 18:09:44 by llopez           ###   ########.fr       */
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

int			ft_printf_flags(char const*format, va_list ap, int *skip, t_arg *fg)
{
	int		lenght;
	int		i;

	lenght = 0;
	if (ft_strchr(format, '#'))
		fg->hfound = 1;
	if (ft_strchr(format, '+'))
		fg->plus = 1;
	if (ft_strchr())
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

int			ft_printf_u(char const*format, va_list ap, int *skip)
{
	if (format[1] == 'u')
	{
		*skip += 2;
		return (ft_printf_putlstr(ft_printf_itoa_base(va_arg(ap, unsigned int),\
					10, 'a')));
	}
	return (0);
}

int			ft_printf_i(char const*format, va_list ap, int *skip)
{
	int		nb;

	if (format[1] == 'i')
	{
		*skip += 2;
		nb = va_arg(ap, int);
		ft_putnbr(nb);
		return ((int)ft_strlen(ft_itoa(nb)));
	}
	return (0);
}
