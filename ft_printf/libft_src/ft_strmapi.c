/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:52:13 by hjeon             #+#    #+#             */
/*   Updated: 2020/04/04 00:43:41 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	size_t	s_len;
	int		i;

	s_len = ft_strlen(s);
	ptr = ft_calloc((s_len + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(ptr + i) = f(i, *(s + i));
		i++;
	}
	return (ptr);
}
