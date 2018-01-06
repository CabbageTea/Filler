/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 20:01:08 by dglaser           #+#    #+#             */
/*   Updated: 2017/10/02 15:44:50 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*cpy;
	unsigned char	a;
	int				i;

	a = (unsigned char)c;
	cpy = (unsigned char *)str;
	i = 0;
	while (n > 0)
	{
		if (cpy[i] == a)
			return (cpy + i);
		i++;
		n--;
	}
	return (NULL);
}
