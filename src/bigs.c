/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 23:36:01 by llopez            #+#    #+#             */
/*   Updated: 2018/04/05 01:57:39 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_wchar_one_o(char *a, wchar_t c)
{
	a[0] = (c >> 6) + 0xC0;
	a[1] = (c & 0x3F) + 0x80;
	write(1, a, 2);
}

void				ft_wchar_two_o(char *a, wchar_t c)
{
	a[0] = (c >> 12) + 0xE0;
	a[1] = ((c >> 6) & 0x3F) + 0x80;
	a[2] = (c & 0x3F) + 0x80;
	write(1, a, 3);
}

void				ft_wchar_tree_o(char *a, wchar_t c)
{
	a[0] = (c >> 18) + 0xF0;
	a[1] = ((c >> 12) & 0x3F) + 0x80;
	a[2] = ((c >> 6) & 0x3F) + 0x80;
	a[3] = (c & 0x3F) + 0x80;
	write(1, a, 4);
}

int					ft_wstrlen_unit(wchar_t *c)
{
	int		i;

	i = 0;
	if (c == NULL)
		return (0);
	while (c[i])
		i++;
	return (i);
}

int					ft_wstrlen(wchar_t *c)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (c == NULL)
		return (0);
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
	if ((c >= 0xD800 && c <= 0xDFFF) || c >= 0x10FFFE || c < 0)
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

int					ft_wcharlen(wchar_t c)
{
	if (!ft_valid_wchar(c))
		return (-1);
	if (c <= 0x7F)
		return (1);
	else if (c > 0x7F && c <= 0x7FF)
		return (2);
	else if (c > 0x7FF && c <= 0xFFFF)
		return (3);
	else
		return (4);
	return (-1);	
}

int					ft_printf_bigc(const char *format, va_list ap, 	int *skip, \
		t_arg *fg)
{
	wchar_t c;
	int		len;
	int		tmp;

	len = 0;
	tmp = 0;
	if (format[0] == 'C' || (format[0] == 'c' && fg->l))
	{
		*skip += 2;
		c = va_arg(ap, wchar_t);
		len += ft_printf_width_wchar(fg, 0, c);
		tmp = ft_putwchar(c);
		len += tmp;
		len += ft_printf_width_wchar(fg, 1, c);
		return ((tmp >= -1) ? len : tmp);
	}
	return (0);
}

wchar_t			*ft_fill_null(wchar_t *str)
{
	str = (wchar_t *)malloc(sizeof(wchar_t) * 7);
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'u';
	str[3] = 'l';
	str[4] = 'l';
	str[5] = ')';
	str[6] = '\0';
	return (&str[0]);
}

int				ft_printf_bigs(const char *format, va_list ap, 	int *skip, \
		t_arg *fg)
{
	wchar_t		*str;
	int			len_str;
	int			width;
	wchar_t		*str_char;

	len_str = 0;
	(void)str;
	if (format[0] == 'S' || (format[0] == 's' && fg->l))
	{
		str_char = NULL;
		str_char = ft_fill_null(str_char);
		width = fg->width;
		*skip += 2;
		str = va_arg(ap, wchar_t *);
		fg->precision = ((int)ft_wstrlen(str) > fg->precision &&\
				fg->precision > 0) ? fg->precision : (int)ft_wstrlen(str);
		fg->precision = (str != NULL) ? fg->precision : \
						(int)ft_wstrlen(str_char);
		len_str += ft_printf_width(fg, 0, NULL, (str == NULL) ? \
				ft_subwstrlen(str_char, fg->precision) : \
				ft_subwstrlen(str, fg->precision));
		len_str += (str == NULL) ? ft_putsubwstr(str_char, fg->precision)\
				   : ft_putsubwstr(str, fg->precision);
		len_str += ft_printf_width(fg, 1, NULL, (str == NULL) ? \
				ft_subwstrlen(str_char, fg->precision) : \
				ft_subwstrlen(str, fg->precision));
		free(str_char);
	}
	return (len_str);
}
