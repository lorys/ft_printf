/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 23:36:01 by llopez            #+#    #+#             */
/*   Updated: 2018/04/01 21:07:28 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int					ft_putwchar(wchar_t c)
{
	char	a;
	char	b;
	char	cb;
	char	d;

	if (c <= 0x7F)
		write(1, &c, 1);
	else if (c > 0x7F && c <= 0x7FF)
	{
		a = (c >> 6) + 0xC0;
		b = (c & 0x3F) + 0x80;
		write(1, &a, 1);
		write(1, &b, 1);
		return (2);
	}
	else if (c > 0x7FF && c <= 0xFFFF)
	{
		a = (c >> 12) + 0xE0;
		b = ((c >> 6) & 0x3F) + 0x80;
		cb = (c & 0x3F) + 0x80;
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, &cb, 1);
		return (3);
	}
	else {
		a = (c >> 18) + 0xF0;
		b = ((c >> 12) & 0x3F) + 0x80;
		cb = ((c >> 6) & 0x3F) + 0x80;
		d = (c & 0x3F) + 0x80;
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, &cb, 1);
		write(1, &d, 1);
		return (4);
	}
	return (1);
}

int					ft_printf_bigc(const char *format, va_list ap, 	int *skip, \
		t_arg *fg)
{
	wchar_t c;

	(void)fg;
	(void)skip;
	if (format[0] == 'C' || (format[0] == 'c' && fg->l))
	{
		*skip += 2;
		setlocale(LC_ALL, "");
		c = (wchar_t)ft_printf_unsigned(ap, fg);
		return (ft_printf_width_str(fg, 0, "0") + ft_putwchar(c) + \
				ft_printf_width_str(fg, 1, "0"));
	}
	return (0);
}

int				ft_printf_bigs(const char *format, va_list ap, 	int *skip, \
		t_arg *fg)
{
	wchar_t c;

	(void)skip;
	(void)ap;
	(void)c;
	if (format[0] == 'S' || (format[0] == 's' && fg->l))
	{


	}
	return (0);
}
