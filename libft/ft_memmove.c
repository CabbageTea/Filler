/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 20:08:10 by dglaser           #+#    #+#             */
/*   Updated: 2017/10/02 15:44:36 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*str;
	unsigned char	*ret;
	size_t			i;

	i = 0;
	ret = (unsigned char *)dest;
	str = (unsigned char *)src;
	if (ret > str)
	{
		while (len-- > 0)
			ret[len] = str[len];
	}
	else
		while (i < len)
		{
			ret[i] = str[i];
			i++;
		}
	return (ret);
}
