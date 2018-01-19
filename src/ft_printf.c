/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 04:20:35 by llopez            #+#    #+#             */
/*   Updated: 2018/01/19 18:47:41 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf_putlstr(char *str)
{
	int	i;

	i = 0;
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

int				ft_addc(int *skip, int add)
{
	*skip += add;
	return (1);
}

static int		*ft_format(const char *str, va_list ap, int *lenght)
{
	int		i;
	int		bfore;
	int		*skip;
	//t_arg	handle;

	skip = (int *)malloc(sizeof(int) * 2);
	i = 0;
	skip[1] = 0;
	bfore = *lenght;
	if (str[i] == '%')
	{
		while (ft_isdigit(str[i + 1]) && str[i + 1])
			i++;
		*lenght += ft_printf_s(&str[i], va_arg(ap, char *), &skip[1]);
		*lenght += ft_printf_p(&str[i], va_arg(ap, uintmax_t), &skip[1]);
	}
	skip[0] = (*lenght - bfore);
	return (skip);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int			i;
	int			lenght;
	int			*retrn;

	i = 0;
	lenght = 0;
	va_start(ap, format);
	while (format[i])
	{
		retrn = ft_format(&format[i], ap, &lenght);
		if (retrn[0] == 0 && ++lenght)
		{
			ft_putchar(format[i]);
			i += 1;
		}
		else
			i += retrn[1];
		free(retrn);
	}
	va_end(ap);
	return (lenght);
}
