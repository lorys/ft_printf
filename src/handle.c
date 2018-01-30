/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:52:06 by llopez            #+#    #+#             */
/*   Updated: 2018/01/30 15:21:22 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_s(char const*format, va_list ap, int *skip, t_arg *fg)
{
	char	*str;

	(void)fg;
	if (format[0] == 's')
	{
		str = va_arg(ap, char *);
		*skip += 2;
		return (ft_printf_putlstr(str));
	}
	return (0);
}

int			ft_printf_c(char const*format, va_list ap, int *skip, t_arg *fg)
{
	(void)fg;
	if (format[0] == 'c')
	{
		*skip += 2;
		ft_putchar(va_arg(ap, int));
		return (1);
	}
	return (0);
}

int			ft_printf_flags(char const*format, int *skip, t_arg *fg)
{
	int		lenght;

	lenght = 0;
	while (ft_strchr("sSpdDioOuUxXcC", format[lenght]) == NULL\
			&& format[lenght])
	{
		if (format[lenght] == '#' && ++*skip)
			fg->hfound = 1;
		if (format[lenght] == '0' && ++*skip)
			fg->zero = 1;
		if (format[lenght] == '-' && ++*skip)
			fg->moins = 1;
		if (format[lenght] == '+' && ++*skip)
			fg->plus = 1;
		if (format[lenght] == ' ' && ++*skip)
			fg->space = 1;
		lenght++;
	}
	//printf("\n-----------\nhfound = %d\nplus = %d\nmoins = %d\nspace = %d\nzero = %d\n", fg->hfound, fg->plus, fg->moins, fg->space, fg->zero);
	return (lenght);
}

int			ft_printf_uU(char const*format, va_list ap, int *skip, t_arg *fg)
{
	(void)fg;
	if (format[0] == 'u' || format[0] == 'U')
	{
		*skip += 2;
		if (format[0] == 'u')
			return (ft_printf_putlstr(ft_printf_itoa_base(\
							va_arg(ap, unsigned int), 10, 'a')));
		if (format[0] == 'U')
			return (ft_printf_putlstr(ft_printf_itoa_base(\
							va_arg(ap, long unsigned int), 10, 'a')));
	}
	return (0);
}

int			ft_printf_i(char const*format, va_list ap, int *skip, t_arg *fg)
{
	int		nb;

	(void)fg;
	if (format[0] == 'i')
	{
		*skip += 2;
		nb = va_arg(ap, int);
		ft_putnbr(nb);
		return ((int)ft_strlen(ft_itoa(nb)));
	}
	return (0);
}

void		ft_initialize_struct(t_arg *fg)
{
	fg->hh = 0;
	fg->h = 0;
	fg->l = 0;
	fg->ll = 0;
	fg->j = 0;
	fg->z = 0;
	fg->width = 0;
	fg->precision = 0;
	fg->min = 0;
	fg->max = 0;
	fg->hfound = 0;
	fg->moins = 0;
	fg->plus = 0;
	fg->space = 0;
	fg->zero = 0;
}
