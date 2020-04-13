/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:57:43 by hjeon             #+#    #+#             */
/*   Updated: 2020/02/27 18:56:55 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*temp;

	temp = lst[0];
	if (!temp)
	{
		lst[0] = new;
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}
