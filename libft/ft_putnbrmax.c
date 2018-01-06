/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 20:13:59 by dglaser           #+#    #+#             */
/*   Updated: 2017/12/27 00:18:25 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrmax(intmax_t a)
{
	if (a == -9223372036854775807 - 1)
	{
		ft_putstr("9223372036854775808");
		return ;
	}
	if (a < 0)
	{
		ft_putchar('-');
		a *= -1;
	}
	if (a >= 10)
	{
		ft_putnbrmax(a / 10);
		ft_putnbrmax(a % 10);
	}
	else
		ft_putchar(a + '0');
}