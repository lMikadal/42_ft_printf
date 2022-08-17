/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:53:48 by pmikada           #+#    #+#             */
/*   Updated: 2022/07/28 14:40:07 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_next(char c, va_list arg, int *c_str)
{
	if (c == 'c')
		ft_print(va_arg(arg, int), c_str);
	else if (c == 's')
		ft_mul_print(va_arg(arg, char *), c_str);
	else if (c == 'p')
		ft_address(va_arg(arg, unsigned long), c_str);
	else if (c == 'd' || c == 'i')
		ft_print_num(va_arg(arg, int), c_str);
	else if (c == 'u')
		ft_print_base(va_arg(arg, unsigned int), c_str, 10, "0123456789");
	else if (c == 'x')
		ft_print_base(va_arg(arg, unsigned int), c_str, 16, "0123456789abcdef");
	else if (c == 'X')
		ft_print_base(va_arg(arg, unsigned int), c_str, 16, "0123456789ABCDEF");
}

int	ft_printf(const char *start, ...)
{
	va_list	arg;
	int		i;
	int		c_str;

	va_start(arg, start);
	c_str = 0;
	i = 0;
	while (start[i])
	{
		if (start[i] == '%')
		{
			if (start[i + 1] == '%')
			{
				ft_print('%', &c_str);
				i++;
			}
			else
				ft_check_next(start[1 + i++], arg, &c_str);
		}
		else
			ft_print(start[i], &c_str);
		i++;
	}
	va_end(arg);
	return (c_str);
}
