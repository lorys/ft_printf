/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 20:20:53 by llopez            #+#    #+#             */
/*   Updated: 2018/04/04 22:39:29 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putwstr(wchar_t *str)
{
	int		len;

	len = 0;
	while (*str)
	{
		ft_putwchar(*str);
		len += ft_wcharlen(*str);
		str++;
	}
	return (len);
}
