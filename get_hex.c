/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkocabay <bkocabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:33:38 by bkocabay          #+#    #+#             */
/*   Updated: 2024/12/06 13:18:47 by bkocabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	hex_len(unsigned int n)
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

static int	transformer(unsigned int n, int a)
{
	int		i;
	char	hex[11];
	int		len;

	if (n == 0)
		return (write(1, "0", 1));
	len = hex_len(n);
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

int	get_hex_lower(va_list va)
{
	unsigned int	n;

	n = va_arg(va, unsigned int);
	return (transformer(n, 0));
}

int	get_hex_upper(va_list va)
{
	unsigned int	n;

	n = va_arg(va, unsigned int);
	return (transformer(n, -32));
}
