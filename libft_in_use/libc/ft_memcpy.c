/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:21:40 by hjeon             #+#    #+#             */
/*   Updated: 2020/02/26 14:40:42 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** The memcpy() copies n bytes from memory area src to memory area dest.
** The memory areas must not overlap.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n) // src 길이구해서 while 조건으로 넣기
	{
		*((unsigned char *)dest + i) = *((unsigned char *)src + i); 
		i++;
	}
	return (dest);
}
