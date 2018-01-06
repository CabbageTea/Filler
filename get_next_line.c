/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:41:10 by dglaser           #+#    #+#             */
/*   Updated: 2017/11/14 18:04:01 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_freetmp(char *tmp, char *buf)
{
	size_t	i;
	char	*new;
	size_t	tmp_len;
	size_t	buf_len;

	if (!tmp || !buf)
		return (NULL);
	tmp_len = ft_strlen(tmp);
	buf_len = ft_strlen(buf);
	i = (tmp_len + buf_len);
	new = (char *)malloc(sizeof(new) * (i + 1));
	if (new == 0)
		return (NULL);
	ft_strcpy(new, tmp);
	ft_strcat(new, buf);
	new[i + 1] = '\0';
	ft_strdel(&tmp);
	return (new);
}

int		ft_check_tmp(char **tmp, char **line, int i, int x)
{
	char *add;

	x = ft_strlen(*tmp);
	while (i < x)
	{
		if (tmp[0][i] == '\n')
		{
			add = ft_strsub(*tmp, 0, i);
			*line = ft_strdup(add);
			ft_strdel(&add);
			add = ft_strsub(*tmp, i + 1, x - i);
			free(*tmp);
			*tmp = ft_strdup(add);
			ft_strdel(&add);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_read_buf(int ret, char *buf, char **tmp)
{
	buf[ret] = '\0';
	if (*tmp)
	{
		*tmp = ft_strjoin_freetmp(*tmp, buf);
	}
	else
		*tmp = ft_strdup(buf);
}

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	static char	*tmp;

	if (tmp && ft_check_tmp(&tmp, line, 0, 0) == 1)
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		ft_read_buf(ret, buf, &tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	if ((ret == -1) || (!line) || (fd < 0))
		return (-1);
	if ((tmp) && ft_check_tmp(&tmp, line, 0, 0) == 1)
		return (1);
	if ((ret == 0) && (tmp) && (ft_strlen(tmp)))
	{
		*line = ft_strdup(tmp);
		free(tmp);
		tmp = NULL;
		return (1);
	}
	return (0);
}
