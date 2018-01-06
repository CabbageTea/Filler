/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 20:29:26 by dglaser           #+#    #+#             */
/*   Updated: 2017/10/05 22:01:13 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t i;
	size_t q;
	size_t a;

	a = 0;
	i = ft_strlen(dest);
	q = ft_strlen(src);
	if (i >= len)
	{
		return (q + len);
	}
	while ((dest[a] != '\0') && (a < (len - 1)))
		a++;
	while ((*src != '\0') && (a < (len - 1)))
	{
		dest[a] = *src;
		a++;
		src++;
	}
	dest[a] = '\0';
	return (i + q);
}
