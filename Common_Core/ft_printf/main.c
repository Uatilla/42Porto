/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:02:49 by uviana-a          #+#    #+#             */
/*   Updated: 2023/05/28 15:40:06 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


int	main()
{
	char	c_test = 'U';
	char	*s_test = "Uatilla";
	char	*p_test = &*s_test;
	int	xX_test = 123456789;

	printf("%d\n", printf("Or_printf: [%c]\n", c_test));
	printf("%d\n", ft_printf("ft_printf: [%c]\n", c_test));
	printf("%d\n", printf("Or_printf: [%s]\n", s_test));
	printf("%d\n", ft_printf("ft_printf: [%s]\n", s_test));
	printf("%d\n", printf("Or_printf: [%p]\n", p_test));
	printf("%d\n", ft_printf("ft_printf: [%p]\n", p_test));
	printf("%d\n", printf("Or_printf: [%x]\n", xX_test));
	printf("%d\n", ft_printf("ft_printf: [%x]\n", xX_test));
	printf("%d\n", printf("Or_printf: [%X]\n", xX_test));
	printf("%d\n", ft_printf("ft_printf: [%X]\n", xX_test));
	printf("%d\n", printf("Or_printf: [%%]\n"));
	printf("%d\n", ft_printf("ft_printf: [%%]\n"));
	printf("%d\n", printf("Or_printf: [%d]\n", -2147483647));
	printf("%d\n", ft_printf("ft_printf: [%d]\n", -2147483647));
	return (0);
}
