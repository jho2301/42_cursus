/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_conversion_csp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:20:38 by hjeon             #+#    #+#             */
/*   Updated: 2020/04/08 15:01:05 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*conversion_percent(t_flagconv *fc)
{
	char		*str;
	int			len;

	if (fc->left)
		fc->pd0 = 0;
	if (fc->pd0)
	{
		len = (fc->wid) > 1 ? fc->wid : 1;
		if (!(str = ft_calloc((len + 2), sizeof(char))))
			return (NULL);
		str = get_converted_string(str, "%", len, fc);
		return (str);
	}
	len = (fc->wid) > 1 ? fc->wid : 1;
	if (!(str = ft_calloc((len + 2), sizeof(char))))
		return (NULL);
	str = get_converted_string(str, "%", len, fc);
	return (str);
}

char	*conversion_c(va_list arg_ptr, t_flagconv *fc)
{
	char	*str;
	char	c[2];
	int		len;
	int		chr;

	len = (fc->wid) > 1 ? fc->wid : 1;
	str = ft_calloc((len + 1), sizeof(char));
	chr = va_arg(arg_ptr, int);
	if (!chr)
	{
		fc->is_c_zero = 1;
		str = get_converted_string(str, "", len - 1, fc);
		return (str);
	}
	c[0] = chr;
	c[1] = 0;
	str = get_converted_string(str, c, len, fc);
	return (str);
}

char	*conversion_s(va_list arg_ptr, t_flagconv *fc,
						const char *origin_str, int written_len)
{
	char	*str;
	char	*src;
	int		len;

	if (!(src = va_arg(arg_ptr, char *)))
	{
		if (((!fc->wid || !fc->prec) && (written_len == 0 &&
				(*origin_str == '\n' && *(origin_str + 1) == '\0'))))
			src = "";
		else
			src = "(null)";
	}
	len = (fc->wid) > (int)ft_strlen(src) ? fc->wid : (int)ft_strlen(src);
	if (!(str = ft_calloc((len + 1), sizeof(char))))
		return (NULL);
	if (fc->prec >= 0)
		if (!(src = ft_substr(src, 0, fc->prec)))
			return (NULL);
	len = fc->wid > (int)ft_strlen(src) ? fc->wid : (int)ft_strlen(src);
	str = get_converted_string(str, src, len, fc);
	if (fc->prec >= 0)
		free(src);
	return (str);
}

char	*conversion_p(va_list arg_ptr, t_flagconv *fc)
{
	char		*str;
	char		*ptr_str;
	int			len;

	if (!(str = lltoa_hex(va_arg(arg_ptr, unsigned long long), &len)))
		return (NULL);
	if (*str == '0' && 0 <= fc->prec)
		ptr_str = ft_strdup("0x");
	else if (*str == '0')
		ptr_str = ft_strdup("0x0");
	else
	{
		ptr_str = ft_strdup("0x");
		ptr_str = ft_super_cat(ptr_str, str);
	}
	len = fc->wid > (int)ft_strlen(ptr_str) ? fc->wid : ft_strlen(ptr_str);
	free(str);
	if (!(str = ft_calloc((len + 3), sizeof(char))))
		return (NULL);
	str = get_converted_string(str, ptr_str, len, fc);
	free(ptr_str);
	return (str);
}
