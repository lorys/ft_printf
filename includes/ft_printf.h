/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 06:39:39 by llopez            #+#    #+#             */
/*   Updated: 2018/01/18 18:44:00 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"

int		ft_printf(const char*restrict format, ...);
int		ft_printf_putlstr(char *str);
char	*ft_printf_itoa_base(long nb, unsigned int base);
int		ft_printf_puthexa(unsigned long nb, unsigned int base);
int		ft_printf_putnbr_base(long nb, unsigned int base);

#endif
