/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:45:51 by hjeon             #+#    #+#             */
/*   Updated: 2020/04/08 15:02:40 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flagconv	*init_flag_spec(void)
{
	t_flagconv		*flag_spec;

	flag_spec = ft_calloc(1, sizeof(t_flagconv));
	if (!flag_spec)
		return (NULL);
	flag_spec->conversion = 0;
	flag_spec->left = 0;
	flag_spec->prec = -2;
	flag_spec->show_sign = 0;
	flag_spec->space = 0;
	flag_spec->sharp = 0;
	flag_spec->pd0 = 0;
	flag_spec->wid = 0;
	flag_spec->is_c_zero = 0;
	return (flag_spec);
}

void		get_width_from_arg_ptr(va_list arg_ptr, t_flagconv *fc)
{
	int wid;

	wid = va_arg(arg_ptr, int);
	if (wid < 0)
	{
		fc->wid = wid * (-1);
		fc->left = 1;
	}
	else
		fc->wid = wid;
	return ;
}

char		*do_conversion(va_list arg_ptr, t_flagconv *fc,
						const char *str, int written_len)
{
	int		wid;

	wid = 0;
	if (fc->wid == -1)
		get_width_from_arg_ptr(arg_ptr, fc);
	if (fc->prec == -1)
		fc->prec = va_arg(arg_ptr, int);
	if (fc->conversion == '%')
		return (conversion_percent(fc));
	if (fc->conversion == 'c')
		return (conversion_c(arg_ptr, fc));
	else if (fc->conversion == 's')
		return (conversion_s(arg_ptr, fc, str, written_len));
	else if (fc->conversion == 'p')
		return (conversion_p(arg_ptr, fc));
	else if (fc->conversion == 'd' || fc->conversion == 'i')
		return (conversion_di(arg_ptr, fc));
	else if (fc->conversion == 'u')
		return (conversion_u(arg_ptr, fc));
	else if (fc->conversion == 'x')
		return (conversion_small_x(arg_ptr, fc));
	else if (fc->conversion == 'X')
		return (conversion_big_x(arg_ptr, fc));
	else
		return (ft_strdup("%"));
}

int			process_conversion(const char *str, int *idx,
								va_list arg_ptr, int w_len)
{
	int			written_len;
	char		*converted_str;
	t_flagconv	*flag_spec;

	written_len = 0;
	flag_spec = get_flag_spec(str + *idx, idx);
	if (!flag_spec)
		return (-1);
	converted_str = do_conversion(arg_ptr, flag_spec, str + *idx, w_len);
	if (!converted_str)
	{
		free(flag_spec);
		return (-1);
	}
	written_len = ft_strlen(converted_str);
	written_len = flag_spec->is_c_zero ? written_len + 1 : written_len;
	if (flag_spec->is_c_zero && flag_spec->left)
		write(1, "\x00", 1);
	ft_putstr_fd(converted_str, STDOUT_FILENO);
	if (flag_spec->is_c_zero && !flag_spec->left)
		write(1, "\x00", 1);
	free(converted_str);
	free(flag_spec);
	return (written_len);
}
