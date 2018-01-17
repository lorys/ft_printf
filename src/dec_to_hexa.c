/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 21:40:01 by llopez            #+#    #+#             */
/*   Updated: 2018/01/17 19:00:13 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_printf_itoa_base(unsigned int nb, unsigned int base)
{
	int				i;
	static char		str[32] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";

	i = 30;
	while (nb > 0 && i > 0)
	{
		str[i] = "0123456789abcdef"[nb % base];
		nb /= base;
		--i;
	}
	return (str + i + 1);
}

int				ft_printf_puthexa(unsigned int nb, unsigned int base)
{
	int		i;

	i = ft_printf_putlstr("0x7fff");
	i += ft_printf_putlstr(ft_printf_itoa_base(nb, base));
	return (i);
}

int				ft_printf_putnbr_base(long nb, unsigned int base)
{
	int		i;

	if (nb < 0)
	{
		nb *= -1;
		i = ft_printf_putlstr("-");
	}
	nb = (nb < 0)? nb * -1 : nb;
	i = ft_printf_putlstr(ft_printf_itoa_base(nb, base));
	return (i);
}
