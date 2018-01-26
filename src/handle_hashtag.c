/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hashtag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 09:01:28 by llopez            #+#    #+#             */
/*   Updated: 2018/01/26 18:09:41 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_hashtag_xX(char const*format, va_list ap,\
		int *skip)
{
	int		lenght;

	lenght = 0;
	if ((format[0] == 'x' || format[0] == 'X'))
		lenght += ft_printf("0%c", format[0]);
	if (format[0] == 'x')
		lenght += ft_printf_putlstr(ft_printf_itoa_base(va_arg(ap, uintmax_t),\
					16, 'a'));
	if (format[0] == 'X')
		lenght += ft_printf_putlstr(ft_printf_itoa_base(va_arg(ap, uintmax_t),\
					16, 'A'));
	*skip = (lenght > 0) ? (*skip + 3) : *skip;
	return (lenght);
}

int			ft_printf_hashtag_oO(char const*format, va_list ap,\
		int *skip)
{
	int		lenght;

	lenght = 0;
	if ((format[0] == 'o' || format[0] == 'O'))
		lenght += ft_printf("0");
	if (format[0] == 'o')
		lenght += ft_printf_putlstr(ft_printf_itoa_base(va_arg(ap, uintmax_t),\
					8, 'a'));
	if (format[0] == 'O')
		lenght += ft_printf_putlstr(ft_printf_itoa_base(va_arg(ap, uintmax_t),\
					8, 'A'));
	*skip = (lenght > 0) ? (*skip + 3) : *skip;
	return (lenght);
}
