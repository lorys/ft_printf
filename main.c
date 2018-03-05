/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 06:51:44 by llopez            #+#    #+#             */
/*   Updated: 2018/03/05 20:09:33 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int		main(int argc, char **argv)
{
	int ret;
	int ret2;
	
	ret = printf("|%d|% d|%8d|%d|%5.3d|\n", 5, 5, 5, 5, 5);
	ret2 = ft_printf("|%d|% d|%8d|%#d|%5.3d|\n", 5, 5, 5, 5, 5);
	printf("\n\nprintf : %d - ft_printf : %d\n\n", ret, ret2);
	ret = printf("|%d|% d|%8d|%d|%5.3d|\n", 0, 0, 0, 0, 0);
	ret2 = ft_printf("|%d|% d|%8d|%#d|%5.3d|\n", 0, 0, 0, 0, 0);
	printf("\n\nprintf : %d - ft_printf : %d\n\n", ret, ret2);
	ret = printf("|%x|%x|%8x|%#x|%5.3x|\n", 5, 5, 5, 5, 5);
	ret2 = ft_printf("|%x|%x|%8x|%#x|%5.3x|\n", 5, 5, 5, 5, 5);
	printf("\n\nprintf : %d - ft_printf : %d\n\n", ret, ret2);
	ret = printf("|%x|%x|%8x|%#x|%5.3x|\n", 0, 0, 0, 0, 0);
	ret2 = ft_printf("|%x|%x|%8x|%#x|%5.3x|\n", 0, 0, 0, 0, 0);
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
	ret = printf("|%15x|%#5x|%-x|%x|%5.3x|\n", 5, 5, 5, 5, 5);
	ret2 = ft_printf("|%15x|%#5x|%-x|%x|%5.3x|\n", 5, 5, 5, 5, 5);
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
	ret = printf("|%#-#-#-#15x|%#x|%15.15x|%x|%5.3x|\n", 5, 5, 5, 5, 5);
	ret2 = ft_printf("|%#-#-#-#15x|%#x|%15.15x|%x|%5.3x|\n", 5, 5, 5, 5, 5);
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
	ret = printf("|%015.5x|%1x|%0x|%x|%5.7x|\n", 5, 5, 5, 5, 5);
	ret2 = ft_printf("|%015.5x|%1x|%0x|%x|%5.7x|\n", 5, 5, 5, 5, 5);
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
	ret = printf("% 20.12ld et%5D% 4.8hi !\n", 0x11ffaa147, 24, (short)-2345);
	ret2 = ft_printf("% 20.12ld et%5D% 4.8hi !\n", 0x11ffaa147, 24, (short)-2345);
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
	ret = printf("%08i\n", -71);
	ret2 = ft_printf("%08i\n", -71);
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);

	ret = printf("% 5D|% 5d|\n", 24, 24);
	ret2 = ft_printf("% 5D|% 5d|\n", 24, 24);
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
	ret = printf("%.2o|\n", 24);
	ret2 = ft_printf("%.2o|\n", 24);
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
	
	
	return (0);
}
