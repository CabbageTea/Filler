/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 20:24:40 by dglaser           #+#    #+#             */
/*   Updated: 2017/10/05 14:56:49 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*cpy;
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	i = ft_strlen(src);
	cpy = (char *)malloc(sizeof(char) * (i + 1));
	if (cpy == 0)
		return (NULL);
	while (src[x] != '\0')
	{
		cpy[x] = src[x];
		x++;
	}
	cpy[x] = '\0';
	return (cpy);
}
