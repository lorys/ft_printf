/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 04:20:35 by llopez            #+#    #+#             */
/*   Updated: 2018/04/05 00:03:30 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf_putlstr(char *str)
{
	int		len;

	len = (int)ft_strlen(str);
	write(1, str, len);
	return (len);
}

int				ft_putsubstr(char *str, int len)
{
	if (len <= (int)ft_strlen(str))
		write(1, str, len);
	else
		write(1, str, (int)ft_strlen(str));
	return ((len <= (int)ft_strlen(str)) ? len : (int)ft_strlen(str));
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
	int		tmp;

	skip = (int *)malloc(sizeof(int) * 3);
	i = 0;
	skip[1] = 0;
	bfore = *lenght;
	tmp = 0;
	if (str[i] == '%' && str[i + 1] != '\0' && ++i)
	{
		ft_initialize_struct(&fg);
		i += ft_printf_flags(&str[i], &skip[1], &fg);
		tmp = ft_printf_bigs(&str[i], ap, &skip[1], &fg);
		*lenght += tmp;
		skip[2] = (tmp == -1)?-1:skip[2];
		tmp = ft_printf_bigc(&str[i], ap, &skip[1], &fg);
		*lenght += tmp;
		skip[2] = (tmp == -1)?-1:skip[2];
		*lenght += ft_printf_percent(&str[i], &skip[1], &fg);
		*lenght += ft_printf_s(&str[i], ap, &skip[1], &fg);
		*lenght += ft_printf_p(&str[i], ap, &skip[1], &fg);
		*lenght += ft_printf_d(&str[i], ap, &skip[1], &fg);
		*lenght += ft_printf_c(&str[i], ap, &skip[1], &fg);
		*lenght += ft_printf_oo(&str[i], ap, &skip[1], &fg);
		*lenght += ft_printf_uu(&str[i], ap, &skip[1], &fg);
		*lenght += ft_printf_xx(&str[i], ap, &skip[1], &fg);
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
	int			error;

	i = 0;
	lenght = 0;
	error = 0;
	if (format == NULL)
		return (0);
	va_start(ap, format);
	while (format[i])
	{
		retrn = ft_format(&format[i], ap, &lenght);
		if (retrn[1] == 0 && ++lenght)
		{
			if (format[i] == '%' && format[i + 1] == '\0')
				return (0);
			ft_putchar(format[i]);
			i++;
		}
		i += retrn[1];
		error = (retrn[2] == -1)?-1:0;
		free(retrn);
	}
	va_end(ap);
	return ((error == -1)?-1:lenght);
}
