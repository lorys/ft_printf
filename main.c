/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 06:51:44 by llopez            #+#    #+#             */
/*   Updated: 2018/01/27 13:16:53 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int		ret;
	int		ret2;

	printf("ma fonction: \n");
	ret = ft_printf("petit test : %p %d %s %#o %o \n%u\n%x", &ret, 225, "saleeeeeeeeeeet", 100, 100, -525, 525);
	printf("\nreturn %d\n", ret);
printf("\n\npetit test : %%p %%d %%s %%#o %%o \n%%u\n%%x\n\n");
printf("\n\nla vraie: \n");
	ret2 = printf("petit test : %p %d %s %#o %o \n%u\n%x", &ret, 225, "saleeeeeeeeeeet", 100, 100, -525, 525);
	printf("\nreturn %d\n", ret2);
	return (0);
}
