
#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && first < third && second < third)
		sa(a);
	else if (first > second && first > third && second < third)
		ra(a);
	else if (first > second && first > third && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first < second && first < third && second > third)
	{
		rra(a);
		sa(a);
	}
	else if (first < second && first > third && second > third)
		rra(a);
}

int	find_min(t_stack *a)
{
	int		min;
	int		j;
	int		i;
	t_stack	*temp;

	min = a->value;
	temp = a;
	i = 0;
	j = 0;
	while (temp)
	{
		if (temp->value < min)
		{
			min = temp->value;
			j = i;
		}
		i++;
		temp = temp->next;
	}
	return (j);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	min;
	int	size;

	while (stack_size(*a) > 3)
	{
		size = stack_size(*a);
		min = find_min(*a);
		if (min <= size / 2)
			while (min-- > 0)
				ra(a);
		else if (min > size / 2)
			while (min++ < size)
				rra(a);
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

void	small_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2 && (*a)->value > (*a)->next->value)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else
		sort_five(a, b);
}
