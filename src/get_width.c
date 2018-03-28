/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:10:17 by llopez            #+#    #+#             */
/*   Updated: 2018/03/19 17:10:33 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_get_width(const char *str, t_arg *fg)
{
	int		i;
	int		b;

	b = 0;
	while (ft_strchr("#0-+ hljz", str[b]))
		b++;
	i = b;
	while (ft_isdigit(str[i]))
	{
		i++;
		fg->width_used = 1;
	}
	if (i == 0)
		return (0);
	return (ft_atoi(ft_strndup(&str[b], i)));
}
