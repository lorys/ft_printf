/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:52:06 by llopez            #+#    #+#             */
/*   Updated: 2018/01/22 16:28:44 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_s(char const*restrict format, va_list ap, int *skip)
{
	char	*str;

	if (format[1] == (char)'s')
	{
		str = va_arg(ap, char *);
		*skip += 2;
		ft_putstr(str);
		return (ft_strlen(str));
	}
	return (0);
}
