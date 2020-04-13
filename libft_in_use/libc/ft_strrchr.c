/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 09:45:26 by hjeon             #+#    #+#             */
/*   Updated: 2020/02/26 08:25:55 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	char		*rchr;
	t_bool		is_found;

	i = 0;
	is_found = FALSE;
	while (*(s + i))
	{
		if (*(s + i) == c)
		{
			rchr = (char *)s + i;
			is_found = TRUE;
		}
		i++;
	}
	if (*(s + i) == c)
	{
		rchr = (char *)s + i;
		is_found = TRUE;
	}
	if (is_found)
		return (rchr);
	else
		return (NULL);
}
