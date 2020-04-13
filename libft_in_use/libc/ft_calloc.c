/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:02:03 by hjeon             #+#    #+#             */
/*   Updated: 2020/03/03 22:01:08 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The  calloc()  function  allocates  memory
** for an array of nmemb elements of size bytes each
** and returns a pointer to the allocated memory. The memory is set to zero.
** If nmemb or size is 0, then calloc() returns either NULL,
** or a unique pointer value that can later be successfully passed to free().
*/

#include "../libft.h"

void		*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, size * nmemb);
	return (ptr);
}
