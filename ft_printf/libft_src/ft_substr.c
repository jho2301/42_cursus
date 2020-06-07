/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:14:27 by hjeon             #+#    #+#             */
/*   Updated: 2020/04/05 01:16:28 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		i;

	ptr = ft_calloc((len + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	if (ft_strlen(s) < start)
		return (ptr);
	while (i < len && *(s + start + i))
	{
		*(ptr + i) = *(s + start + i);
		i++;
	}
	return (ptr);
}
