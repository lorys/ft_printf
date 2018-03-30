/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:11:22 by llopez            #+#    #+#             */
/*   Updated: 2018/03/30 12:50:58 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_percent(char const *format, int *skip, t_arg *fg)
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
