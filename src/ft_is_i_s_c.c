/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_i_s_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:41:33 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/10/28 15:55:31 by ypetruzz         ###   ########.fr       */
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
	char	char_arg;

	char_arg = va_arg(arg_list, int);
	ft_putchar_fd(char_arg, 1);
	return (1);
}
