/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:56:48 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/10/23 23:32:31 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_percent_count(const char *str)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '%')
			count++;
		index++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int	current_arg;
	va_list		arg_list;
	int	test = 0;

	va_start(arg_list, str);
	current_arg = va_arg(arg_list, int); // arguments pointer is ++ when this is called
	printf("%s\n", str);
	printf("arg : %i\n", current_arg);
	test = ft_percent_count(str);
	printf("nombre d'arguments : %i", test);
	va_end(arg_list);
	// il faut un compteur de % pour pouvoir definir combien d'arguments sont passes
	return (0);
}
