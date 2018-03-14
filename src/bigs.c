/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 23:36:01 by llopez            #+#    #+#             */
/*   Updated: 2018/03/14 16:35:02 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int					ft_putwchar(wchar_t c)
{
	if (c <= 0x7F)
	{
		ft_printf("%c", (int)c);
	}
	return (0);
}

int					ft_printf_bigc(const char *format, va_list ap, \
		int *skip, t_arg *fg)
{
	wchar_t c;

	(void)fg;
	(void)skip;
	if (format[0] == 'C')
	{
		*skip += 2;
		setlocale(LC_ALL, "");
		c = (wchar_t)ft_printf_unsigned(ap, fg);
		if (c <= 0x7F)
		{
			ft_printf("%c", (int)c);
		}
	}
	return (0);
}
