/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:15:34 by hjeon             #+#    #+#             */
/*   Updated: 2020/02/26 14:41:19 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static t_bool	is_space(char c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (TRUE);
	return (FALSE);
}

static int		get_number_with_digit(char c, int digit)
{
	int		result;
	int		converted_c;

	result = 1;
	while (--digit)
		result *= 10;
	converted_c = c - '0';
	return (result * converted_c);
}

int				ft_atoi(const char *nptr)
{
	t_bool	is_signed;
	size_t	i;
	int		result;
	int		digit;

	i = 0;
	result = 0;
	digit = 0;
	is_signed = FALSE;
	while (is_space(*nptr))
		nptr++;
	if ( *nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			is_signed = TRUE;
	while ('0' <= *(nptr + i) && *(nptr + (i++)) <= '9')
		digit++;
	while ('0' <= *nptr && *nptr <= '9')
		result += get_number_with_digit(*nptr++, digit--);
	if (is_signed)
		result *= -1;
	return (result);
}

/*
** 
** #include <stdio.h>
** int main()
** {
** 	int mine = ft_atoi("1234");
** 	int real = atoi("1234");
** 
** 	printf("mine : %d\n", mine);
** 	printf("real : %d\n", real);
** 	return 0;
** }
** 
** 
*/
