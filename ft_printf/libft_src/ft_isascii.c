/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:50:48 by hjeon             #+#    #+#             */
/*   Updated: 2020/04/04 00:43:41 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** checks whether c is a 7-bit unsigned char value
** that fits into the ASCII character set.
*/

int		ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (TRUE);
	else
		return (FALSE);
}
