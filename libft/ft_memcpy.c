/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 20:05:17 by dglaser           #+#    #+#             */
/*   Updated: 2017/10/02 15:44:17 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cpy;
	unsigned char	*rtn;

	i = 0;
	cpy = (unsigned char *)src;
	rtn = (unsigned char *)dest;
	while (i < n)
	{
		rtn[i] = cpy[i];
		i++;
	}
	return (dest);
}
