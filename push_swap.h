/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facelik <facelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:19:37 by facelik           #+#    #+#             */
/*   Updated: 2025/12/06 07:28:22 by facelik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_stack	*create_node(int value);
void	stack_add_back(t_stack **stack, t_stack *new_node);
int		stack_size(t_stack *stack);
void	destroy_stack(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
int		find_min(t_stack *a);
void	sort_five(t_stack **a, t_stack **b);
void	small_sort(t_stack **a, t_stack **b);
int		*bubble_sort(int *arr, int size);
int		find_pos(int *arr, int find, int size);
int		*stack_to_arr(t_stack *a);
int		positive_stack(t_stack *a);
void	radix_sort(t_stack **a, t_stack **b, int count);
void	sort_stack(t_stack **a, t_stack **b);
void	error_and_quit(t_stack **a, char **arr);
char	**arg_parsing(char **argv);
int		to_stack(char **arr, t_stack **a);
void	free_arr(char **arr);

#endif