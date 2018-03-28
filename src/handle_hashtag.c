/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hashtag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 12:20:16 by llopez            #+#    #+#             */
/*   Updated: 2018/03/28 18:22:32 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_width(t_arg *fg, int r, char *str, int len)
{
	int lenght;
	int	width;
	int	strlen;

	strlen = (str == NULL) ? len : (int)ft_strlen(str);
	width = fg->width;
	lenght = 0;
	if (fg->width_used && fg->moins == r)
	{
		if (fg->precision > -1 && fg->precision > strlen)
			width = fg->width - fg->precision;
		else
			width = width - strlen;
		while (width > 0)
		{
			lenght += ft_printf_putlstr((fg->zero) ? "0" : " ");
			--width;
		}
	}
	return (lenght);
}

intmax_t	ft_printf_signed(va_list ap, t_arg *fg)
{
	if (fg->z)
		return (va_arg(ap, ssize_t));
	if (fg->hh)
		return ((char)va_arg(ap, int));
	if (fg->h)
		return ((short int)va_arg(ap, int));
	if (fg->j)
		return (va_arg(ap, intmax_t));
	if (fg->l)
		return (va_arg(ap, long));
	if (fg->ll)
		return (va_arg(ap, long long));
	return (va_arg(ap, int));
}

uintmax_t	ft_printf_unsigned(va_list ap, t_arg *fg)
{
	if (fg->hh)
		return ((unsigned char)va_arg(ap, unsigned int));
	if (fg->h)
		return ((unsigned short int)va_arg(ap, unsigned int));
	if (fg->j)
		return (va_arg(ap, uintmax_t));
	if (fg->z)
		return (va_arg(ap, size_t));
	if (fg->l || fg->flag == 'O')
		return (va_arg(ap, unsigned long));
	if (fg->ll)
		return (va_arg(ap, unsigned long long));
	return (va_arg(ap, unsigned int));
}

int			ft_printf_putspace(t_arg *fg, char *str)
{
	(void)str;
	if (!fg->space)
		return (0);
	if (fg->space && fg->width_used)
		return (0);
	if (fg->space && fg->width_used && fg->width <= fg->precision)
		return (0);
	if (fg->space && fg->width_used && fg->width <= (int)ft_strlen(str))
		return (0);
	if (fg->space && fg->plus)
		return (0);
	ft_putchar(' ');
	return (1);
}

int			ft_printf_putspace_d(t_arg *fg, char *str)
{
	(void)str;
	if (!fg->space)
		return (0);
	if (fg->space && fg->width_used && !fg->zero)
		return (0);
	if (fg->space && fg->width_used && fg->width <= fg->precision)
		return (0);
	if (fg->space && fg->width_used && fg->width <= (int)ft_strlen(str))
		return (0);
	if (fg->space && fg->plus)
		return (0);
	ft_putchar(' ');
	return (1);
}
