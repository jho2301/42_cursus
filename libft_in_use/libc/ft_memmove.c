/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:40:11 by hjeon             #+#    #+#             */
/*   Updated: 2020/02/26 14:40:34 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**  The  memmove()  function  copies  n bytes from memory area src to memory area dest.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;

	i = -1;
	if (dest <= src)
		while (++i < n)
			*((char *)dest + i) = *((char *)src + i);
	else
		while (++i < n)
			*((char *)dest + n - 1 - i) = *((char *)src + n - 1 - i);
	return (dest);
}
