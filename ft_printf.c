/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkocabay <bkocabay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:26:38 by bkocabay          #+#    #+#             */
/*   Updated: 2024/12/16 14:08:33 by bkocabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	control(char c, va_list va)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter = get_char(va);
	else if (c == 's')
		counter = get_string(va);
	else if (c == 'd' || c == 'i')
		counter = get_int(va);
	else if (c == 'u')
		counter = get_unsigned(va);
	else if (c == 'x')
		counter = get_hex_lower(va);
	else if (c == 'X')
		counter = get_hex_upper(va);
	else if (c == '%')
		counter = write(1, "%%", 1);
	else if (c == 'p')
		counter = get_pointer(va);
	else
	{
		counter = write(1, "%%", 1);
		counter = counter + write(1, &c, 1);
	}
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	va;
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	va_start(va, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			counter += control(format[++i], va);
		else
		{
			write(1, &format[i], 1);
			counter++;
		}
		i++;
	}
	va_end(va);
	return (counter);
}
