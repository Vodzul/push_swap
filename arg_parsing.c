#include "push_swap.h"

void	errorandquit(t_stack **a, char **arr)
{
	if (arr)
		freearr(arr);
	destroy_stack(a);
	ft_putstr_fd("Error\n", 2);
}

void	freearr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		freearr(arr);
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
	
	if (!str)
		return (NULL);
	arr = ft_strdup(str);
	if (!arr)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		if ((arr[i] >= 9 && arr[i] <= 13))
			arr[i] = 32;
		i++;
	}
	newarr = ft_split(arr, ' ');
	free(arr);
	return (newarr);
}

int	checknum(char *str)
{
	int	i;
	
	if (!str)
		return (0);
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

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
	{
		if (!checknum(arr[i]))
		{
			errorandquit(a, arr);
			return (0);
		}
		num = ft_atoi(arr[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			errorandquit(a, arr);
			return (0);
		}
		new = create_node((int)num);
		if (!new)
		{
			errorandquit(a, arr);
			return (0);
		}
		stack_add_back(a, new);
		i++;
	}
	return (1);
}
