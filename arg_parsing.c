#include "push_swap.h"

void	errorandquit(t_stack **a, char **arr, int i)
{
	freearr(arr);
	destroy_stack(a);
	ft_putstr_fd("Error\n", 2);
}

void	freearr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**twoarg(char *str)
{
	char	**newarr;
	char	*arr;
	int	i;
	
	arr = ft_strdup(str);
	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13))
			str[i] = 32;
		i++;
	}
	newarr = ft_split(str, ' ');
	free(arr);
	return (newarr);
}

int	checknum(char *str)
{
	int	i;
	
	i = 0;
	if (str[i] == 43 || str[i] == 45)
	{
		if (!ft_isdigit((str[i + 1])))
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	tostack(char **arr, t_stack **a)
{
	int		i;
	long	num;
	t_stack	*new;

	i = 0;
	while (arr[i])
	{
		if (!checknum(arr[i]))
		{
			errorandquit(a, arr, i);
			return (0);
		}
		num = ft_atoi(arr[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			errorandquit(a, arr, i);
			return (0);
		}
		new = create_node(num);
		if (!new)
		{
			errorandquit(a, arr, i);
			return (0);
		}
		stack_add_back(a, new);
		i++;
	}
	destroy_stack(&new);
}
