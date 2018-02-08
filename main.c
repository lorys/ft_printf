/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 06:51:44 by llopez            #+#    #+#             */
/*   Updated: 2018/02/08 19:12:20 by llopez           ###   ########.fr       */
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
	ret = ft_printf(argv[1], "abcdefghijkl");
	printf("\nreturn %d\n", ret);

	printf("la vraie: \n");
	ret2 = printf(argv[1], "abcdefghijkl");
	printf("\nreturn %d\n", ret2);
	return (0);
}
