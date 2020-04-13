/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 09:24:23 by hjeon             #+#    #+#             */
/*   Updated: 2020/02/26 08:24:49 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** the strchr() function returns a pointer
** to the first occurrence of the character c in the string s.
** Here "character" means "byte".
*/

char	*ft_strchr(const char *s, int c)
{
	size_t		i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
			return ((char *)s + i);
		i++;
	}
	if (*(s + i) == c)
		return ((char *)s + i);
	return (NULL);
}
