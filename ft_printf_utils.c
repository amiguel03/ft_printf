/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:43:09 by amiguel-          #+#    #+#             */
/*   Updated: 2023/12/12 11:54:16 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_c(int num, int counter)
{
	long	aux_n;
	int		digit;

	aux_n = num;
	if (aux_n < 0)
	{
		write(1, "-", 1);
		counter++;
		aux_n = -aux_n;
	}
	if (aux_n >= 10)
		counter = ft_putnbr_c(aux_n / 10, counter);
	digit = aux_n % 10 + 48;
	write(1, &digit, 1);
	counter++;
	return (counter);
}

int	ft_putnbr_unsigned(unsigned int num, int counter)
{
	long	aux_n;
	char	digit;

	aux_n = num;
	if (aux_n >= 10)
		counter = ft_putnbr_c(aux_n / 10, counter);
	digit = aux_n % 10 + 48;
	write(1, &digit, 1);
	counter++;
	return (counter);
}

int	ft_hexa_min(unsigned long long h, int counter)
{
	char	*minus;

	minus = "0123456789abcdef";
	if (h < 16)
		counter = ft_putchar_c(minus[h], counter);
	else
	{
		counter = ft_hexa_min(h / 16, counter);
		counter = ft_hexa_min(h % 16, counter);
	}
	return (counter);
}

int	ft_hexa_mayus(unsigned long long h, int counter)
{
	char	*mayus;

	mayus = "0123456789ABCDEF";
	if (h < 16)
		counter = ft_putchar_c(mayus[h], counter);
	else
	{
		counter = ft_hexa_mayus(h / 16, counter);
		counter = ft_hexa_mayus(h % 16, counter);
	}
	return (counter);
}

int	ft_putptr_c(void *ptr, int counter)
{
	counter = ft_putstr_c("0x", counter);
	counter = ft_hexa_min((unsigned long)ptr, counter);
	return (counter);
}
