/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:12:47 by llopez            #+#    #+#             */
/*   Updated: 2018/04/02 20:44:25 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_rest_s_flag(t_arg *fg, char *str)
{
	int len_str;

	len_str = ft_printf_width_str(fg, 0, str);
	while (fg->precision > 0 && fg->precision > (int)ft_strlen(str) \
			&& fg->width_used && !fg->moins)
	{
		len_str++;
		ft_putchar(' ');
		fg->precision--;
	}
	len_str += (ft_printf_putlstr(str) + ft_printf_width_str(fg, 1, str));
	return (len_str);
}

int			ft_printf_s(char const *format, va_list ap, int *skip, t_arg *fg)
{
	char	*str;
	int		len_str;
	char	*str_new;

	len_str = 0;
	if (format[0] == 's')
	{
		*skip += 2;
		str = va_arg(ap, char *);
		if (str == NULL)
		{
			free(str);
			str = ft_strdup("(null)");
		}
		if (fg->precision > -1)
		{
			str_new = ft_strndup(&str[0], fg->precision);
			str = ft_strdup(str_new);
			free(str_new);
		}
		len_str += ft_rest_s_flag(fg, str);
	}
	return (len_str);
}
