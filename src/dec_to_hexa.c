/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 21:40:01 by llopez            #+#    #+#             */
/*   Updated: 2018/01/19 18:47:40 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_printf_itoa_base(long nb, uintmax_t base, int type)
{
	int				i;
	static char		str[32];

	i = 30;
	while (nb > 0 && i > 0)
	{
		if (type == 'A')
			str[i] = "0123456789ABCDEF"[nb % base];
		else
			str[i] = "0123456789abcdef"[nb % base];
		nb /= base;
		--i;
	}
	printf("\nhexa : %s\n", str);
	return (str + i + 1);
}

int					ft_printf_p(const char* format, uintmax_t nb, int *skip)
{
	int		i;

	if (format[1] == 'p')
	{
		printf("decimal : %d\n", nb);
		*skip += 2;
		i = ft_printf_putlstr("0x7fff");
		i += ft_printf_putlstr(ft_printf_itoa_base(nb, 16, 'a'));
		return (0);
	}
	return (0);
}

int					ft_printf_putnbr_base(long nb, unsigned int base)
{
	int		i;

	if (nb < 0)
	{
		nb *= -1;
		i = ft_printf_putlstr("-");
	}
	else
		i = 0;
	i += ft_printf_putlstr(ft_printf_itoa_base(nb, base, 'a'));
	return (i);
}
