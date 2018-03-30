/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:11:51 by llopez            #+#    #+#             */
/*   Updated: 2018/03/30 12:54:17 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		fg->precision = (fg->moins) ? 0 : fg->precision;
		width = width - (int)ft_strlen(str);
		if (!fg->moins && fg->precision > (int)ft_strlen(str) &&\
				width - (fg->precision - (int)ft_strlen(str)) >= 0)
			width = width - (fg->precision - (int)ft_strlen(str));
		while (width > 0)
		{
			len_str += ft_printf_putlstr((fg->zero) ? "0" : " ");
			--width;
		}
	}
	return (len_str);
}
