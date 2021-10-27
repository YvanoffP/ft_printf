/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:56:48 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/10/27 18:34:34 by ypetruzz         ###   ########.fr       */
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
		if (str[count] == '%')
		{
			count++;
			len += ft_detect_type(str, &count, arg_list);
		}
		else
		{
			ft_putchar_fd(str[count], 1);
			count++;
		}
	}
	va_end(arg_list);
	len = len + (count - (ft_percent_count(str) * 2));
	return (len);
}
