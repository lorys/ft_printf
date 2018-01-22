/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 06:51:44 by llopez            #+#    #+#             */
/*   Updated: 2018/01/22 16:28:52 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int		justaddr = 123456;
	int		ret;
	int		ret2;

	ret = ft_printf("petit test : %p", &justaddr);
	printf("\nreturn %d\n", ret);

	ret2 = printf("petit test : %p", &justaddr);
	printf("\nreturn %d\n", ret2);
	return (0);
}
