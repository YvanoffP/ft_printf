/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 19:13:40 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/10/27 21:05:25 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

size_t	ft_nbrlen(long long int nbr)
{
	size_t	count;

	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		count++;
		nbr *= -1;
	}
	if (nbr < 0)
	{
		count++;
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}
