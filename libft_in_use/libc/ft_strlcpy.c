/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 08:50:45 by hjeon             #+#    #+#             */
/*   Updated: 2020/02/25 19:18:24 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** guarantee to NUL-terminate the result
*/

size_t			ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		src_len;

	src_len = ft_strlen(src);
	if (!size)
		return (src_len);
	i = 0;
	while (i + 1 < size && *(src + i))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = 0;
	return (src_len);
}
