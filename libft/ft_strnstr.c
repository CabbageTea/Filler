/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 20:44:26 by dglaser           #+#    #+#             */
/*   Updated: 2017/10/05 22:25:44 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t i;
	size_t x;
	size_t y;

	i = 0;
	x = 0;
	y = 0;
	if (lit[i] == '\0')
		return ((char *)big);
	while ((big[i] != '\0') && (i < len))
	{
		y = i;
		x = 0;
		while ((big[y] == lit[x]) && (y <= len))
		{
			y++;
			x++;
			if (lit[x] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
