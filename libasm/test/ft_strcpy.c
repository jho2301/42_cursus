#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *dest, const char *src);

int		main(int argc, char *argv[])
{
	char	dest1[1024];
	char	dest2[1024];
	const char	*src = argv[1];
	strcpy(dest1, src);
	ft_strcpy(dest2, src);
	printf("original	: %s\n", dest1);
	printf("ft_strcpy	: %s\n", dest2);
}
