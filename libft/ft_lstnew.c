/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:33:06 by dglaser           #+#    #+#             */
/*   Updated: 2017/10/05 22:32:06 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newnext;

	newnext = (t_list *)malloc(sizeof(t_list));
	if (newnext == NULL)
		return (NULL);
	if (content == NULL)
	{
		newnext->content = NULL;
		newnext->content_size = 0;
	}
	else
	{
		newnext->content = (void*)ft_memalloc(content_size);
		ft_memcpy(newnext->content, content, content_size);
		newnext->content_size = content_size;
	}
	newnext->next = NULL;
	return (newnext);
}
