/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeon <hjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:50:00 by hjeon             #+#    #+#             */
/*   Updated: 2020/06/04 20:49:20 by hjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	LIBFT v1.0.1
*/

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define TRUE	1
# define FALSE	0

typedef int		t_bool;
typedef struct	s_list
{
	void *content;
	struct s_list *next;
}				t_list;


/*
** libc function
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char	*big, const char *little, size_t len);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isprint(int c);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isascii(int c);
char	*ft_strdup(const char *s);
int		ft_tolower(int c);
int		ft_toupper(int c);

/*
** additional function
*/

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void 	ft_putnbr_fd(int n, int fd);

/*
** bonus function
*/

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new_lst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new_lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*
** my own bonus function
*/

void	ft_putstrn_fd_bonus(const char *s, int fd, int n);
int		ft_strchri_bonus(const char *s, int c);
char	*ft_lltoa_bonus(long long nbr);
char	*ft_realloc_bonus(char *ptr, size_t size, int nmemb);
// char	*ft_super_cat(char *dst, char *src);
/*
** get_next_line_bonus : read line and give malloced string
** return : 1 = read some, 0 = read nothing, -1 = error occured
*/
int		get_next_line(int fd, char **line);
void	check_argc(int argc);
int		check_screenshot_option(int argc, char *option_str);




#endif
