/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:52:06 by llopez            #+#    #+#             */
/*   Updated: 2018/02/02 20:15:33 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_s(char const*format, va_list ap, int *skip, t_arg *fg)
{
	char	*str;

	(void)fg;
	if (format[0] == 's')
	{
		str = va_arg(ap, char *);
		*skip += 2;
		return (ft_printf_putlstr(str));
	}
	return (0);
}

int			ft_printf_c(char const*format, va_list ap, int *skip, t_arg *fg)
{
	if (format[0] == 'c')
	{
		*skip += 2;
		fg->width = (fg->width > 0)?fg->width - 1:fg->width;
		ft_printf_width(fg, 0);
		ft_putchar(va_arg(ap, int));
		ft_printf_width(fg, 1);
		return (1);
	}
	return (0);
}

int			ft_printf_flags(char const*format, int *skip, t_arg *fg)
{
	int		lenght;
	int		first_width;
	int		last_width;
	char	*width_nb;

	lenght = 0;
	first_width = -1;
	last_width = 0;
	while (ft_strchr("sSpdDioOuUxXcC", format[lenght]) == NULL\
			&& format[lenght])
	{
		*skip = (ft_strchr("#0-+ hljz", format[lenght]))? *skip + 1 : *skip;
		*skip = ((format[lenght] == 'h' && format[lenght + 1] == 'h') ||\
				(format[lenght] == 'l' && format[lenght + 1] == 'l'))?*skip+3:\
				*skip;
		first_width = (ft_isdigit(format[lenght])\
				&& format[lenght] != '0' && first_width == -1 && ++*skip)?\
					  lenght : first_width;
		last_width = (ft_isdigit(format[lenght])\
				&& first_width > -1) ? last_width + 1 : last_width;
		if (format[lenght] == '#')
			fg->hfound = 1;
		if (format[lenght] == '0' && !ft_isdigit(format[lenght - 1]))
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
		lenght++;
	}
		if (first_width > -1)
		{
			width_nb = ft_strndup(&format[first_width], last_width);
			fg->width = ft_atoi(width_nb);
		}
		//printf("\n-----------\nwidth = %d\nhfound = %d\nplus = %d\nmoins = %d\nspace= %d\nzero = %d\nh= %d\nhh= %d\nl= %d\nll= %d\nj= %d\nz= %d\n", fg->width, fg->hfound, fg->plus, fg->moins, fg->space, fg->zero, fg->h, fg->hh, fg->l, fg->ll, fg->j, fg->z);
	return (lenght);
}

int			ft_printf_uU(char const*format, va_list ap, int *skip, t_arg *fg)
{
	(void)fg;
	if (format[0] == 'u' || format[0] == 'U')
	{
		*skip += 2;
		if (format[0] == 'u')
			return (ft_printf_putlstr(ft_printf_itoa_base(\
							va_arg(ap, unsigned int), 10, 'a')));
		if (format[0] == 'U')
			return (ft_printf_putlstr(ft_printf_itoa_base(\
							va_arg(ap, long unsigned int), 10, 'a')));
	}
	return (0);
}

int			ft_printf_i(char const*format, va_list ap, int *skip, t_arg *fg)
{
	int		nb;

	(void)fg;
	if (format[0] == 'i')
	{
		*skip += 2;
		nb = va_arg(ap, int);
		ft_putnbr(nb);
		return ((int)ft_strlen(ft_itoa(nb)));
	}
	return (0);
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
	fg->precision = 0;
	fg->min = 0;
	fg->max = 0;
	fg->hfound = 0;
	fg->moins = 0;
	fg->plus = 0;
	fg->space = 0;
	fg->zero = 0;
}
