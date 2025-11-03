/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facelik <facelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:35:22 by facelik           #+#    #+#             */
/*   Updated: 2025/10/29 20:22:12 by facelik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issorted(t_stack *a)
{
	while (a)
	{
		if (a > a->next)
			return (0);
		a = a->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a = NULL;
	t_stack *b = NULL;
	char	**arr;
	
	if (argc == 2)
	{
		arr = twoarg(argv[1]);
		if (!tostack(arr, &a))
			return (freearr(arr), 0);
		freearr(arr);
	}
	else if (argc > 2)
		if (!tostack((argv + 1), &a))
			return (0);
	else
		return (0);
	if (issorted(a))
		return (destroy_stack(&a), 0);
	positive_stack(a);
	sort_stack(&a, &b);
	destroy_stack(&a);
	destroy_stack(&b);
}
