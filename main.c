/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 06:51:44 by llopez            #+#    #+#             */
/*   Updated: 2017/12/20 16:09:10 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char	c;
	int		ret;
	int		ret2;
	char	str[] = "%s";

	c = 'y';
	ret = ft_printf(str, "mdr");
	printf("\n=== %d chars written. ===\n", ret);
	ret2 = printf(str, "mdr");
	printf("\n=== %d chars written. ===\n", ret2);
	return (0);
}
