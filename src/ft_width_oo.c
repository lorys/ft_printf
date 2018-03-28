/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_oo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:11:07 by llopez            #+#    #+#             */
/*   Updated: 2018/03/28 18:23:52 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_width_oo(t_arg *fg, int nb)
{
	fg->width = (fg->width > 0 && fg->space && fg->zero && nb != 0) ? \
				fg->width - 1 : fg->width;
	fg->width = (fg->hfound && nb != 0) ? fg->width - 1 : fg->width;
}
