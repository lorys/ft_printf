/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:52:06 by llopez            #+#    #+#             */
/*   Updated: 2018/02/15 16:50:37 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_percent(char const*format, int *skip, t_arg *fg)
{
	char	*str;
	int		len_str;

	len_str = 0;
	if (format[0] == '%')
	{
		str = ft_strdup("%");
		*skip += 2;
		len_str = ft_printf_width_str(fg, 0, str) + ft_printf_putlstr(str) +\
		ft_printf_width_str(fg, 1, str);
	}
	return (len_str);
}

int			ft_printf_width_str(t_arg *fg, int r, char *str)
{
	int		len_str;
	int		width;

	width = fg->width;
	len_str = 0;
	if (fg->width_used && r == fg->moins)
	{
		if ((fg->flag == 'u' || fg->flag == 'U') && fg->moins\
				&& fg->precision > fg->width)
			return (0);
		fg->precision = (fg->moins)?0:fg->precision;
		width = width - (int)ft_strlen(str);
		if (!fg->moins && fg->precision > (int)ft_strlen(str) &&\
				width-(fg->precision-(int)ft_strlen(str)) >= 0)
			width = width - (fg->precision-(int)ft_strlen(str));
		while (width > 0)
		{
			len_str += ft_printf_putlstr((fg->zero)?"0":" ");
			--width;
		}
	}
	return (len_str);
}

int			ft_printf_s(char const*format, va_list ap, int *skip, t_arg *fg)
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

		len_str = ft_printf_width_str(fg, 0, str) + ft_printf_putlstr(str) +\
		ft_printf_width_str(fg, 1, str);
	}
	return (len_str);
}

int			ft_printf_c(char const*format, va_list ap, int *skip, t_arg *fg)
{
	int	len;

	len = 0;
	if (format[0] == 'c')
	{
		*skip += 2;
		len += ft_printf_width_str(fg, 0, "0");
		ft_putchar(va_arg(ap, int));
		len += ft_printf_width_str(fg, 1, "0") + 1;  
	}
	return (len);
}

int			ft_printf_flags(char const*format, int *skip, t_arg *fg)
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
		*skip = (ft_strchr("#0-+ hljz.123456789", format[lenght]))?\
				*skip + 1 : *skip;
		first_width = (ft_isdigit(format[lenght])\
				&& format[lenght] != '0' && first_width == -1)?\
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
	//printf("\n-----------\nwidth_used = %d\nprecision = %d\nwidth = %d\nhfound = %d\nplus = %d\nmoins = %d\nspace= %d\nzero = %d\nh= %d\nhh= %d\nl= %d\nll= %d\nj= %d\nz= %d\n", fg->width_used, fg->precision, fg->width, fg->hfound, fg->plus, fg->moins, fg->space, fg->zero, fg->h, fg->hh, fg->l, fg->ll, fg->j, fg->z);
	return (lenght);
}

int			ft_printf_uu(char const*format, va_list ap, int *skip, t_arg *fg)
{
	int		len;
	char	*str;

	len = 0;
	if (format[0] == 'u' || format[0] == 'U')
	{
		str = ft_printf_itoa_base(ft_printf_unsigned(ap, fg), 10, 'a');
		*skip += 2;
		fg->zero = (fg->precision > -1)?0:fg->zero;	
		len += ft_printf_width_str(fg, 0, str);
		len += ft_printf_precision(fg, (int)ft_strlen(str));
		len += (str[0] == '0' && fg->precision == 0)?0:ft_printf_putlstr(str);
		len += ft_printf_width_str(fg, 1, str);
	}
	return (len);
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
	fg->precision = -1;
	fg->min = 0;
	fg->max = 0;
	fg->hfound = 0;
	fg->moins = 0;
	fg->plus = 0;
	fg->space = 0;
	fg->zero = 0;
	fg->width_used = 0;
	fg->flag = 0;
}
