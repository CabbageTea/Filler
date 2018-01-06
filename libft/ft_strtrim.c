/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 20:51:48 by dglaser           #+#    #+#             */
/*   Updated: 2017/10/05 15:14:58 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int				i;
	int				x;
	int				y;
	char			*new;

	y = 0;
	i = 0;
	if (!s)
		return (NULL);
	x = (int)(ft_strlen(s) - 1);
	while (s[x] == ' ' || s[x] == '\n' || s[x] == '\t')
		x--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		x--;
		i++;
	}
	x = (x <= 0) ? 0 : x;
	new = (char*)malloc(sizeof(char) * (x + 2));
	if (new == NULL)
		return (NULL);
	while (y <= x)
		new[y++] = s[i++];
	new[y] = '\0';
	return (new);
}
