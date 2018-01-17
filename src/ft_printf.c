/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 04:20:35 by llopez            #+#    #+#             */
/*   Updated: 2018/01/17 19:00:11 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf_putlstr(char *str)
{
	int	i;

	i = 0;
	ft_putstr(str);
	return ((int)ft_strlen(str));
}

int				ft_printf_getnb(int nb, int n)
{
	while (n-- > 0)
		if (nb >= 10)
			nb /= 10;
	nb %= 10;
	return (nb);
}

static int		ft_addc(int *skip, int add)
{
	*skip += add;
	return (1);
}

static int		*ft_format(const char *str, va_list ap, int *lenght)
{
	int		i;
	int		bfore;
	int		*skip;

	skip = (int *)malloc(sizeof(int) * 2);
	i = 0;
	skip[1] = 0;
	bfore = *lenght;
	if (str[i] == '%')
	{
		if (str[i + 1] == 's' && ft_addc(&skip[1], 2))
			*lenght += ft_printf_putlstr(va_arg(ap, char *));
		if (str[i + 1] == 'd' && ++*lenght && ft_addc(&skip[1], 2))
			*lenght += ft_printf_putlstr(ft_itoa(va_arg(ap, int)));
		if (str[i + 1] == 'c' && ++*lenght && ft_addc(&skip[1], 2))
			ft_putchar(va_arg(ap, int));
		if (str[i + 1] == 'p' && ft_addc(&skip[1], 2))
			lenght += ft_printf_puthexa(va_arg(ap, unsigned int), 16);
		if (str[i + 1] == 'z' && str[i + 2] == 'u' && ft_addc(&skip[1], 3))
			lenght += ft_printf_putnbr_base(va_arg(ap, unsigned int), 10);
		if (str[i + 1] == '%' && ++*lenght && ft_addc(&skip[1], 2))
			ft_putchar(str[i + 1]);
	}
	skip[0] = (*lenght - bfore);
	return (skip);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int			i;
	int			lenght;
	int			*retrn;

	i = 0;
	lenght = 0;
	va_start(ap, format);
	while (format[i])
	{
		retrn = ft_format(&format[i], ap, &lenght);
		if (retrn[0] == 0 && ++lenght)
		{
			ft_putchar(format[i]);
			i += 1;
		}
		else
			i += retrn[1];
		free(retrn);
	}
	va_end(ap);
	return (lenght);
}
