/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag_spec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:09:11 by hjeon             #+#    #+#             */
/*   Updated: 2020/04/08 13:42:50 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		inspect_flags(const char *str, int *i, t_flagconv *flag_spec)
{
	while (*(str + *i) == '-' || *(str + *i) == '+' || *(str + *i) == ' '
		|| *(str + *i) == '#' || *(str + *i) == '0')
	{
		if (*(str + *i) == '-')
			flag_spec->left = 1;
		else if (*(str + *i) == '+')
			flag_spec->show_sign = 1;
		else if (*(str + *i) == ' ')
			flag_spec->space = 1;
		else if (*(str + *i) == '#')
			flag_spec->sharp = 1;
		else if (*(str + *i) == '0')
			flag_spec->pd0 = 1;
		(*i)++;
	}
}

int			inspect_wid(const char *str, int *i, t_flagconv *flag_spec)
{
	if ((ft_isdigit(*(str + *i)) || *(str + *i) == '*'))
	{
		if (*(str + (*i)) == '*')
			flag_spec->wid = -1;
		else
			flag_spec->wid = ft_atoi(str + *i);
	}
	while ((ft_isdigit(*(str + *i)) || *(str + *i) == '*') &&
			*(str + *i) != '%')
		if (*(str + ++(*i)) == '*')
			return (-1);
	return (0);
}

int			inspect_prec(const char *str, int *i, t_flagconv *flag_spec)
{
	if (*(str + *i) == '.')
	{
		flag_spec->prec = 0;
		if (ft_isdigit(*(str + ++(*i))) || *(str + *i) == '*')
		{
			if (*(str + *i) == '*')
				flag_spec->prec = -1;
			else
				flag_spec->prec = ft_atoi(str + *i);
		}
		while (ft_isdigit(*(str + *i)) || *(str + *i) == '*')
			if (*(str + (++(*i))) == '*')
				return (-1);
		return (0);
	}
	return (0);
}

t_flagconv	*get_flag_spec(const char *str, int *idx)
{
	int				i;
	t_flagconv		*flag_spec;

	i = 1;
	if (!(flag_spec = init_flag_spec()))
		return (NULL);
	inspect_flags(str, &i, flag_spec);
	if (inspect_wid(str, &i, flag_spec) == -1)
		return (flag_spec);
	if (inspect_prec(str, &i, flag_spec) == -1)
		return (flag_spec);
	if (!*(str + i))
		return (NULL);
	flag_spec->conversion = *(str + i++);
	*idx += i;
	return (flag_spec);
}
