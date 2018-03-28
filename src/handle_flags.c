/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:13:47 by llopez            #+#    #+#             */
/*   Updated: 2018/03/28 18:27:46 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_flags(char const *format, int *skip, t_arg *fg)
{
	int		lenght;
	int		first_width;
	int		last_width;
	int		pass_precision;

	pass_precision = 0;
	lenght = 0;
	first_width = -1;
	last_width = 0;
	while (ft_strchr("sSpdDioOuUxXcC%", format[lenght]) == NULL\
			&& format[lenght])
	{
		*skip = (ft_strchr("#0-+ hljz.123456789", format[lenght])) ? \
				*skip + 1 : *skip;
		first_width = (ft_isdigit(format[lenght])\
				&& format[lenght] != '0' && first_width == -1) ? \
					lenght : first_width;
		last_width = (ft_isdigit(format[lenght])\
				&& first_width > -1) ? last_width + 1 : last_width;
		if (format[lenght] == '#')
			fg->hfound = 1;
		if (format[lenght] == '0' && !ft_isdigit(format[lenght - 1])\
				&& !pass_precision)
			fg->zero = 1;
		if (format[lenght] == '-')
			fg->moins = 1;
		if (format[lenght] == '+')
			fg->plus = 1;
		if (format[lenght] == ' ')
			fg->space = 1;
		if (format[lenght] == 'h' && format[lenght + 1] == 'h')
			fg->hh = 1;
		if (format[lenght] == 'l' && format[lenght + 1] == 'l')
			fg->ll = 1;
		if (fg->hh == 0 && format[lenght] == 'h')
			fg->h = 1;
		if (fg->ll == 0 && format[lenght] == 'l')
			fg->l = 1;
		if (format[lenght] == 'j')
			fg->j = 1;
		if (format[lenght] == 'z')
			fg->z = 1;
		if (format[lenght] == '.' && ++pass_precision)
			fg->precision = ft_get_precision(&format[lenght]);
		lenght++;
	}
	fg->flag = format[lenght];
	fg->width = ft_get_width(&format[0], fg);
	return (lenght);
}
