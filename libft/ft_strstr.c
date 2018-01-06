/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 20:48:56 by dglaser           #+#    #+#             */
/*   Updated: 2017/09/28 20:48:58 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *lit)
{
	int i;
	int x;
	int y;

	x = 0;
	i = 0;
	y = 0;
	if (lit[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0')
	{
		y = i;
		x = 0;
		while (big[y] == lit[x])
		{
			y++;
			x++;
			if (lit[x] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
