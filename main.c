/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 06:51:44 by llopez            #+#    #+#             */
/*   Updated: 2018/02/23 10:46:56 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int		main(int argc, char **argv)
{
	int ret;
	int ret2;
	ft_printf("|%1.4s et %-6.8s et %4.2s|\n", "tuuu", "12345", "hu");
	   printf("|%1.4s et %-6.8s et %4.2s|\n", "tuuu", "12345", "hu");
	ft_printf("\n|%05.1u %3.4hu %-4.7U|\n", 45, (unsigned short)-1789, 147);
	   printf("\n|%05.1u %3.4hu %-4.7U|\n", 45, (unsigned short)-1789, 147);
	ft_printf("\nft_printf: |t%4.2o%#2oet %#-8.3o titi %o|\n%#o\ncoco et %-#-#--24O titi%#12o", 0, 0, 0, 0, -896, 12, -874);
	   printf("\n   printf: |t%4.2o%#2oet %#-8.3o titi %o|\n%#o\ncoco et %-#-#--24O titi%#12o", 0, 0, 0, 0, -896, 12, -874);
	printf("\n\n\n|%o|%#o|%5o|%5.3o|%#5o|%#-8.3o|\n", 0,0,0,0,0,0);
	ft_printf("\n\n\n|%o|%#o|%5o|%5.3o|%#5o|%#-8.3o|\n", 0,0,0,0,0,0);

	   printf("\n|%X|% d|%.0x|%.0lx|%#X|\n", 0, 42, 0, &ret, 0);
	ft_printf("\n|%X|% d|%.0x|%.0lx|%#X|\n", 0, 42, 0, &ret, 0);
	ret = printf("%llX", (unsigned long long)0xaaffee11996677);
	printf("\nprintf = return (%d)\n", ret);
	ret2 = ft_printf("%llX", (unsigned long long)0xaaffee11996677);
	printf("\nftprintf = return (%d)\n", ret2);
	printf("% ++d", -42);
	ft_printf("% ++d", -42);
	return (0);
}
