
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN (-2147483648)

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

//stack utils
t_stack *create_node(int value);
void	stack_add_back(t_stack **stack, t_stack *new_node);
int		stack_size(t_stack *stack);
void	destroy_stack(t_stack **stack);

//swap func.
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
//push func.
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
//rotate func.
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
//revr func.
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

//small cases
void	sort_three(t_stack **a);
int		find_min(t_stack *a);
void	sort_five(t_stack **a, t_stack **b);
void	small_sort(t_stack **a, t_stack **b);

//positive stack
int	*bubble_sort(int *arr, int size);
int	find_pos(int *arr, int find, int size);
int	*stack_to_arr(t_stack **a);
void	positive_stack(t_stack **a);

//radix sort
void	radix_sort(t_stack **a, t_stack **b, int count);
void	sort_stack(t_stack **a, t_stack **b);

#endif