/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 06:51:44 by llopez            #+#    #+#             */
/*   Updated: 2018/02/06 11:12:15 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int		main(void)
{
	int		ret;
	int		ret2;
	printf("ma fonction: \n");
	ret = ft_printf("%s", "");
	printf("\nreturn %d\n", ret);

	printf("la vraie: \n");
	ret2 = printf("%s", "");
	printf("\nreturn %d\n", ret2);
	return (0);
}
