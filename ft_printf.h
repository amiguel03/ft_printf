/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:13:21 by amiguel-          #+#    #+#             */
/*   Updated: 2023/12/11 17:08:02 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

int	ft_putchar_c(int c, int counter);
int	ft_putnbr_c(int num, int counter);
int	ft_putstr_c(char *str, int counter);
int	ft_putnbr_unsigned(unsigned int num, int counter);
int	ft_hexa_min(unsigned long long h, int counter);
int	ft_hexa_mayus(unsigned long long h, int counter);
int	ft_putptr_c(void *ptr, int counter);
int	ft_printf(char const *str, ...);

#endif