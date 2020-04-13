/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:01:15 by hjeon             #+#    #+#             */
/*   Updated: 2020/03/03 22:02:17 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
	ptr = ft_calloc((s1_len + 1), sizeof(char));
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

/*
** #include <stdio.h>
** int main(int argc, char const *argv[])
** {
** 	char *s;
** 	argc++;
** 	s = ft_strtrim(argv[1], "b");
** 	printf("%s", s);
** 	return 0;
** }
*/
