/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 22:59:06 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/10/28 15:56:17 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_detect_type(const char *str, int *count, va_list arg_list)
{
	size_t	len;

	len = 0;
	if (str[*count] == '%')
	{
		ft_putchar_fd('%', 1);
		*count = *count + 1;
		return (1);
	}
	else if (str[*count] == 'i')
	{
		len = ft_is_int(arg_list);
		*count = *count + 1;
		return (len);
	}
	else if (str[*count] == 's')
	{
		len = ft_is_string(arg_list);
		*count = *count + 1;
		return (len);
	}
	else
		return (ft_detect_type_2(str, count, arg_list));
}

size_t	ft_detect_type_2(const char *str, int *count, va_list arg_list)
{
	size_t	len;
	long	long_int;

	len = 0;
	if (str[*count] == 'c')
	{
		len = ft_is_char(arg_list);
		*count = *count + 1;
		return (len);
	}
	else if (str[*count] == 'd')
	{
		long_int = va_arg(arg_list, int);
		len = ft_putnbr_base(long_int, "0123456789");
		*count = *count + 1;
		return (len);
	}
	else
		return (ft_detect_type_3(str, count, arg_list));
}

size_t	ft_detect_type_3(const char *str, int *count, va_list arg_list)
{
	size_t	len;

	len = 0;
	if (str[*count] == 'x')
	{
		len = ft_putnbr_base_hexa
			((unsigned int)va_arg(arg_list, unsigned int), "0123456789abcdef");
		*count = *count + 1;
		return (len);
	}
	else if (str[*count] == 'X')
	{
		len = ft_putnbr_base_hexa
			((unsigned int)va_arg(arg_list, unsigned int), "0123456789ABCDEF");
		*count = *count + 1;
		return (len);
	}
	else
		return (ft_detect_type_4(str, count, arg_list));
}

size_t	ft_detect_type_4(const char *str, int *count, va_list arg_list)
{
	size_t	len;

	len = 0;
	if (str[*count] == 'u')
	{
		len = ft_putnbr_base_unsigned
			((unsigned int)va_arg(arg_list, unsigned int), "0123456789");
		*count = *count + 1;
		return (len);
	}
	else if (str[*count] == 'p')
	{
		len = ft_putnbr_pointer
			((void *)va_arg(arg_list, void *), "0123456789abcdef");
		*count = *count + 1;
		return (len);
	}
	return (len);
}
