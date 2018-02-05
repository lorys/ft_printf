/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hashtag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 09:01:28 by llopez            #+#    #+#             */
/*   Updated: 2018/02/05 18:18:24 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_add(int *nb, int plus)
{
	*nb += plus;
	return (1);
}

int			ft_printf_xX(char const*format, va_list ap,\
		int *skip, t_arg *fg)
{
	int		lenght;

	lenght = 0;
	if (format[0] == 'x' || format[0] == 'X')
	{
		if (fg->hfound == 1)
			lenght += ft_printf("0%c", format[0]);
		lenght += ft_printf_putlstr(ft_printf_itoa_base(\
					va_arg(ap, int), 16, format[0]));
		*skip += 2;
	}
	return (lenght);
}

int			ft_printf_oO(char const*format, va_list ap,\
		int *skip, t_arg *fg)
{
	int		lenght;

	lenght = 0;
	if (format[0] == 'o' || format[0] == 'O')
	{
		if (fg->hfound == 1)
			lenght += ft_printf("0");
		if (format[0] == 'o')
			lenght += ft_printf_putlstr(ft_printf_itoa_base(\
						va_arg(ap, uintmax_t), 8, format[0]));
		if (format[0] == 'O')
			lenght += ft_printf_putlstr(ft_printf_itoa_base(\
						va_arg(ap, uintmax_t), 8, format[0]));
		*skip += 2;
	}
	return (lenght);
}

int			ft_printf_width(t_arg *fg, int r)
{
	int lenght;

	lenght = 0;
	while (fg->width > 0 && fg->moins == r)
	{
		if (fg->zero)
			lenght += ft_printf_putlstr("0");
		else
			lenght += ft_printf_putlstr(" ");
		--fg->width;
	}
	return (lenght);
}
