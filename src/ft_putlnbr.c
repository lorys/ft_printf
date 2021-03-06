/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:02:28 by llopez            #+#    #+#             */
/*   Updated: 2018/03/28 18:23:11 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putlnbr(unsigned int n)
{
	if (n == 2147483648)
		return (ft_printf_putlstr("2147483648"));
	if (n >= 10)
		ft_putlnbr(n / 10);
	ft_putchar((n % 10) + '0');
	return (0);
}
