#include "push_swap.h"

char	**twoarg(char *str)
{
	char	**newarr;
	int	i;
	
	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13))
			str[i] = 32;
		i++;
	}
	newarr = ft_split(str, ' ');
	return (newarr);
}

int	checknum(char *str)
{
	int	i;
	
	i = 0;
	if (str[i] == 43 || str[i] == 45)
	{
		if (ft_isdigit(!(str[i + 1])))
			return (0);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
