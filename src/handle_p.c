/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:07:44 by llopez            #+#    #+#             */
/*   Updated: 2018/04/04 23:31:52 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf_p(const char *format, va_list ap,\
		int *skip, t_arg *fg)
{
	int		i;
	void	*nb;
	char	*conv;

	i = 0;
	if (format[0] == 'p')
	{
		nb = va_arg(ap, void *);
		conv = ft_printf_itoa_base((uintmax_t)nb, 16, 'a');
		conv = ft_strjoin("0x", conv);
		*skip += 2;
		i += ft_printf_width_str(fg, 0, (nb == 0 && nb != NULL) ? "0x" : conv);
		i += (nb == 0 && nb != NULL) ? ft_printf_putlstr("0x") : ft_printf_putlstr(conv);
		i += ft_printf_width_str(fg, 1, (nb == 0 && nb != NULL) ? "0x" : conv);
		free(conv);
	}
	return (i);
}