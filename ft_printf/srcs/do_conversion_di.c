/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_conversion_di.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:14:52 by hjeon             #+#    #+#             */
/*   Updated: 2020/04/08 13:43:09 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	mark_sign(char *str, int *len, t_flagconv *fc)
{
	ft_strlcat(str, "-", 2);
	(*len)++;
	(fc->prec)++;
}

char	*get_conv_di_str(t_flagconv *fc, long long nbr, int is_signed, int len)
{
	char		*str;
	char		*s;

	nbr = (nbr < 0 && fc->prec > len) ? (nbr * -1) : nbr;
	s = (!nbr && fc->prec == 0) ? ft_strdup("") : ft_lltoa_bonus(nbr);
	if (!s)
		return (NULL);
	if (fc->prec > len)
	{
		if (!(str = ft_calloc((fc->prec + 2), sizeof(char))))
			return (NULL);
		if (is_signed)
			mark_sign(str, &len, fc);
		str = get_converted_string_right_zero(str, s, len, fc->prec);
		free(s);
		s = str;
	}
	len = (fc->wid) > (int)ft_strlen(s) ? fc->wid : (int)ft_strlen(s);
	if (!(str = ft_calloc((len + 2), sizeof(char))))
		return (NULL);
	str = get_converted_string(str, s, len, fc);
	free(s);
	return (str);
}

char	*get_signed_0_pad_str(t_flagconv *fc, long long nbr, int len)
{
	char		*str;
	char		*s;

	if (!(s = ft_lltoa_bonus(nbr * -1)))
		return (NULL);
	if (*s == '0' && fc->prec == 0)
	{
		free(s);
		s = ft_strdup("");
	}
	len = ((fc->wid) > len) ? fc->wid : len;
	if (!(str = ft_calloc((len + 2), sizeof(char))))
		return (NULL);
	ft_strlcat(str, "-", len + 2);
	if (fc->left && fc->pd0 && !fc->left)
		str = get_converted_string_left_zero(str, s, ft_strlen(s) + 1, len);
	else if (!fc->left && fc->pd0 && !fc->left)
		str = get_converted_string_right_zero(str, s, ft_strlen(s) + 1, len);
	else if (fc->left)
		str = get_converted_string_left_space(str, s, ft_strlen(s) + 1, len);
	else
		str = get_converted_string_right_space(str, s, ft_strlen(s) + 1, len);
	free(s);
	return (str);
}

char	*get_signed_0_pad_str_small_prec(t_flagconv *fc, long long nbr, int len)
{
	char		*str;
	char		*s;
	int			is_signed;

	is_signed = nbr < 0;
	nbr = (fc->prec > len && is_signed) ? nbr * -1 : nbr;
	if (!(s = (!nbr && fc->prec == 0) ? ft_strdup("") : ft_lltoa_bonus(nbr)))
		return (NULL);
	if (fc->prec > len)
	{
		if (!(str = ft_calloc((fc->prec + 2), sizeof(char))))
			return (NULL);
		if (is_signed)
			mark_sign(str, &len, fc);
		str = get_converted_string_right_zero(str, s, len, fc->prec);
		free(s);
		s = str;
	}
	len = (fc->wid) > (int)ft_strlen(s) ? fc->wid : (int)ft_strlen(s);
	if (!(str = ft_calloc((len + 2), sizeof(char))))
		return (NULL);
	fc->pd0 = (fc->pd0 && fc->prec < fc->wid && fc->prec != -2) ? 0 : fc->pd0;
	str = get_converted_string(str, s, len, fc);
	free(s);
	return (str);
}

char	*conversion_di(va_list arg_ptr, t_flagconv *fc)
{
	long long	nbr;
	int			is_signed;
	char		*str;

	nbr = (long long)va_arg(arg_ptr, int);
	is_signed = (nbr < 0) ? 1 : 0;
	if (is_signed && fc->pd0 && (fc->prec >= fc->wid ||
							fc->prec == -2) && fc->wid > get_len(nbr))
		str = get_signed_0_pad_str(fc, nbr, get_len(nbr));
	else if (fc->pd0 && fc->prec < fc->wid)
		str = get_signed_0_pad_str_small_prec(fc, nbr, get_len(nbr));
	else
		str = get_conv_di_str(fc, nbr, is_signed, get_len(nbr));
	return (str);
}
