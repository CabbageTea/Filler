/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 19:59:01 by dglaser           #+#    #+#             */
/*   Updated: 2017/10/02 15:23:31 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	a;
	unsigned char	*cpy;
	unsigned char	*rtn;

	i = 0;
	a = (unsigned char)c;
	cpy = (unsigned char *)src;
	rtn = (unsigned char *)dest;
	while (i < n)
	{
		if (cpy[i] == a)
		{
			rtn[i] = cpy[i];
			return (rtn + i + 1);
		}
		rtn[i] = cpy[i];
		i++;
	}
	return (NULL);
}
