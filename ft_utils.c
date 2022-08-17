/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:48:16 by pmikada           #+#    #+#             */
/*   Updated: 2022/07/28 14:29:38 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(char c, int *c_str)
{
	write(1, &c, 1);
	*c_str += 1;
}

void	ft_mul_print(char *s, int *c_str)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*c_str += 6;
		return ;
	}	
	while (s[i])
		ft_print(s[i++], c_str);
}

void	ft_print_base(unsigned long ad, int *c_str, int base, char *check)
{
	if (ad <= 9 && base == 10)
	{
		ft_print(ad + '0', c_str);
		return ;
	}
	else if (ad <= 16 && base == 16)
	{
		if (ad != 0 && ad % 16 == 0)
			ft_print('1', c_str);
		ft_print(check[ad % base], c_str);
		return ;
	}
	else if (ad > 9 && base == 10)
	{
		ft_print_base(ad / base, c_str, base, check);
		ft_print((ad % base) + '0', c_str);
	}
	else if (ad > 16 && base == 16)
	{
		ft_print_base(ad / base, c_str, base, check);
		ft_print(check[ad % base], c_str);
	}
}

void	ft_print_num(int num, int *c_str)
{
	if (num == -2147483648)
	{
		ft_mul_print("-2147483648", c_str);
		return ;
	}
	else if (num < 0)
	{
		ft_print('-', c_str);
		num *= -1;
		ft_print_num(num, c_str);
		return ;
	}
	if (num <= 9)
	{
		ft_print(num + '0', c_str);
		return ;
	}
	else if (num > 9)
	{
		ft_print_num(num / 10, c_str);
		ft_print((num % 10) + '0', c_str);
	}
}

void	ft_address(unsigned long ad, int *c_str)
{
	write(1, "0x", 2);
	*c_str += 2;
	ft_print_base(ad, c_str, 16, "0123456789abcdef");
}
