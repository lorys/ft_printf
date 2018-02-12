/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 06:51:44 by llopez            #+#    #+#             */
/*   Updated: 2018/02/12 21:09:20 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int		main(int argc, char **argv)
{
	int		ret;
	int		ret2;
	printf("ma fonction: \n");
	ret = ft_printf("% 20.12ld et % 05D% 4.8hi !\n%+.i% 9.5d", 0x11ffaa147, 24,
			             (short)-2345, 0, 12345);
	printf("\nreturn %d\n", ret);

	printf("la vraie: \n");
	ret2 = printf("% 20.12ld et % 05D% 4.8hi !\n%+.i% 9.5d", 0x11ffaa147, 24,
			             (short)-2345, 0, 12345);
	printf("\nreturn %d\n", ret2);
	return (0);
}
