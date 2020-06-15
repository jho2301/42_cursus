/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 07:29:04 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/15 09:25:42 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(const char *s);

int		main(int argc, char *argv[])
{
	char 	*dest1;
	char	*dest2;

	dest1 = strdup(argv[1]);
	printf("original	: %s\n", dest1);
	free(dest1);
	dest2 = ft_strdup(argv[1]);
	printf("ft_strdup	: %s\n", dest2);
	free(dest2);
}
