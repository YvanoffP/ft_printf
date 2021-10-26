/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 22:59:06 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/10/23 23:32:39 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	a;
	int b;
	char *str;
	char c;
	unsigned int unsint;

	unsint = 4294967293;
	str = ft_strdup("mama la phrase");
	c = 'u';
	a = 11234;
	b = 1209;


	ft_printf("Let's print a modulo kek %%\nThis is my string yaya : %s\nAnd this is my int : %i\n", str, a);
	ft_printf("Here comes a char rofl %c\nWhat about a base 10 number yay : %d\n", c, b);
	ft_printf("Now we print %i in hexa, which is : %x\n", a, a);
	ft_printf("What about this unsigned int : %u\n", unsint);
	ft_printf("This is the address if pointer str : %p\n", str);
}
