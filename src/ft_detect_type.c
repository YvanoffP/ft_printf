/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 22:59:06 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/10/23 23:32:39 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_is_int(va_list arg_list)
{
	int	int_arg;

	int_arg = va_arg(arg_list, int);
	ft_putnbr_fd(int_arg, 1);
}

void	ft_is_string(va_list arg_list)
{
	char	*str_arg;

	str_arg = va_arg(arg_list, char *);
	ft_putstr_fd(str_arg, 1);
}

void	ft_is_char(va_list arg_list)
{
	char char_arg;

	char_arg = va_arg(arg_list, int);
	ft_putchar_fd(char_arg, 1);
}

void	ft_detect_type(const char *str, int *count, va_list arg_list)
{
	*count = *count + 1;
	if (str[*count] == '%')
	{
		ft_putchar_fd('%', 1);
		*count = *count + 1;
		return ;
	}
	else if (str[*count] == 'i')
	{
		ft_is_int(arg_list);
		*count = *count + 1;
		return ;
	}
	else if (str[*count] == 's')
	{
		ft_is_string(arg_list);
		*count = *count + 1;
		return ;
	}
	else if (str[*count] == 'c')
	{
		ft_is_char(arg_list);
		*count = *count + 1;
		return ;
	}
	else if (str[*count] == 'd')
	{
		ft_putnbr_base((int)va_arg(arg_list, int), "0123456789");
		*count = *count + 1;
		return ;
	}
	else if (str[*count] == 'x')
	{
		ft_putnbr_base((int)va_arg(arg_list, int), "0123456789ABCDEF");
		*count = *count + 1;
		return ;
	}

}
