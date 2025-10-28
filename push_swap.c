/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facelik <facelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:35:22 by facelik           #+#    #+#             */
/*   Updated: 2025/10/20 20:37:43 by facelik          ###   ########.fr       */
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
	if (argc == 2)
		twoarg(argv[2]);
	else if (argc > 2)
		multiplearg(argv);
	else
		ft_putstr_fd("Error\n", 1);
}
