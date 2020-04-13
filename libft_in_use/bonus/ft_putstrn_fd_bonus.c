/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn_fd_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 22:19:41 by hjeon             #+#    #+#             */
/*   Updated: 2020/03/02 23:40:51 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putstrn_fd_bonus(const char *s, int fd, int n)
{
	int	s_len;

	s_len = ft_strlen(s);
	if (n <= s_len)
		write(fd, s, n);
	else
		write(fd, s, s_len);
}
