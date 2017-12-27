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
	int	tmp;
	int	tmp_n;

	tmp = nb;
	tmp_n = n;
	while (tmp_n-- > 0)
	{
		if (tmp > 9)
		{
			tmp /= 10;
			tmp *= ;
		}
	}
	nb = nb - tmp;
	printf("\nnb = %d\n", nb);
	return (nb);
}

char			*ft_printf_dec_to_hex(int dec)
{
	char	*str;
	int	nb_len;
	int	tmp_nb;
	int	i;

	i = 0;
	nb_len = 1;
	tmp_nb = dec;
	while ((tmp_nb = (tmp_nb / 10)) > 0)
		nb_len++;
	printf("\n%d\n", nb_len);
	str = (char *)malloc(sizeof(char) * nb_len + 1);
	str[nb_len] = '\0';
	while (nb_len--)
	{
		str[i] = ft_printf_getnb(dec, nb_len);
		i++;
	}
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
