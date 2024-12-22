/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkocabay <bkocabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:40:24 by bkocabay          #+#    #+#             */
/*   Updated: 2024/11/16 13:18:04 by bkocabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_len(long long nb)
{
	int	counter;

	counter = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		counter++;
	while (nb != 0)
	{
		nb = nb / 10;
		counter++;
	}
	return (counter);
}

static void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n < 10)
	{
		c = n + 48;
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		c = n % 10 + 48;
		write(1, &c, 1);
	}
}

static void	putnbr_usigned(unsigned int n)
{
	char	c;

	if (n < 10)
	{
		c = n + 48;
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		c = n % 10 + 48;
		write(1, &c, 1);
	}
}

int	get_int(va_list va)
{
	int	n;

	n = va_arg(va, int);
	ft_putnbr(n);
	return (num_len(n));
}

int	get_unsigned(va_list va)
{
	unsigned int	n;

	n = va_arg(va, unsigned int);
	putnbr_usigned(n);
	return (num_len(n));
}
