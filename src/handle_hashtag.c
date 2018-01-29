/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hashtag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 09:01:28 by llopez            #+#    #+#             */
/*   Updated: 2018/01/29 16:30:18 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_xX(char const*format, va_list ap,\
		int *skip, t_arg *fg)
{
	int		lenght;

	lenght = 0;
	if (format[0] == 'x' || format[0] == 'X')
	{
		if (fg->hfound == 1)
			lenght += ft_printf("0%c", format[1]);
		if (format[0] == 'x')
			lenght += ft_printf_putlstr(ft_printf_itoa_base(\
						va_arg(ap, uintmax_t), 16, format[0]));
		if (format[0] == 'X')
			lenght += ft_printf_putlstr(ft_printf_itoa_base(\
						va_arg(ap, uintmax_t), 16, format[0]));
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
		*skip = (lenght > 0) ? (*skip + 3) : *skip;
	}
	return (lenght);
}
