

#include <stdio.h>

int	ft_isalpha(int i)
{
	if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
		return(1);
	return(0);
}

int	main(int ac,char **av)
{
	if (ac == 2)
		printf ("output: %d", ft_isalpha(av[1][0]));
	return(0);
}
