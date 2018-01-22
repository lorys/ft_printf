/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:52:06 by llopez            #+#    #+#             */
/*   Updated: 2018/01/22 16:52:27 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_s(char const*restrict format, va_list ap, int *skip)
{
	char	*str;

	if (format[1] == 's')
	{
		str = va_arg(ap, char *);
		*skip += 2;
		ft_putstr(str);
		return (ft_strlen(str));
	}
	return (0);
}

int			ft_printf_c(char const*restrict format, va_list ap, int *skip)
{
	if (format[1] == 'c')
	{
		*skip += 2;
		ft_putchar(va_arg(ap, int));
		return (1);
	}
	return (0);
}
