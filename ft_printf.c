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
		printf("cc\n");
		if (str[index] == '%')
			count++;
		index++;
	}
	return (count);
}

int	ft_printf(const char *arg, ...)
{
	const char	*current_arg;
	va_list		arguments;
	int	test = 0;

	va_start(arguments, arg);
	current_arg = va_arg(arguments, const char *); // arguments pointer is ++ when this is called
	printf("%s", current_arg);
	test = ft_percent_count(current_arg);
	printf("nombre d'arguments : %i", test);
	// il faut un compteur de % pour pouvoir definir combien d'arguments sont passes
	return (0);	
}
