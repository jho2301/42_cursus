/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:21:40 by hjeon             #+#    #+#             */
/*   Updated: 2020/04/04 13:04:45 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memcpy() copies n bytes from memory area src to memory area dest.
** The memory areas must not overlap.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == 0 && src == 0)
		return (dest);
	i = 0;
	while (i < n)
	{
		*((unsigned char*)dest + i) = *((unsigned char*)src + i);
		i++;
	}
	return (dest);
}
