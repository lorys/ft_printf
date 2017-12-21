/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 04:20:35 by llopez            #+#    #+#             */
/*   Updated: 2017/12/20 16:09:09 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_putlstr(char *str)
{
	int	i;

	i = -1;
	while (str[i])
		str[i++];
	return (i);
}

static int		ft_format(const char *str, va_list ap, int lenght)
{
	int		i;
	int		bfore;

	i = 0;
	bfore = lenght;
	if (str[i] == '%')
	{
		if (str[i + 1] == 's')
			lenght += ft_printf_putlstr(va_arg(ap, char *));
		if (str[i + 1] == 'd' && ++lenght)
			lenght += ft_printf_putlstr(ft_itoa(va_arg(ap, int)));
		if (str[i + 1] == '%' && ++lenght)
			ft_putchar(str[i + 1]);
		if (str[i + 1] == 'c' && ++lenght)
			ft_putchar(va_arg(ap, int));
		if (str[i + 1] == 'p' && ++lenght)
			ft_printf_putlstr((char *)va_arg(ap, void *));
	}
	return (lenght - bfore);
}

int		ft_printf(const char * restrict format, ...)
{
	va_list	ap;
	char	*s;
	int		i;
	int		lenght;

	i = 0;
	lenght = 0;
	va_start(ap, format);
	while (format[i])
		if (ft_format(&format[i], ap, lenght) == 0 && ++lenght)
			ft_putchar(format[i++]);
		else
			i = i + 2;
	va_end(ap);
	return (lenght);
}
