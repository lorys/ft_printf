/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 06:51:44 by llopez            #+#    #+#             */
/*   Updated: 2018/04/04 11:40:13 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int		main(int argc, char **argv)
{
	int		ret;
	int		ret2;
/*	wchar_t	i;

	setlocale(LC_ALL, "");
	i = 0;
	while (i < 0xFFFFFF)
	{
		ret2 = ft_printf("%C", i);
		printf("\n");
		ret = printf("%C", i);
		printf("\n");
		printf("\n\nprintf : %d - ft_printf : %d - %ld\n\n", ret, ret2, i);
		if (ret2 != ret)
			return (0);
		i++;
	}
*/
	ret = printf(">------------<%+.52zi>------------<\n", 0);
	ret2 = ft_printf(">------------<%+.52zi>------------<\n", 0);
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
/*

	ret = printf("%00+10.4d\n", 0);
	ret2 = ft_printf("%00+10.4d\n", 0);
	printf("\n\nprintf : %d - ft_printf : %d\n\n", ret, ret2);

	ret = printf("%+12.5d\n", 140);
	ret2 = ft_printf("%+12.5d\n", 140);
	printf("\n\nprintf : %d - ft_printf : %d\n\n", ret, ret2);
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
*/	ret = printf("% 20.12ld et% 05D% 4.8hi !\n", 0x11ffaa147, 24, (short)-2345);
	ret2 = ft_printf("% 20.12ld et% 05D% 4.8hi !\n", 0x11ffaa147, 24, (short)-2345);
	printf("\nprintf : %d - ft_printf : %d (%% 20.12ld et%% 05D%% 4.8hi !, 0x11ffaa147, 24, (short)-2345\n", ret, ret2);
/*	ret = printf("%08i\n", -71);
	ret2 = ft_printf("%08i\n", -71);
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);

	ret = printf("% 5D|% 5d|\n", 24, 24);
	ret2 = ft_printf("% 5D|% 5d|\n", 24, 24);
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
	ret = printf("%.2o|\n", 24);
	ret2 = ft_printf("%.2o|\n", 24);
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
	ret = printf("%0d|\n", 579);
	ret2 = ft_printf("%0d|\n", 579);
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
	
	ret = printf("coco et %-#-#--24O titi%#012o\n", 12, -874);
	ret2 = ft_printf("coco et %-#-#--24O titi%#012o\n", 12, -874);
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);

	ret = printf("t %#7.5X%0006.2x et %lX!\n", 0xab, 0x876, 0xff11ff11ff1);	
	ret2 = ft_printf("t %#7.5X%0006.2x et %lX!", 0xab, 0x876, 0xff11ff11ff1);	
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);

	ret = printf("cc%#.4X et %#0012x %#04hX !!\n", 0xaef, 0xe, (unsigned short)0);
	ret2 = ft_printf("cc%#.4X et %#0012x %#04hX !!", 0xaef, 0xe, (unsigned short)0);
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
	ret = printf("%0#10.0x %0#x\n", 12345, 0);
	ret2 = ft_printf("%0#10.0x %0#x\n", 12345, 0);
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
	ret = printf("%#-08x\n", 42);
	ret2 = ft_printf("%#-08x\n", 42);
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
	ret = printf("|@moulitest: %5.x %5.0x|\n", 0, 0);
	ret2 = ft_printf("|@moulitest: %5.x %5.0x|\n", 0, 0);
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
	
	ret = printf("%5.2s is a string\n", "");
	ret2 = ft_printf("%5.2s is a string\n", "");
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);

	ret = printf("%.2s is a string\n", "");
	ret2 = ft_printf("%.2s is a string\n", "");
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
	
	ret = printf("%5.2s is a string\n", "this");
	ret2 = ft_printf("%5.2s is a string\n", "this");
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
	
	ret = printf("%.2s is a string", "this");
	ret2 = ft_printf("%.2s is a string\n", "this");
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
	
	ret = printf("%-5.2s is a string\n", "");
	ret2 = ft_printf("%-5.2s is a string\n", "");
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
	
	ret = printf("%-.2s is a string\n", "this");
	ret2 = ft_printf("%-.2s is a string\n", "this");
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
	
	ret = printf("%-05o\n", 2500);
	ret2 = ft_printf("%-05o\n", 2500);
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
	
	ret = printf("@moulitest: %.o %.0o\n", 0, 0);
	ret2 = ft_printf("@moulitest: %.o %.0o\n", 0, 0);
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
	
	ret = printf("toto %###.0o%#.O et %#.1o !\n", 0, 0, 0);
	ret2 = ft_printf("toto %###.0o%#.O et %#.1o !\n", 0, 0, 0);
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
	
	ret = printf("@moulitest: %5.o %5.0o|\n", 0, 0);
	ret2 = ft_printf("@moulitest: %5.o %5.0o|\n", 0, 0);
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
	
	ret = printf("%-05d\n", 42);
	ret2 = ft_printf("%-05d\n", 42);
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
	
	ret = printf("%zd\n", 4294967295);
	ret2 = ft_printf("%zd\n", 4294967295);
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
	
	ret = printf("%hU\n", 4294967296);
	ret2 = ft_printf("%hU\n", 4294967296);
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
	
	ret = printf("%C\n", 0x1234);
	ret2 = ft_printf("%C\n", 0x1234);
	printf("\nprintf : %d - ft_printf : %d\n", ret, ret2);
*/	return (0);
}
