/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn_fd_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 22:19:41 by hjeon             #+#    #+#             */
/*   Updated: 2020/04/08 12:24:27 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrn_fd_bonus(const char *s, int fd, int n)
{
	int	s_len;

	s_len = ft_strlen(s);
	if (n <= s_len)
		write(fd, s, n);
	else
		write(fd, s, s_len);
}
