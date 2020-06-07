/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:21:15 by hjeon             #+#    #+#             */
/*   Updated: 2020/04/08 13:43:04 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		arg_check(const char *str)
{
	if (!str)
		return (-1);
	return (1);
}

void	init_do_print_variable(int *i, int *write_len, int *is_null)
{
	*i = 0;
	*write_len = 0;
	*is_null = 0;
}

int		do_printf(const char *str, va_list arg_ptr)
{
	int		i;
	int		temp;
	int		write_len;
	int		is_null;

	if (arg_check(str) == -1)
		return (-1);
	init_do_print_variable(&i, &write_len, &is_null);
	while (1)
	{
		if ((temp = ft_strchri_bonus(str + i, '%')) == -1)
		{
			temp = ft_strchri_bonus(str + i, '\0');
			is_null = 1;
		}
		ft_putstrn_fd_bonus(str + i, 1, temp);
		i += temp;
		write_len += temp;
		if (is_null)
			return (write_len);
		if ((temp = process_conversion(str, &i, arg_ptr, write_len)) == -1)
			return (-1);
		write_len += temp;
	}
}

int		ft_printf(const char *str, ...)
{
	va_list		arg_ptr;
	int			done;

	done = 0;
	va_start(arg_ptr, str);
	done = do_printf(str, arg_ptr);
	va_end(arg_ptr);
	return (done);
}
