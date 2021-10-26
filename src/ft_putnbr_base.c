/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:24:09 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/10/12 22:20:35 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(int nb, char *base)
{
	int	base_size;

	base_size = ft_strlen(base);
	if (nb >= base_size)
	{
		ft_putnbr_base(nb / base_size, base);
		ft_putnbr_base(nb % base_size, base);
	}
	else
		write(1, &base[nb], 1);
}

void	ft_putnbr_base_unsigned(unsigned int nb, char *base)
{
	unsigned int	base_size;

	base_size = ft_strlen(base);
	if (nb >= base_size)
	{
		ft_putnbr_base_unsigned(nb / base_size, base);
		ft_putnbr_base_unsigned(nb % base_size, base);
	}
	else
		write(1, &base[nb], 1);
}

void	ft_putnbr_base_address(void *p, char *base)
{
	unsigned long long	nb;

	nb = (unsigned long long)&p;
	printf("\n NB = %llu", nb);
	ft_putnbr_base_ull(nb, base);
}

void	ft_putnbr_base_llu(unsigned long long nb, char *base)
{
	unsigned long long	base_size;

	base_size = (unsigned long long)ft_strlen(base);
	if (nb >= base_size)
	{
		ft_putnbr_base_llu(nb / base_size, base);
		ft_putnbr_base_llu(nb % base_size, base);
	}
	else
		write(1, &base[nb], 1);
}
