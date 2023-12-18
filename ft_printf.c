/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:55:30 by amiguel-          #+#    #+#             */
/*   Updated: 2023/12/11 17:05:54 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_c(int c, int counter)
{
	write(1, &c, 1);
	counter++;
	return (counter);
}

int	ft_putstr_c(char *str, int counter)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		counter++;
		i++;
	}
	return (counter);
}

int	ft_analyze(const char *str, int i, va_list args, int counter)
{
	if (str[i] == '%')
		counter = ft_putchar_c('%', counter);
	else if (str[i] == 'c')
		counter = ft_putchar_c(va_arg(args, int), counter);
	else if (str[i] == 's')
		counter = ft_putstr_c(va_arg(args, char *), counter);
	else if (str[i] == 'd' || str[i] == 'i')
		counter = ft_putnbr_c(va_arg(args, int), counter);
	else if (str[i] == 'u')
		counter = ft_putnbr_unsigned(va_arg(args, unsigned int), counter);
	else if (str[i] == 'p')
		counter = ft_putptr_c(va_arg(args, void *), counter);
	else if (str[i] == 'x')
		counter = (ft_hexa_min(va_arg(args, unsigned int), counter));
	else if (str[i] == 'X')
		counter = (ft_hexa_mayus(va_arg(args, unsigned int), counter));
	return (counter);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		counter;
	va_list	args;

	va_start(args, str);
	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			counter = ft_analyze((char *)str, i, args, counter);
		}
		else
			counter = ft_putchar_c(str[i], counter);
		i++;
	}
	va_end(args);
	return (counter);
}
