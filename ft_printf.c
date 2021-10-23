/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:56:48 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/10/23 20:08:48 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printf(const char *arg ...)
{
	const char	*current_arg;
	va_list		arguments;

	va_start(arguments, first);
	current_arg = va_arg(arguments, const char *); // arguments pointer is ++ when this is called

	// il faut un compteur de % pour pouvoir definir combien d'arguments sont passes
	
}
