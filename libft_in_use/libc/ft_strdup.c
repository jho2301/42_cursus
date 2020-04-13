/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:02:03 by hjeon             #+#    #+#             */
/*   Updated: 2020/03/03 21:58:31 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**  The  strdup() function returns a pointer to a new string
**  which is a duplicate of the string s.
**  Memory forthe new string is obtained with ft_calloc(3)
*/

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(s);
	ptr = ft_calloc((src_len + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		*(ptr + i) = *(s + i);
		i++;
	}
	return (ptr);
}
