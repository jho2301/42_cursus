/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 09:53:59 by hjeon             #+#    #+#             */
/*   Updated: 2020/02/26 14:39:54 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** locates the	first occurrence of the	null-terminated string in the string,
** where not more than len characters are searched.
** Characters that appear after a `\0' character are not searched.
*/

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (*(big + i) && i < len)
	{
		j = 0;
		while (*(big + i + j) == *(little + j) && i + j < len)
		{
			j++;
			if (!*(little + j))
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
/*
** 
** #include <bsd/string.h>
** #include "stdio.h"
** int main()
** {
** 	char	*s1 = "MZIRIBMZIRIBMZE123";
** 	char	*s2 = "MZIRIBMZE";
** 	size_t	max = strlen(s2);
** 
** 	char	*i1 = strnstr(s1, s2, max);
** 	char	*i2 = ft_strnstr(s1, s2, max);
** 	printf("original : %s\n", i1);
** 	printf("ft_mine : %s\n", i2);
** 	return 0;
** }
** 
*/
