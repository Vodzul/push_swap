/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facelik <facelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:35:22 by facelik           #+#    #+#             */
/*   Updated: 2025/12/06 07:23:09 by facelik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_and_quit(t_stack **a, char **arr)
{
	if (arr)
		freearr(arr);
	destroy_stack(a);
}

void	free_arr(char **arr)
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
	ft_putstr_fd("Error\n", 2);
}

static int	is_duplicate(t_stack **a)
{
	t_stack	*temp;
	t_stack	*forward;

	if (!a || !*a)
		return (1);
	temp = *a;
	while (temp)
	{
		forward = temp->next;
		while (forward)
		{
			if (temp->value == forward->value)
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}	
			forward = forward->next;
		}
		temp = temp->next;
	}
	return (1);
}

static int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**newarr;

	a = NULL;
	b = NULL;
	if (argc >= 2)
	{
		newarr = arg_parsing(argv + 1);
		if (!newarr)
			return (0);
		if (!to_stack(newarr, &a))
			return (0);
	}
	else
		return (0);
	if (!is_duplicate(&a))
		return (destroy_stack(&a), 0);
	if (is_sorted(a))
		return (destroy_stack(&a), 0);
	positive_stack(a);
	sort_stack(&a, &b);
	destroy_stack(&a);
	destroy_stack(&b);
}
