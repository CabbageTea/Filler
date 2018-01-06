/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 20:45:40 by dglaser           #+#    #+#             */
/*   Updated: 2017/10/05 15:00:37 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	a;
	size_t	i;
	size_t	x;
	char	*ret;

	a = 0;
	i = 0;
	x = ft_strlen((char *)str);
	while (a++ <= x)
	{
		if (*str == c)
		{
			ret = (char *)str;
			i = 1;
		}
		str++;
	}
	if (i == 1)
		return (ret);
	else
		return (NULL);
}
