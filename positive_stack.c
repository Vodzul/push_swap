
#include "push_swap.h"

int	*bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	j = 0;
	i = 0;
	while (i < size - 1)
	{
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (arr);
} // time complexity cok olursa flagle dizi sirali mi diye kontrol et

int	find_pos(int *arr, int find, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == find)
			return (i);
		i++;
	}
	return (-1); //error
}

void	stack_to_arr(t_stack **a, int *arr)
{
	t_stack *temp;
	int	i;
	int size;

	size = stack_size(*a);
	arr = malloc(sizeof(int) * size);
	i = 0;
	temp = *a;
	while (i < size)
	{
		arr[i] = temp->value;
		temp = temp->next;
		i++;
	}
}

void	positive_stack(t_stack **a)
{
	int	*arr;
	t_stack *temp;
	int	size;
	int	pos;

	size = stack_size(*a);
	stack_to_arr(a, arr);
	arr = bubble_sort(arr, size);
	temp = *a;
	while (temp != NULL)
	{
		pos = find_pos(arr, temp->value, size);
		temp->value = pos;
		temp = temp->next;
	}
	free(arr);
}
