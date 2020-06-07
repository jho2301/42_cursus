/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 21:06:21 by hjeon             #+#    #+#             */
/*   Updated: 2020/04/06 09:45:20 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n && *((char *)src + i))
	{
		*((char *)dest + i) = *((char *)src + i);
		i++;
	}
	*((char *)dest + i) = 0;
	return (dest);
}

int		do_get_line(int fd, char *buf, char **line)
{
	int		i;

	while ((i = read(fd, buf, BUFFER_SIZE)))
	{
		if (i == -1)
			return (-1);
		*(buf + i) = 0;
		if (!(*line = super_cat(*line, buf, BUFFER_SIZE)))
			return (-1);
		if ((i = ft_strchr(*line, '\n')) != -1)
		{
			*(*line + i) = 0;
			ft_memmove(buf, *line + i + 1, BUFFER_SIZE);
			return (1);
		}
	}
	buf[0] = 0;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		buf[BUFFER_SIZE + 1];
	int				i;

	if (!line || !(*line = ft_calloc(1, sizeof(char))))
		return (-1);
	**line = 0;
	if (*buf)
		if (!(*line = super_cat(*line, buf, BUFFER_SIZE)))
			return (-1);
	if ((i = ft_strchr(*line, '\n')) != -1)
	{
		*(*line + i) = 0;
		ft_memmove(buf, *line + i + 1, BUFFER_SIZE);
		return (1);
	}
	i = do_get_line(fd, buf, line);
	if (i == 1)
		return (1);
	else if (i == -1)
	{
		*line = 0;
		return (-1);
	}
	return (0);
}
