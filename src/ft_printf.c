/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 04:20:35 by llopez            #+#    #+#             */
/*   Updated: 2018/02/26 16:08:52 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf_putlstr(char *str)
{
	ft_putstr(str);
	return ((int)ft_strlen(str));
}

int				ft_printf_getnb(int nb, int n)
{
	while (n-- > 0)
		if (nb >= 10)
			nb /= 10;
	nb %= 10;
	return (nb);
}

static int		*ft_format(const char *str, va_list ap, int *lenght)
{
	int		i;
	int		bfore;
	int		*skip;
	t_arg	fg;

	skip = (int *)malloc(sizeof(int) * 2);
	i = 0;
	skip[1] = 0;
	bfore = *lenght;
	if (str[i] == '%' && ++i)
	{
		ft_initialize_struct(&fg);
		i += ft_printf_flags(&str[i], &skip[1], &fg);
		*lenght += ft_printf_percent(&str[i], &skip[1], &fg);
		*lenght += ft_printf_s(&str[i], ap, &skip[1], &fg);
		*lenght += ft_printf_p(&str[i], ap, &skip[1], &fg);
		*lenght += ft_printf_d(&str[i], ap, &skip[1], &fg);
		*lenght += ft_printf_c(&str[i], ap, &skip[1], &fg);
		*lenght += ft_printf_oo(&str[i], ap, &skip[1], &fg);
		*lenght += ft_printf_uu(&str[i], ap, &skip[1], &fg);
		*lenght += ft_printf_xX(&str[i], ap, &skip[1], &fg);
	}
	skip[0] = (*lenght - bfore);
	return (skip);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			lenght;
	int			*retrn;

	i = 0;
	lenght = 0;
	if (format == NULL)
		return (0);
	va_start(ap, format);
	while (format[i])
	{
		retrn = ft_format(&format[i], ap, &lenght);
		if (retrn[1] == 0 && ++lenght)
		{
			ft_putchar(format[i]);
			i++;
		}
		i += retrn[1];
		free(retrn);
	}
	va_end(ap);
	return (lenght);
}
