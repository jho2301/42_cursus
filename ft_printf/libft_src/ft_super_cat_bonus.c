/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_super_cat_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:47:12 by hjeon             #+#    #+#             */
/*   Updated: 2020/04/08 12:24:05 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strcat(char *dst, char *src, int size)
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

char			*ft_super_cat(char *dst, char *src)
{
	char	*result;
	int		dst_len;
	int		src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (!(result = ft_calloc((dst_len + src_len + 1), sizeof(char))))
		return (NULL);
	*result = 0;
	if (!result)
		return (0);
	ft_strcat(result, dst, dst_len);
	ft_strcat(result, src, (dst_len + src_len));
	free(dst);
	return (result);
}
