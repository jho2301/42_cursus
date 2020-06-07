/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:46:04 by hjeon             #+#    #+#             */
/*   Updated: 2020/04/08 14:51:31 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft_src/libft.h"

/*
**	left -> - : left-align
**	space -> prefix ' '
**	sharp -> # for x, X
**	pd0 -> fiil with 0
**	wid -> -1 : asterisk, 0 : none specified.
**	prec-> -1 : asterisk, -2 : none specified.
*/

typedef struct	s_flagconv
{
	int		left;
	int		show_sign;
	int		space;
	int		sharp;
	int		pd0;
	int		wid;
	int		prec;
	char	conversion;
	char	is_c_zero;
}				t_flagconv;

int				ft_printf(const char *str, ...);
int				process_conversion(const char *str, int *idx,
								va_list arg_ptr, int written_len);
char			*lltoa_hex(long long num, int *total_len);
char			*lltoa_hex_big(long long num, int *total_len);
char			*conversion_c(va_list arg_ptr, t_flagconv *fc);
char			*conversion_s(va_list arg_ptr, t_flagconv *fc,
							const char *origin_str, int written_len);
char			*conversion_u(va_list arg_ptr, t_flagconv *fc);
char			*conversion_di(va_list arg_ptr, t_flagconv *fc);
char			*conversion_p(va_list arg_ptr, t_flagconv *fc);
char			*conversion_small_x(va_list arg_ptr, t_flagconv *fc);
char			*conversion_big_x(va_list arg_ptr, t_flagconv *fc);
char			*conversion_percent(t_flagconv *fc);
int				get_len(long long nbr);
char			*get_converted_string(char *ptr, char *src,
									int total_len, t_flagconv *fc);
char			*get_converted_string_left_space(char *str, char *src,
												int src_len, int len);
char			*get_converted_string_right_space(char *str, char *src,
												int src_len, int len);
char			*get_converted_string_left_zero(char *str, char *src,
												int src_len, int len);
char			*get_converted_string_right_zero(char *str, char *src,
												int src_len, int len);
t_flagconv		*get_flag_spec(const char *str, int *idx);
t_flagconv		*init_flag_spec(void);

#endif
