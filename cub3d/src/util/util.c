#include <unistd.h>
# include <unistd.h>
# include "libft.h"

void	exit_with_errmsg(char *errmsg)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(errmsg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(1);
}

void	check_argc(int argc)
{
	if (argc == 1)
		exit_with_errmsg("please enter a argument.");
	else if (3 < argc)
		exit_with_errmsg("please enter 1 or 2 argument.");
	else
		return ;
}

int		check_screenshot_option(int argc, char *option_str)
{
	if (argc == 3 && !ft_strncmp("--save" , option_str, 6))
		return (TRUE);
	else
		return (FALSE);
}

size_t	ft_stcat(char *dst, char *src, int size)
{
	int		i;

	while (*dst)
		dst++;
	i = 0;
	while (*(src + i) && i < size)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = 0;
	return (0);
}

char	*supreme_cat(char *dst, char *src, int size)
{
	char	*result;
	int		dst_len;
	int		src_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	result = ft_calloc((dst_len + src_len + 1), sizeof(char));
	*result = 0;
	if (!result)
		return (NULL);
	ft_stcat(result, dst, dst_len);
	ft_stcat(result, src, size);
	free(dst);
	// free(src);
	return (result);
}
