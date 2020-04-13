/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:01:29 by hjeon             #+#    #+#             */
/*   Updated: 2020/02/27 14:49:45 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	get_digit(long long nbr)
{
	int		digit;

	digit = 1;
	if (nbr < 0)
		nbr *= -1;
	while (nbr > 9)
	{
		digit++;
		nbr /= 10;
	}
	return (digit);
}

char		*ft_itoa(int n)
{
	long long	nbr;
	int			digit;
	char		*ptr;
	t_bool		is_signed;

	is_signed = FALSE;
	nbr = (long long)n;
	digit = get_digit(nbr);
	if (!(ptr = ft_calloc(digit++ + 2, sizeof(char))))
		return (NULL);
	if (nbr < 0)
	{
		*ptr = '-';
		nbr *= -1;
		is_signed = TRUE;
	}
	while (--digit)
	{
		if (is_signed)
			*(ptr + digit) = nbr % 10 + '0';
		else
			*(ptr + digit - 1) = nbr % 10 + '0';
		nbr /= 10;
	}
	return (ptr);
}

/*
** #include <unistd.h>
** #include <stdio.h>
**  int main()
**  {
**  	int i;
** 
**  	i = -123;
**  	printf("%s", ft_itoa(i));
**  	return 0;
** }
*/


