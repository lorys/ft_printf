/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 23:36:01 by llopez            #+#    #+#             */
/*   Updated: 2018/04/03 16:51:47 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

void				ft_wchar_one_o(char *a, wchar_t c)
{
	a[0] = (c >> 6) + 0xC0;
	a[1] = (c & 0x3F) + 0x80;
	write(1, &a[0], 1);
	write(1, &a[1], 1);
}

void				ft_wchar_two_o(char *a, wchar_t c)
{
	a[0] = (c >> 12) + 0xE0;
	a[1] = ((c >> 6) & 0x3F) + 0x80;
	a[2] = (c & 0x3F) + 0x80;
	write(1, &a[0], 1);
}

void				ft_wchar_tree_o(char *a, wchar_t c)
{
	a[0] = (c >> 18) + 0xF0;
	a[1] = ((c >> 12) & 0x3F) + 0x80;
	a[2] = ((c >> 6) & 0x3F) + 0x80;
	a[3] = (c & 0x3F) + 0x80;
	write(1, &a[0], 1);
	write(1, &a[1], 1);
	write(1, &a[2], 1);
	write(1, &a[3], 1);
}

int					ft_wstrlen(wchar_t *c)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (c[i])
	{
		if (c[i] <= 0x7F)
			len += 1;
		else if (c[i] > 0x7F && c[i] <= 0x7FF)
			len += 2;
		else if (c[i] > 0x7FF && c[i] <= 0xFFFF)
			len += 3;
		else
			len += 4;
		i++;
	}
	return (len);
}

int					ft_valid_wchar(wchar_t c)
{
	if ((c >= 0xD800 && c <= 0xDFFF) || (c >= 0xFDD0 && c <= 0xFDEF) ||
		(c >= 0xFFFE && c <= 0xFFFF) || (c >= 0x1FFFE && c <= 0x1FFFF) ||
		(c >= 0x2FFFE && c <= 0x2FFFF) || (c >= 0xEFFFE && c <= 0xEFFFF) ||
		(c >= 0xFFFFE && c <= 0xFFFFF) || (c >= 0x10FFFE && c <= 0x10FFFF))
		return (0);
	return (1);
}

int					ft_putwchar(wchar_t c)
{
	char	a[4];

	if (!ft_valid_wchar(c))
		return (-1);
	if (c <= 0x7F)
		write(1, &c, 1);
	else if (c > 0x7F && c <= 0x7FF)
	{
		ft_wchar_one_o(a, c);
		return (2);
	}
	else if (c > 0x7FF && c <= 0xFFFF)
	{
		ft_wchar_two_o(a, c);
		return (3);
	}
	else {
		ft_wchar_tree_o(a, c);
		return (4);
	}
	return (1);
}

int					ft_printf_bigc(const char *format, va_list ap, 	int *skip, \
		t_arg *fg)
{
	wchar_t c;
	int		len;

	len = 0;
	if (format[0] == 'C' || (format[0] == 'c' && fg->l))
	{
		*skip += 2;
		setlocale(LC_ALL, "");
		c = (wchar_t)ft_printf_unsigned(ap, fg);
		len += ft_printf_width_str(fg, 0, "0");
		len += ft_putwchar(c);
		len += ft_printf_width_str(fg, 1, "0");
		return (len);
	}
	return (0);
}

int				ft_printf_bigs(const char *format, va_list ap, 	int *skip, \
		t_arg *fg)
{
	wchar_t	*str;
	int		i;
	int		len_str;
	int		width;

	i = 0;
	len_str = 0;
	if (format[0] == 'S' || (format[0] == 's' && fg->l))
	{
		width = fg->width;
		*skip += 2;
		str = (wchar_t *)va_arg(ap, wchar_t *);	
		while (str[i] != '\0')
		{
			printf("\n%d\n", i);
			len_str += ft_putwchar(str[i]);
			i++;
		}
	}
	return (len_str);
}
