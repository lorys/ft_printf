/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 06:51:44 by llopez            #+#    #+#             */
/*   Updated: 2018/02/11 06:39:58 by llopez           ###   ########.fr       */
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
	ret = ft_printf("toto%.0d et %+.i et  %   .0D !!!", 0, 0, 0);
	printf("\nreturn %d\n", ret);

	printf("la vraie: \n");
	ret2 = printf("toto%.0d et %+.i et  %   .0D !!!", 0, 0, 0);
	printf("\nreturn %d\n", ret2);
	return (0);
}
