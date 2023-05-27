/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:02:49 by uviana-a          #+#    #+#             */
/*   Updated: 2023/05/26 16:02:53 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

//START FT_ITOA
static	int	ft_get_len(long int n)
{
	long int	len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n = n *(-1);
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static	char	*inp_itoa(long int num, int len, char *str_ft_itoa)
{
	int	i;

	i = 1;
	if (num == 0)
		str_ft_itoa[0] = '0';
	while (num > 0)
	{
		str_ft_itoa[len - i] = num % 10 + '0';
		num = num / 10;
		i++;
	}
	return (str_ft_itoa);
}

char	*ft_itoa(int n)
{
	char	*str_ft_itoa;
	char	*str_ft_itoa2;
	long	num;
	int		len;

	len = ft_get_len(n);
	str_ft_itoa = (char *)malloc(sizeof(char) * (len + 1));
	if (!str_ft_itoa)
		return (NULL);
	if (n < 0)
	{
		num = (long)n * (-1);
		str_ft_itoa[0] = '-';
	}
	else
		num = n;
	str_ft_itoa2 = inp_itoa(num, len, str_ft_itoa);
	str_ft_itoa2[len] = '\0';
	return (str_ft_itoa2);
}
//END FT_ITOA

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(const char c)
{
	return (write(1, &c, 1));
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_hex_base(unsigned long decimal_address, int flag)
{
	int	letter_counter;
	char		*base;

	letter_counter = 0;
	if (flag == 'X')
		base = "0123456789ABCDEF";
	if (flag == 'x')
		base = "0123456789abcdef";
	if (decimal_address >= 16)
	{
		letter_counter += ft_hex_base(decimal_address / 16, flag);
		letter_counter += ft_hex_base(decimal_address % 16, flag);
	}
	else
	{
		letter_counter += ft_putchar(base[decimal_address]);
	}
	return (letter_counter);
}

int	flag_conversor(char flag, va_list args)
{
	int	letter_counter;
	char	*int_converted;

	letter_counter = 0;
	if (flag == '%')
		letter_counter += ft_putchar('%');
	if (flag == 'c')
		letter_counter += ft_putchar(va_arg(args, int));
	if (flag == 's')
		letter_counter += ft_putstr(va_arg(args, char *));
	if (flag == 'p')
	{
		letter_counter += ft_putstr("0x");
		letter_counter += ft_hex_base(va_arg(args, unsigned long), 'x');
	}
	if (flag == 'x' || flag == 'X')
		letter_counter += ft_hex_base(va_arg(args, unsigned long), flag);
	if (flag == 'd' || flag == 'i')
	{
		int_converted = ft_itoa(va_arg(args, int));//If it don't work I can use the ft_putnbr() function.
		ft_putstr(int_converted);
		letter_counter += ft_strlen(int_converted);
	}
	else
	{
		//write(1,"a",1);
	}
	return (letter_counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	const char	*ptr = str;
	int	letter_counter;

	letter_counter = 0;
	va_start(args, str);
	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			ptr++;
			letter_counter += flag_conversor(*ptr, args);
		}
		else
		{
			letter_counter += ft_putchar(*ptr);
		}
		ptr++;
	}
	va_end(args);
	return (letter_counter);
}

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
