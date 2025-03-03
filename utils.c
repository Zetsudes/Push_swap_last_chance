#include "push_swap.h"


int		handle_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

void    free_array(char **array) 
{
    int     i;
     
    i = 0;
    if (!array)
        return;
    while (array[i]) {
        free(array[i]);
        i++;
    }
    free(array);
}

void free_stack(t_stack **stack) 
{
    t_stack *tmp;

    while (*stack) 
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }
}

int		find_max_index(t_stack *stack)
{
	int		max;
	t_stack		*tmp;

	max = INT_MIN;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int		find_bits(int max_number)
{
	int		max_bits;

	max_bits = 0;
	while (max_number > 0)
	{
		max_number >>= 1;
		max_bits++;
	}
	return (max_bits);
}
