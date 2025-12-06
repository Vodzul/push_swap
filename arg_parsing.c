/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facelik <facelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:14:27 by facelik           #+#    #+#             */
/*   Updated: 2025/12/06 07:26:00 by facelik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	result;

	sign = 1;
	i = 0;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * sign);
}

static char	**join_split(char **argv)
{
	int		i;
	char	*temp;
	char	*tmp;
	char	**ret;

	i = -1;
	temp = NULL;
	tmp = "";
	while (argv[++i])
	{
		temp = ft_strjoin(argv[i], " ");
		tmp = ft_strjoin(ft_strdup(tmp), temp);
	}
	ret = ft_split(tmp, 32);
	return (ret);
}

static int	checknum(char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (!argv[i])
		return (0);
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (!ft_isdigit(argv[i][j]))
			return (0);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**arg_parsing(char **argv)
{
	char	**newarr;
	int		i;
	int		j;

	if (!argv || argv[0][0] == '\0')
		return (ft_putstr_fd("Error\n", 2), NULL);
	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] >= 9 && argv[i][j] <= 13))
				argv[i][j] = 32;
			j++;
		}
		i++;
	}
	i = -1;
	newarr = join_split(argv);
	if (!checknum(newarr))
		return (freearr(newarr), NULL);
	return (newarr);
}

int	to_stack(char **arr, t_stack **a)
{
	int		i;
	long	num;
	t_stack	*new;

	i = 0;
	while (arr[i])
	{
		num = ft_atol(arr[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			errorandquit(a, arr);
			return (ft_putstr_fd("Error\n", 2), 0);
		}
		new = create_node((int)num);
		if (!new)
		{
			errorandquit(a, arr);
			return (ft_putstr_fd("Error\n", 2), 0);
		}
		stack_add_back(a, new);
		i++;
	}
	return (1);
}
