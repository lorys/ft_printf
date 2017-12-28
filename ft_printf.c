/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 04:20:35 by llopez            #+#    #+#             */
/*   Updated: 2017/12/20 16:09:09 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_putlstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (i - 1);
}

int			ft_printf_getnb(int nb, int n)
{
	while (n-- > 0)
		if (nb >= 10)
			nb /= 10;
	nb %= 10;
	return (nb);
}

char			*ft_printf_dec_to_hex(int dec)
{
	char	*str;
	int	nb_len;
	int	tmp_nb;
	char	hexa[] = "0123456789ABCDEF";
	int	calc;

	nb_len = 1;
	tmp_nb = dec;
	while ((tmp_nb = (tmp_nb / 10)) > 0)
		nb_len++;
	str = (char *)malloc(sizeof(char) * nb_len + 1);
	str[nb_len + 1] = '\0';
	while (nb_len--)
	{
		if (nb_len > 1)
		{
			calc = ft_printf_getnb(dec, nb_len) * 10 + \
				ft_printf_getnb(dec, nb_len - 1);
			if (calc > 15)
				str[nb_len] = hexa[calc];
			printf("\n%d = %c\n", calc, hexa[calc]);
		}
		else
			str[nb_len] = hexa[ft_printf_getnb(dec, nb_len)];
	}
	printf("hexa : %s\n", str);
	return (str);
}

static int		ft_format(const char *str, va_list ap, int *lenght)
{
	int		i;
	int		bfore;

	i = 0;
	bfore = *lenght;
	if (str[i] == '%')
	{
		if (str[i + 1] == 's')
			*lenght += ft_printf_putlstr(va_arg(ap, char *));
		if (str[i + 1] == 'd' && ++*lenght)
			*lenght += ft_printf_putlstr(ft_itoa(va_arg(ap, int)));
		if (str[i + 1] == 'c' && ++*lenght)
			ft_putchar(va_arg(ap, int));
		if (str[i + 1] == 'p' && ++*lenght)
			ft_printf_dec_to_hex(7654); /* lenght += ft_printf_putlstr(va_arg(ap, char *)); */
		if (str[i + 1] == '%' && ++*lenght)
			ft_putchar(str[i + 1]);
	}
	return (*lenght - bfore);
}

int		ft_printf(const char * restrict format, ...)
{
	va_list		ap;
	int		i;
	int		lenght;

	i = 0;
	lenght = 0;
	va_start(ap, format);
	while (format[i])
		if (ft_format(&format[i], ap, &lenght) == 0 && ++lenght)
			ft_putchar(format[i++]);
		else
			i = i + 2;
	va_end(ap);
	return (lenght);
}
