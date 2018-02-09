/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 06:51:44 by llopez            #+#    #+#             */
/*   Updated: 2018/02/09 19:03:17 by llopez           ###   ########.fr       */
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
	ret = ft_printf("%hhd %lld", (char)-1, (char)-2);
	printf("\nreturn %d\n", ret);

	printf("la vraie: \n");
	ret2 = printf("%hhd %lld", (char)-2, (char)-2);
	printf("\nreturn %d\n", ret2);
	return (0);
}
