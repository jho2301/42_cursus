#include <stdio.h>
#include <string.h>

int ft_strcmp(const char *s1, const char *s2);

int	main(int argc, char *argv[])
{
	printf("original	: %d\n", strcmp(argv[1], argv[2]));
	printf("ft_strcmp	: %d\n", ft_strcmp(argv[1], argv[2]));
	return (0);
}
