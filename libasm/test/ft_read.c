/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 07:28:55 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/15 07:28:56 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

ssize_t	ft_read(int fd, void *buf, size_t count);

int		main(int argc, char *argv[])
{
	int		fd1;
	int		fd2;
	char	line1[1024];
	char	line2[1024];

	fd1 = open("./original.txt", O_RDONLY);
	fd2 = open("./ft_write.txt", O_RDONLY);
	printf("original	: %ld\n", read(fd1, line1, 1024));
	printf("original	: %s\n", line1);
	printf("ft_read		: %ld\n", ft_read(fd2, line2, 1024));
	printf("ft_read		: %s\n", line2);
	return (0);
}
