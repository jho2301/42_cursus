/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 21:07:59 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/14 22:26:42 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_strlen(const char *s);

int main(int argc, char *argv[])
{
    int ret1;
    int ret2;

	ret2 = strlen(argv[1]);
	ret1 = ft_strlen(argv[1]);
	printf("original	: %d\n", ret2);
	printf("ft_strlen	: %d\n", ret1);
	return (0);
}
