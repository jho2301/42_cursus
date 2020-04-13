/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:22:07 by hjeon             #+#    #+#             */
/*   Updated: 2020/02/27 15:26:09 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void ft_putnbr_fd(int n, int fd)
{
	char	*nbr_str;
	int		len;

	nbr_str = ft_itoa(n);
	len = ft_strlen(nbr_str);
	write(fd, nbr_str, len);
	free(nbr_str);
}
