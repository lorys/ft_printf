/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 06:51:44 by llopez            #+#    #+#             */
/*   Updated: 2018/01/31 20:54:21 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int		ret;
	int		ret2;
	unsigned int nb = 555;
	printf("ma fonction: \n");
	ret = ft_printf("%00000010d\n% 10d\n% 010d\n%#o\n", 25, 45, 50, 200, 200);
	printf("\nreturn %d\n", ret);

	printf("la vraie: \n");
	ret2 = printf("%O  \n", nb);
	printf("\nreturn %d\n", ret2);
	return (0);
}
