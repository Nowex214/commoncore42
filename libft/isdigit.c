
#include <stdio.h>

int	ft_isdigit(int i)
{
	if (i >= '0' && i <= '9')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("output: %d", ft_isdigit(av[1][0]));
		return(0);
	}
}
