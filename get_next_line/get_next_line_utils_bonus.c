/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 21:06:18 by hjeon             #+#    #+#             */
/*   Updated: 2020/04/04 22:23:56 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	while (i < size * nmemb)
	{
		*((char *)ptr + i) = 0;
		i++;
	}
	return (ptr);
}

size_t		ft_strcat(char *dst, char *src, int size)
{
	int		i;

	while (*dst)
		dst++;
	i = 0;
	while (*(src + i) && i < size)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = 0;
	return (0);
}

int			ft_strchr(const char *s, int c)
{
	size_t		i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
			return (i);
		i++;
	}
	if (*(s + i) == c)
		return (i);
	return (-1);
}

int			ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (*(s + len))
		len++;
	return (len);
}

char		*super_cat(char *dst, char *src, int size)
{
	char	*result;
	int		dst_len;

	dst_len = ft_strlen(dst);
	result = ft_calloc((dst_len + BUFFER_SIZE + 1), sizeof(char));
	if (!result)
		return (NULL);
	ft_strcat(result, dst, dst_len);
	ft_strcat(result, src, size);
	free(dst);
	return (result);
}
