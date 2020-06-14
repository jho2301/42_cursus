/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 07:28:59 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/15 07:29:00 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_strcmp(const char *s1, const char *s2);

int	main(int argc, char *argv[])
{
	printf("original	: %d\n", strcmp(argv[1], argv[2]));
	printf("ft_strcmp	: %d\n", ft_strcmp(argv[1], argv[2]));
	return (0);
}
