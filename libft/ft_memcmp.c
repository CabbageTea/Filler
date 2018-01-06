/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 20:03:01 by dglaser           #+#    #+#             */
/*   Updated: 2017/10/02 20:17:07 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*s1;
	const unsigned char	*s2;

	if ((str1 == str2) || (n == 0))
		return (0);
	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	while (n--)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
	}
	return (0);
}
