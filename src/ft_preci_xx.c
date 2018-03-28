/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preci_xx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:49:54 by llopez            #+#    #+#             */
/*   Updated: 2018/03/28 18:22:45 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_preci_xx(int preci, char *str)
{
	int	lenght;

	lenght = 0;
	preci = preci - ((int)ft_strlen(str));
	while (preci > 0)
	{
		lenght += ft_printf_putlstr("0");
		preci--;
	}
	return (lenght);
}
