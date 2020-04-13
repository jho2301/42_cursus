/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:15:48 by hjeon             #+#    #+#             */
/*   Updated: 2020/02/26 08:14:03 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** The memccpy() function copies no more than n bytes from memory area src
** to memory area dest, stopping when the character c is found.
** If the memory areas overlap, the results are undefined.
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	t_bool		is_found;

	i = 0;
	is_found = FALSE;
	while (i < n && *((unsigned char *)src + i))
	{
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		i++;
		if (*((unsigned char *)src + i - 1) == c)
		{
			is_found = TRUE;
			break ;
		}
	}
	if (is_found)
		return (dest + i);
	else
		return (NULL);
}
