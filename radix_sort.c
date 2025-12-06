/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facelik <facelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:35:30 by facelik           #+#    #+#             */
/*   Updated: 2025/12/06 07:17:34 by facelik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **a, t_stack **b, int count)
{
	int	turn_count;
	int	i;

	i = 0;
	turn_count = stack_size(*a);
	while (i < turn_count)
	{
		if ((((*a)->value >> count) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		i++;
	}
	while (*b)
		pa(a, b);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;
	int	count;
	int	max_index;
	int	max_bit;

	max_bit = 0;
	count = 0;
	size = stack_size(*a);
	max_index = size - 1;
	while (max_index >> max_bit != 0)
		max_bit++;
	if (size > 5)
	{
		while (count < max_bit)
		{
			radix_sort(a, b, count);
			count++;
		}
	}
	else
		small_sort(a, b);
}
