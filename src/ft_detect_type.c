/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 22:59:06 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/10/27 22:45:39 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_is_int(va_list arg_list)
{
	int	int_arg;

	int_arg = va_arg(arg_list, int);
	ft_putnbr_fd(int_arg, 1);
	return (ft_nbrlen(int_arg));
}

size_t	ft_is_string(va_list arg_list)
{
	char	*str_arg;

	str_arg = va_arg(arg_list, char *);
	if (str_arg == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	else
		ft_putstr_fd(str_arg, 1);
	return (ft_strlen(str_arg));
}

size_t	ft_is_char(va_list arg_list)
{
	char char_arg;

	char_arg = va_arg(arg_list, int);
	ft_putchar_fd(char_arg, 1);
	return (1);
}

size_t	ft_detect_type(const char *str, int *count, va_list arg_list)
{
	size_t	len;
	long test;

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
	else if (str[*count] == 'c')
	{
		len = ft_is_char(arg_list);
		*count = *count + 1;
		return (len);
	}
	else if (str[*count] == 'd')
	{
		test = va_arg(arg_list, int);
		len = ft_putnbr_base(test, "0123456789");
		*count = *count + 1;
		return (len);
	}
	else if (str[*count] == 'x')
	{
		len = ft_putnbr_base_hexa((unsigned int)va_arg(arg_list, unsigned int), "0123456789abcdef");
		*count = *count + 1;
		return (len);
	}
	else if (str[*count] == 'X')
	{
		len = ft_putnbr_base_hexa((unsigned int)va_arg(arg_list, unsigned int), "0123456789ABCDEF");
		*count = *count + 1;
		return (len);
	}
	else if (str[*count] == 'u')
	{
		len = ft_putnbr_base_unsigned((unsigned int)va_arg(arg_list, unsigned int), "0123456789");
		*count = *count + 1;
		return (len);
	}
	else if (str[*count] == 'p')
	{
		len = ft_putnbr_pointer((void *)va_arg(arg_list, void *), "0123456789abcdef");
		*count = *count + 1;
		return (len);
	}
	return (len);
}
