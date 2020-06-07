/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_converted_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:11:19 by hjeon             #+#    #+#             */
/*   Updated: 2020/04/08 13:24:35 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*get_converted_string_left_zero(char *str, char *src,
										int src_len, int len)
{
	int i;

	i = 0;
	ft_strlcat(str, src, len + 1);
	while (i++ < len - src_len)
		ft_strlcat(str, "0", len + 1);
	return (str);
}

char	*get_converted_string_right_zero(char *str, char *src,
											int src_len, int len)
{
	int i;

	i = 0;
	while (i++ < len - src_len)
		ft_strlcat(str, "0", len + 1);
	ft_strlcat(str, src, len + 1);
	return (str);
}

char	*get_converted_string_left_space(char *str, char *src,
											int src_len, int len)
{
	int i;

	i = 0;
	ft_strlcat(str, src, len + 1);
	while (i++ < len - src_len)
		ft_strlcat(str, " ", len + 1);
	return (str);
}

char	*get_converted_string_right_space(char *str, char *src,
											int src_len, int len)
{
	int i;

	i = 0;
	while (i++ < len - src_len)
		ft_strlcat(str, " ", len + 1);
	ft_strlcat(str, src, len + 1);
	return (str);
}

char	*get_converted_string(char *ptr, char *src,
								int total_len, t_flagconv *fc)
{
	int		src_len;

	src_len = ft_strlen(src);
	if (fc->left && fc->pd0)
		ptr = get_converted_string_left_zero(ptr, src, src_len, total_len);
	else if (!fc->left && fc->pd0)
		ptr = get_converted_string_right_zero(ptr, src, src_len, total_len);
	else if (fc->left)
		ptr = get_converted_string_left_space(ptr, src, src_len, total_len);
	else
		ptr = get_converted_string_right_space(ptr, src, src_len, total_len);
	return (ptr);
}
