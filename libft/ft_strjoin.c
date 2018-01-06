/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 20:28:14 by dglaser           #+#    #+#             */
/*   Updated: 2017/10/05 14:57:28 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*new;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = (s1_len + s2_len);
	new = (char *)malloc(sizeof(new) * (i + 1));
	if (new == 0)
		return (NULL);
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	new[i + 1] = '\0';
	return (new);
}
