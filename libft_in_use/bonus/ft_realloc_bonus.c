/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:25:39 by hjeon             #+#    #+#             */
/*   Updated: 2020/03/03 21:59:23 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_realloc_bonus(char *ptr, size_t size, int nmemb)
{
	free(ptr);
	ptr = ft_calloc(nmemb, size);
	if (!ptr)
		return (NULL);
	return (ptr);
}
