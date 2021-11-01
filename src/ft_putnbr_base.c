/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:24:09 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/10/28 15:56:18 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_base(long nb, char *base)
{
	int		base_size;
	size_t	size;

	size = ft_nbrlen(nb);
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		nb *= -1;
	}
	base_size = ft_strlen(base);
	if (nb >= base_size)
	{
		ft_putnbr_base(nb / base_size, base);
		ft_putnbr_base(nb % base_size, base);
	}
	else
		write(1, &base[nb], 1);
	return (size);
}

size_t	ft_putnbr_base_hexa(long unsigned int nb, char *base)
{
	unsigned int	base_size;
	size_t			size;

	base_size = ft_strlen(base);
	size = ft_nbrlen_hexa(nb);
	if (nb >= base_size)
	{
		ft_putnbr_base_hexa(nb / base_size, base);
		ft_putnbr_base_hexa(nb % base_size, base);
	}
	else
		write(1, &base[nb], 1);
	return (size);
}

size_t	ft_putnbr_base_unsigned(unsigned int nb, char *base)
{
	unsigned int	base_size;
	size_t			size;

	size = ft_nbrlen(nb);
	base_size = ft_strlen(base);
	if (nb >= base_size)
	{
		ft_putnbr_base_unsigned(nb / base_size, base);
		ft_putnbr_base_unsigned(nb % base_size, base);
	}
	else
		write(1, &base[nb], 1);
	return (size);
}

size_t	ft_putnbr_pointer(void *p, char *base)
{
	size_t	size;

	size = 2;
	ft_putstr_fd("0x", 1);
	size += ft_putnbr_base_hexa((long long) p, base);
	return (size);
}

size_t	ft_putnbr_base_ul(unsigned long nb, char *base)
{
	unsigned long	base_size;
	size_t			size;

	size = ft_nbrlen(nb);
	base_size = (unsigned long)ft_strlen(base);
	if (nb >= base_size)
	{
		ft_putnbr_base_ul(nb / base_size, base);
		ft_putnbr_base_ul(nb % base_size, base);
	}
	else
		write(1, &base[nb], 1);
	return (size);
}
