/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 04:20:35 by llopez            #+#    #+#             */
/*   Updated: 2017/12/18 19:08:18 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

static int		ft_format(const char *str, va_list ap)
{
	int		i;
	int		found_fmt;

	i = 0;
	found_fmt = 0;
	if (str[i] == '%')
		if (str[i + 1] == 's' && found_fmt++)
			ft_putstr(va_arg(ap, char *));
		else if (str[i + 1] == 'd' && found_fmt++)
			ft_putstr(ft_itoa(va_arg(ap, int)));
		else if (str[i + 1] == '%' && found_fmt++)
			ft_putchar('%');
		else if (str[i + 1] == 'c' && found_fmt++)
			ft_putchar(va_arg(ap, char));	
	return (found_fmt > 0);
}

int		ft_printf(const char * restrict format, ...)
{
	va_list	ap;
	char	*s;
	int		i;

	i = 0;
	va_start(ap, format);
	while (format[i])
		if (ft_format(&format[i], ap) == 0)
			ft_putchar(format[i++]);
		else
			i = i + 2;
	va_end(ap);
	return (1);
}
