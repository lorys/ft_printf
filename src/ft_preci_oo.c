/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preci_oo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:01:23 by llopez            #+#    #+#             */
/*   Updated: 2018/03/28 18:21:12 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_preci_oo(t_arg *fg, char *str, int nb)
{
	int		lenght;
	int		preci;

	preci = fg->precision;
	lenght = 0;
	preci = (preci > -1) ? preci - (int)ft_strlen(str) : preci;
	preci = (fg->hfound && nb != 0) ? preci - 1 : preci;
	while (preci > 0)
	{
		lenght += ft_printf_putlstr("0");
		preci--;
	}
	return (lenght);
}
