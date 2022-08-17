/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:54:39 by pmikada           #+#    #+#             */
/*   Updated: 2022/07/28 14:39:09 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h> 
# include <stdarg.h>

void	ft_print(char c, int *c_str);
void	ft_mul_print(char *s, int *c_str);
void	ft_print_base(unsigned long ad, int *c_str, int base, char *check);
void	ft_print_num(int num, int *c_str);
void	ft_address(unsigned long ad, int *c_str);
int		ft_printf(const char *start, ...);

#endif
