/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 06:51:44 by llopez            #+#    #+#             */
/*   Updated: 2018/04/05 02:26:27 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int		main(int argc, char **argv)
{
	int		ret;
	int		ret2;
	int		free;
	int		c;
	setlocale(LC_ALL, "");
/*	wchar_t	s[4];

	s[0] = 0x53;
		s[1] = 0xd800;
			s[2] = 0x81000;
				s[3] = '\0';

	ret2 = ft_printf("%S\n", s);
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;

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

	ret = printf("%C\n", 254);
	ret2 = ft_printf("%lc\n", 254);
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("!%20.22zu!\n", 0);
	ret2 = ft_printf("!%20.22zu!\n", 0);
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("\\!/%38.8zu\\!/\n", 0);
	ret2 = ft_printf("\\!/%38.8zu\\!/\n", 0);
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("\\!/%16.23zu\\!/", 0);
	ret2 = ft_printf("\\!/%16.23zu\\!/", 0);
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("\\!/%4.22zu\\!/\n", 0);
	ret2 = ft_printf("\\!/%4.22zu\\!/\n", 0);
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf(">------------<%50.51zu>------------<\n", 0);
	ret2 = ft_printf(">------------<%50.51zu>------------<\n", 0);
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("%-05%\n");
	ret2 = ft_printf("%-05%\n");
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("%-34.2ju|\n", 0);
	ret2 = ft_printf("%-34.2ju|\n", 0);
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("!%-13.2zu!");
	ret2 = ft_printf("!%-13.2zu!");
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("^.^/%-13.2zu^.^/\n", -242403321);
	ret2 = ft_printf("^.^/%-13.2zu^.^/\n", -242403321);
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("%");
	ret2 = ft_printf("%");
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("^.^/%-13.2zu^.^/", -242403321);
	ret2 = ft_printf("^.^/%-13.2zu^.^/", -242403321);
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("%-54.45zu", 0);
	printf("\n");
	ret2 = ft_printf("%-54.45zu", 0);
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("%-2.2zU\n", 0);
	ret2 = ft_printf("%-2.2zU\n", 0);
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("^.^/%-16.2zU^.^/\n", 0);
	ret2 = ft_printf("^.^/%-16.2zU^.^/\n", 0);
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("%017%\n");
	ret2 = ft_printf("%017%\n");
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("!%-23.2zU!\n", 0);
	ret2 = ft_printf("!%-23.2zU!\n", 0);
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("%-26.2zU|\n", 0);
	ret2 = ft_printf("%-26.2zU|\n", 0);
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("%S|\n", L"þþþ");
	ret2 = ft_printf("%S|\n", L"þþþ");
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("%5lc\n", 350);
	ret2 = ft_printf("%5lc\n", 350);
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("\\!/%#42.2hhx\\!/\n", -692517628);
	ret2 = ft_printf("\\!/%#42.2hhx\\!/\n", -692517628);
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("^.^/%#17.2zx^.^/\n", 397046228);
	ret2 = ft_printf("^.^/%#17.2zx^.^/\n", 397046228);
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
*/	ret = printf("42%42.62ls42\n", L"");
	ret2 = ft_printf("42%42.62ls42\n", L"");
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("%.p, %.0p\n", 0, 0);
	ret2 = ft_printf("%.p, %.0p\n", 0, 0);
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("%s %C %d %p %x %% %S\n", "bonjour ", L'該', 42, &free, 42, L"لحم خنزي");
	ret2 = ft_printf("%s %C %d %p %x %% %S", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C\n","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	ret2 = ft_printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C\n","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("%hhS, %hhS\n", 0, L"米米");
	ret2 = ft_printf("%hhS, %hhS\n", 0, L"米米");
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("!%22.62ls!\n", L"(null)");
	ret2 = ft_printf("!%22.62ls!", L"(null)");
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("^.^/%31.10ls^.^/\n", L"こんにちは、私はprintf単体テストです");
	ret2 = ft_printf("^.^/%31.10ls^.^/\n", L"こんにちは、私はprintf単体テストです");
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("%p", NULL);
	ret2 = ft_printf("%p\n", NULL);
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("42%35.24ls42\n", L"(╯°Д°）╯︵ /(.□ . \)");
	ret2 = ft_printf("42%35.24ls42\n", L"(╯°Д°）╯︵ /(.□ . \)");
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	//ret = printf("Coucou %.0s\n%s%---12s", "hi", "coco", NULL);
	//ret2 = ft_printf("Coucou %.0s\n%s%---12s", "hi", "coco", NULL);
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("%---12s\n", NULL);
	ret2 = ft_printf("%---12s\n", NULL);
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("%.15s\n", "coco");
	ret2 = ft_printf("%.15s\n", "coco");
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("%.2s\n", NULL);
	ret2 = ft_printf("%.2s\n", NULL);
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("42%6.48s42\n", "");
	ret2 = ft_printf("42%6.48s42\n", "");
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
	ret = printf("% Zoooo\n");
	ret2 = ft_printf("% Zoooo\n");
	printf("\n\nprintf : %d | ft_printf : %d\n\n", ret, ret2);
	ret = 0;
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
