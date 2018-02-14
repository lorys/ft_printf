/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 06:51:44 by llopez            #+#    #+#             */
/*   Updated: 2018/02/14 19:36:37 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int		main(int argc, char **argv)
{
	ft_printf("|%1.4s et %-6.8s et %4.2s|\n", "tuuu", "12345", "hu");
	   printf("|%1.4s et %-6.8s et %4.2s|\n", "tuuu", "12345", "hu");
	ft_printf("\n|%05.1u %3.4hu %-4.7U|", 45, (unsigned short)-1789, 147);
	   printf("\n|%05.1u %3.4hu %-4.7U|", 45, (unsigned short)-1789, 147);
	ft_printf("\n|t%04.2o%#2oet %#-8.3o titi|\n", 0, 0, 0);
	   printf("\n|t%04.2o%#2oet %#-8.3o titi|", 0, 0, 0);
	return (0);
}
