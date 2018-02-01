/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 06:51:44 by llopez            #+#    #+#             */
/*   Updated: 2018/02/01 17:12:06 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int		ret;
	int		ret2;
	printf("ma fonction: \n");
	ret = ft_printf("%  0000001000d\n% 10d\n% 010d\n%#o\n%hhU", 25, 45, 50, 200, 200, 500);
	printf("\nreturn %d\n", ret);

	printf("la vraie: \n");
	ret2 = printf("%U\n", 500);
	printf("\nreturn %d\n", ret2);
	return (0);
}
