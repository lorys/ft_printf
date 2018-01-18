/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 06:51:44 by llopez            #+#    #+#             */
/*   Updated: 2018/01/18 16:22:31 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int		ret;
	int		ret2;

	ret = ft_printf("%lu", 9223372036854775807);
	printf("\n=== %d chars written. ===\n", ret);
	ret2 = printf("%lu", 9223372036854775807);
	printf("\n=== %d chars written. ===\n", ret2);

	ft_printf("\n===============================\n\n");

	ret = ft_printf("%p", &ret);
	printf("\n=== %d chars written. ===\n", ret);
	ret2 = printf("%p", &ret);
	printf("\n=== %d chars written. ===\n", ret2);
	return (0);
}
