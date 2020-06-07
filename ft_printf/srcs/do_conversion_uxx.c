/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_conversion_uxx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:20:38 by hjeon             #+#    #+#             */
/*   Updated: 2020/04/08 14:06:49 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*conversion_u(va_list arg_ptr, t_flagconv *fc)
{
	char			*str;
	char			*src;
	unsigned int	len;

	fc->pd0 = (0 <= fc->prec) ? 0 : fc->pd0;
	len = va_arg(arg_ptr, unsigned int);
	src = (!len && !fc->prec) ? ft_strdup("") : ft_lltoa_bonus(len);
	if (!(src))
		return (NULL);
	if (fc->prec > (int)ft_strlen(src))
	{
		if (!(str = ft_calloc((fc->prec + 1), sizeof(char))))
			return (NULL);
		str = get_converted_string_right_zero(str, src,
												ft_strlen(src), fc->prec);
		free(src);
		src = str;
	}
	len = (fc->wid) > (int)ft_strlen(src) ? fc->wid : (int)ft_strlen(src);
	if (!(str = ft_calloc((len + 1), sizeof(char))))
		return (NULL);
	str = get_converted_string(str, src, len, fc);
	free(src);
	return (str);
}

void	init_conv_x(va_list arg_ptr, t_flagconv *fc,
					int *str_len, unsigned int *t_len)
{
	fc->pd0 = 0 <= fc->prec ? 0 : fc->pd0;
	*t_len = (long long)va_arg(arg_ptr, unsigned int);
	*str_len = 0;
	return ;
}

char	*conversion_small_x(va_list arg_ptr, t_flagconv *fc)
{
	char			*s;
	char			*str;
	int				str_len;
	unsigned int	t_len;

	init_conv_x(arg_ptr, fc, &str_len, &t_len);
	s = (!t_len && !fc->prec) ? ft_strdup("") : lltoa_hex(t_len, &str_len);
	if (!s)
		return (NULL);
	if (fc->prec > str_len)
	{
		if (!(str = ft_calloc((fc->prec + 1), sizeof(char))))
			return (NULL);
		str = get_converted_string_right_zero(str, s, str_len, fc->prec);
		str_len = fc->prec;
		free(s);
		s = str;
	}
	t_len = (fc->wid) > str_len ? fc->wid : str_len;
	if (!(str = ft_calloc((t_len + 1), sizeof(char))))
		return (NULL);
	str = get_converted_string(str, s, t_len, fc);
	free(s);
	return (str);
}

char	*conversion_big_x(va_list arg_ptr, t_flagconv *fc)
{
	char			*s;
	char			*str;
	int				str_len;
	unsigned int	t_len;

	init_conv_x(arg_ptr, fc, &str_len, &t_len);
	s = (!t_len && !fc->prec) ? ft_strdup("") :
								lltoa_hex_big((long long)t_len, &str_len);
	if (!s)
		return (NULL);
	if (fc->prec > str_len)
	{
		if (!(str = ft_calloc((fc->prec + 1), sizeof(char))))
			return (NULL);
		str = get_converted_string_right_zero(str, s, str_len, fc->prec);
		str_len = fc->prec;
		free(s);
		s = str;
	}
	t_len = (fc->wid) > str_len ? fc->wid : str_len;
	if (!(str = ft_calloc((t_len + 1), sizeof(char))))
		return (NULL);
	str = get_converted_string(str, s, t_len, fc);
	free(s);
	return (str);
}
