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

static size_t	ft_percent_count(const char *str)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '%')
		{
			count++;
			if (str[index + 1] == '%')
				index++;
		}
		index++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg_list;
	size_t	len;
	int		count;

	len = 0;
	count = 0;
	va_start(arg_list, str);
	while (str[count] != '\0')
	{
		ft_putchar_fd(str[count], 1);
		if (str[count + 1] == '%')
		{
			count++;
			len += ft_detect_type(str, &count, arg_list);
		}
		else
			count++;
	}
	//current_arg = va_arg(arg_list, int); // arguments pointer is ++ when this is called




	va_end(arg_list);
	len = len + (count - ft_percent_count(str));
	// il faut un compteur de % pour pouvoir definir combien d'arguments sont passes
	// retourner count - le nbr d'arguments + la len traitee dans les
	// fonctions
	return (len);
}
