/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 20:19:05 by dglaser           #+#    #+#             */
/*   Updated: 2017/10/05 14:56:11 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*ret;
	size_t	i;
	size_t	x;

	x = 0;
	i = ft_strlen(str);
	if (c == '\0')
	{
		ret = (char *)str;
		return (&ret[i]);
	}
	while (x <= i)
	{
		if (str[x] == c)
		{
			ret = (char *)str;
			return (&ret[x]);
		}
		x++;
	}
	return (NULL);
}
