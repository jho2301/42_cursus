/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:15:34 by hjeon             #+#    #+#             */
/*   Updated: 2020/04/04 14:22:47 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool		is_space(char c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (TRUE);
	return (FALSE);
}

static long long	validation(long long result, int i, int is_signed)
{
	if (10 < i)
	{
		if (is_signed)
			return (0);
		return (-1);
	}
	if (result < -2147483648)
		return (0);
	if (result > 2147483647)
		return (-1);
	return (result);
}

int					ft_atoi(const char *nptr)
{
	t_bool			is_signed;
	long long		result;
	int				i;

	is_signed = FALSE;
	result = 0;
	while (is_space(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			is_signed = TRUE;
	i = 0;
	while ('0' <= *(nptr + i) && *(nptr + i) <= '9')
	{
		result *= 10;
		result += *(nptr + i) - '0';
		i++;
	}
	if (is_signed)
		result *= -1;
	result = validation(result, i, is_signed);
	return ((int)result);
}
