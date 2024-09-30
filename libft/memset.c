
#include <stdio.h>
#include <string.h>

void	*ft_memset(void *ptr, int value, size_t len)
{
	size_t	i = 0;

	if (!ptr)
		return (NULL);
	while (i < len)
	{
		*(unsigned char *)(ptr + i) = (unsigned char) value;
		i++;
	}
	return (ptr);
}

int	main(void)
{
	char str[50] = "nique ta mère simon";

	printf("output: %s\n",str);
	ft_memset(str, 'A', 5);
	printf("output: %s\n",str);
	return (0);
}
