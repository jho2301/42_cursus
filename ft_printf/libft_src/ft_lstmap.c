/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:56:34 by hjeon             #+#    #+#             */
/*   Updated: 2020/04/04 00:43:41 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new_list;
	t_list		*temp_list;
	t_list		*temp_list2;

	new_list = ft_calloc(1, sizeof(t_list));
	if (!new_list)
		return (NULL);
	temp_list = new_list;
	while (lst->next)
	{
		temp_list->content = f(lst->content);
		temp_list2 = ft_calloc(1, sizeof(t_list));
		if (!new_list)
			ft_lstclear(&lst, del);
		temp_list->next = temp_list2;
		temp_list = temp_list->next;
		lst = lst->next;
	}
	temp_list->content = f(lst->content);
	temp_list->next = NULL;
	return (new_list);
}
