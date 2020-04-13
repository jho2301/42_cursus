/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:17:51 by hjeon             #+#    #+#             */
/*   Updated: 2020/03/03 22:00:28 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int		how_many_strs(const char *str, char delim)
{
	int		cnt;

	cnt = 1;
	while (*str)
	{
		if (*str == delim)
			cnt++;
		str++;
	}
	return (cnt);
}

static char		*ft_strndup(const char *s, size_t n)
{
	char	*ptr;
	size_t	src_len;
	size_t	i;

	src_len = (ft_strlen(s) < n) ? ft_strlen(s) : n;
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

static void		free_ptrs(char **ptrs)
{
	while(*ptrs)
	{
		free(*ptrs);
		ptrs++;
	}
	free(ptrs);
}

static int		do_split(char const *s, char c, char **ptrs)
{
	const char	*starting_point;
	int			cnt;
	int			i;

	i = 0;
	cnt = 0;
	starting_point = s;
	while (*s)
	{
		if (c == *s++)
		{
			if (cnt > 0)
				if (!(*(ptrs + (i++)) = ft_strndup(starting_point, cnt)))
				{
					free_ptrs(ptrs);
					return (0);
				}
			starting_point = s;
			cnt = -1;
		}
		cnt++;
	}
	if (cnt > 0)
		*(ptrs + i) = ft_strndup(starting_point, cnt);
	return (1);
}

char			**ft_split(char const *s, char c)
{
	char		**ptrs;
	int			i;
	
	i = how_many_strs(s, c);
	if (!(ptrs = ft_calloc(i + 1, sizeof(char *))))
		return (NULL);
	if(!do_split(s, c, ptrs))
		return (NULL);
	return (ptrs);
}

// 오류나면 이전에 멀록했던거 다 프리해줘야 함
