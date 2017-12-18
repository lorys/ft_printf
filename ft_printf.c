/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 04:20:35 by llopez            #+#    #+#             */
/*   Updated: 2017/12/18 07:48:36 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

static int		ft_format(const char *str, va_list ap)
{
	int		i;

	i = 0;
	if (str[i] == '%')
	{
		if (str[i + 1] == 's')
		{
			ft_putstr(va_arg(ap, char *));
			return (1);
		}
		else if (str[i + 1] == 'd')
		{
			ft_putstr(ft_itoa(va_arg(ap, int)));
			return (1);
		}
	}
	return (0);
}

int		ft_printf(const char * restrict format, ...)
{
	va_list	ap;
	char	*s;
	int		i;

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (ft_format(&format[i], ap) == 0)
			ft_putchar(format[i]);
		else
			i++;
		i++;
	}
	va_end(ap);
	return (1);
}
