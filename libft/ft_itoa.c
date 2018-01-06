/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 23:38:34 by dglaser           #+#    #+#             */
/*   Updated: 2017/10/05 14:35:39 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int num)
{
	char	*nbr;
	int		i;
	int		len;

	len = ft_intlen(num);
	i = 0;
	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	nbr = (char*)malloc(sizeof(char) * (len + 1));
	if (nbr == 0)
		return (NULL);
	nbr[len--] = '\0';
	if (num < 0)
	{
		num *= -1;
		i = 1;
	}
	while (len >= i)
	{
		nbr[len--] = (num % 10) + 48;
		num = num / 10;
	}
	if (i == 1)
		nbr[len] = '-';
	return (nbr);
}
