
#include "push_swap.h"

void	r_rotate(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **a)
{
	r_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b)
{
	r_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	r_rotate(a);
	r_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}
