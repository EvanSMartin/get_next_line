/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ispirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 14:36:45 by ispirido          #+#    #+#             */
/*   Updated: 2018/05/11 18:24:42 by ispirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_read(const int fd, char **bff)
{
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			i;

	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		if (!*bff)
			*bff = ft_strdup(buf);
		else
		{
		tmp = *bff;
		*bff = ft_strjoin(*bff, buf);
		free(tmp);
		}
	}
	return (i);
}		

int		find_n_l(char **bff, char **line)
{
	char	*check_for_n_l;

	if ((check_for_n_l = ft_strchr(*bff, '\n')))
	{
		*check_for_n_l = '\0';
		*line = ft_strdup(*bff);
		*bff = ft_strcpy(*bff, check_for_n_l + 1);
		return (1);
	}
	if (**bff)
	{
		*line = ft_strdup(*bff);
		*bff = ft_strnew(BUFF_SIZE + 1);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*bff[4864];

	if (fd < 0 || fd > 4864 || line == NULL || !line || BUFF_SIZE < 1 ||
	ft_read(fd, &bff[fd]) < 0)
		return (-1);
	if (find_n_l(&bff[fd], line))
		return (1);
	return (0);
}
