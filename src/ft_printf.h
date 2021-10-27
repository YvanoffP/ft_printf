/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:58:31 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/10/27 22:55:14 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include "../libft/libft.h"
# include <stdarg.h>
# include <string.h>
# include <unistd.h>


int     ft_printf(const char *, ...);
size_t  ft_detect_type(const char *str, int *count, va_list arg_list);
size_t  ft_putnbr_base(long nb, char *base);
size_t  ft_putnbr_base_unsigned(unsigned int nb, char *base);
size_t  ft_putnbr_base_address(void *p, char *base);
size_t  ft_putnbr_base_ul(unsigned long nb, char *base);
size_t  ft_putnbr_base_hexa(long unsigned int nb, char *base);
size_t  ft_putnbr_pointer(void *p, char *base);
size_t  ft_nbrlen(long long int nbr);
size_t  ft_nbrlen_hexa(unsigned long nb);

#endif
