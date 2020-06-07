/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 21:06:15 by hjeon             #+#    #+#             */
/*   Updated: 2020/04/05 21:58:11 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>

int			get_next_line(int fd, char **line);
int			ft_strchr(const char *s, int c);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_strlen(const char *s);
size_t		ft_strcat(char *dst, char *src, int size);
char		*super_cat(char *dst, char *src, int size);

#endif
