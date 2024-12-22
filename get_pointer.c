/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkocabay <bkocabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:07:41 by bkocabay          #+#    #+#             */
/*   Updated: 2024/12/06 13:29:56 by bkocabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	hex_len2(unsigned long long n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		counter++;
		n = n / 16;
	}
	return (counter);
}

static int	transformer2(unsigned long long n, int a)
{
	int		i;
	int		len;
	char	hex[30];

	if (n == 0)
		return (write(1, "0", 1));
	len = hex_len2(n);
	i = len;
	hex[i--] = '\0';
	while (n != 0)
	{
		if (n % 16 < 10)
			hex[i] = (n % 16) + '0';
		else
			hex[i] = (n % 16) + 87 + a;
		n = n / 16;
		i--;
	}
	i = 0;
	while (hex[i] != '\0')
		write(1, &hex[i++], 1);
	return (len);
}

int	get_pointer(va_list va)
{
	unsigned long long	n;

	n = va_arg(va, unsigned long long);
	if (n == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (2 + transformer2(n, 0));
}
