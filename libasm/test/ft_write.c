/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 07:29:10 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/15 07:36:31 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

ssize_t	ft_write(int fd, const void *buf, size_t count);

int		main(int argc, char *argv[])
{
	int	fd1;
	int	fd2;
	int	len;

	fd1 = open("./original.txt", O_WRONLY | O_CREAT);
	fd2 = open("./ft_write.txt", O_WRONLY | O_CREAT);
	len = strlen(argv[1]);
	printf("original	: %ld\n", write(fd1, argv[1], len));
	printf("ft_write	: %ld\n", ft_write(fd2, argv[1], len));
	return (0);
}
