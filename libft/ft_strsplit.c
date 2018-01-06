/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 14:07:08 by dglaser           #+#    #+#             */
/*   Updated: 2017/10/05 17:24:26 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(const char *s, char c)
{
	size_t	words;

	words = 0;
	while (s && *s)
	{
		if (*s != c)
		{
			words++;
			s = ft_strchr(s, c);
		}
		else
			s++;
	}
	return (words);
}

char			**ft_strsplit(const char *s, char c)
{
	size_t	curr;
	size_t	word_count;
	char	**words;
	char	*next;

	word_count = ft_wordcount(s, c);
	words = (char **)ft_memalloc(sizeof(char*) * (word_count + 1));
	if (!words)
		return (NULL);
	curr = 0;
	while (curr < word_count)
	{
		while (*s == c)
			s++;
		next = ft_strchr(s, c);
		if (next)
			words[curr] = ft_strsub(s, 0, next - s);
		else
			words[curr] = ft_strdup(s);
		s = next;
		curr++;
	}
	return (words);
}
