/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 06:51:44 by llopez            #+#    #+#             */
/*   Updated: 2018/01/23 14:26:11 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int		ret;
	int		ret2;

	printf("ma fonction: \n");
	ret = ft_printf("petit test : %p %d %s %#o %o", &ret, 225, "saleeeeeeeeeeet", 100, 100);
	printf("\nreturn %d\n", ret);
printf("\n\nla vraie: \n");
	ret2 = printf("petit test : %p %d %s %#o %o", &ret, 225, "saleeeeeeeeeeet", 100, 100);
	printf("\nreturn %d\n", ret2);
	return (0);
}
