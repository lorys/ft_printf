/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 17:45:11 by llopez            #+#    #+#             */
/*   Updated: 2018/04/25 19:16:20 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main()
{
	int ret;
	int ret2;

	ret = ft_printf("{%05p}\n", 0);
	ret2 = printf("{%05p}\n", 0);
	printf("ft %d \n printf %d\n", ret, ret2);

	ret = ft_printf("{% 5p}\n", 0);
	ret2 = printf("{% 5p}\n", 0);
	printf("ft %d \n printf %d\n", ret, ret2);
	
	ret = ft_printf("{%-5p}\n", 0);
	ret2 = printf("{%-5p}\n", 0);
	printf("ft %d \n printf %d\n", ret, ret2);
	
	ret = ft_printf("{%-05p}\n", 0);
	ret2 = printf("{%-05p}\n", 0);
	printf("ft %d \nprintf %d\n", ret, ret2);
	
	ret = ft_printf("{%0p}\n", 0);
	ret2 = printf("{%0p}\n", 0);
	printf("ft %d \nprintf %d\n", ret, ret2);

	ret = ft_printf("{%p}\n", 0);
	ret2 = printf("{%p}\n", 0);
	printf("ft %d \nprintf %d\n", ret, ret2);

	ret = ft_printf("{%p}\n", NULL);
	ret2 = printf("{%p}\n", NULL);
	printf("ft %d \nprintf %d\n", ret, ret2);

	ret = ft_printf("%.5p\n", 0);
	ret2 = printf("%.5p\n", 0);
	printf("ft %d \nprintf %d\n", ret, ret2);

	ret = ft_printf("%2.9p\n", 1234);
	ret2 = printf("%2.9p\n", 1234);
	printf("ft %d \nprintf %d\n", ret, ret2);
	return (0);
}
