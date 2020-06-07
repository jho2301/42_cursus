/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:13:07 by hjeon             #+#    #+#             */
/*   Updated: 2020/04/08 14:00:45 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		get_len(long long nbr)
{
	int		len;

	if (nbr < 0)
		nbr *= -1;
	len = 1;
	while (nbr /= 10)
		len++;
	return (len);
}

int		get_result_len(long long num)
{
	int		result;

	result = 0;
	while (num >= 16)
	{
		result++;
		num /= 16;
	}
	return (result + 1);
}

char	*lltoa_hex(long long num, int *total_len)
{
	int		len;
	int		mod;
	char	*result;

	len = get_result_len(num);
	*total_len = len;
	if (!(result = ft_calloc((len + 1), sizeof(char))))
		return (NULL);
	result[len--] = '\0';
	while (num >= 16)
	{
		mod = num % 16;
		if (mod >= 10)
			result[len--] = mod - 10 + 'a';
		else
			result[len--] = mod + '0';
		num /= 16;
	}
	result[len] = num + '0';
	if (num >= 10)
		result[len] = num - 10 + 'a';
	return (result);
}

char	*lltoa_hex_big(long long num, int *total_len)
{
	int		len;
	int		mod;
	char	*result;

	len = get_result_len(num);
	*total_len = len;
	if (!(result = ft_calloc((len + 1), sizeof(char))))
		return (NULL);
	result[len--] = '\0';
	while (num >= 16)
	{
		mod = num % 16;
		if (mod >= 10)
			result[len--] = mod - 10 + 'A';
		else
			result[len--] = mod + '0';
		num /= 16;
	}
	result[len] = num + '0';
	if (num >= 10)
		result[len] = num - 10 + 'A';
	return (result);
}
