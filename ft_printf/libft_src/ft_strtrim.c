/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:01:15 by hjeon             #+#    #+#             */
/*   Updated: 2020/04/04 13:22:07 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool	is_set(char c, char *set)
{
	while (*set)
	{
		if (*set == c)
			return (TRUE);
		set++;
	}
	return (FALSE);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char		*ptr;
	size_t		s1_len;
	int			i;

	s1_len = ft_strlen(s1);
	ptr = ft_calloc((s1_len + 2), sizeof(char));
	if (!ptr)
		return (NULL);
	*ptr = 0;
	while (*s1 && is_set(*s1, (char *)set))
		s1++;
	i = -1;
	while (*(s1 + (++i)))
		*(ptr + i) = *(s1 + i);
	*(ptr + i) = 0;
	i = (i > 0) ? i - 1 : 0;
	while (*(s1 + i) && is_set(*(s1 + i), (char *)set))
		*(ptr + i--) = 0;
	return (ptr);
}
