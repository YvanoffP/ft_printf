/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:58:31 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/10/23 23:18:32 by ypetruzz         ###   ########.fr       */
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
void    ft_detect_type(const char *str, int *count, va_list arg_list);
void    ft_putnbr_base(int nb, char *base);
void    ft_putnbr_base_unsigned(unsigned int nb, char *base);
void    ft_putnbr_base_address(void *p, char *base);
void    ft_putnbr_base_llu(unsigned long long nb, char *base);

#endif
