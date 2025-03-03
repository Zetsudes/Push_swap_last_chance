/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/01/14 09:51:42 by zamohame          #+#    #+#             */
/*   Updated: 2025/02/10 10:17:47 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	int	max;

	max = find_max_index(*stack);
	if ((*stack)->index == max)
		rotate_a(stack);
	else if ((*stack)->next->index == max)
		reverse_rotate_a(stack);
	if ((*stack)->index > (*stack)->next->index)
		swap_a(stack);
}

void sort_four(t_stack **a, t_stack **b)
{
    int 	pos;
    t_stack 	*temp;
	
	pos = 0;
	temp = *a;
    
    while (temp && temp->index != 0)
    {
        pos++;
        temp = temp->next;
    }
    if (pos == 1)
        rotate_a(a);
    else if (pos == 2)
    {
        rotate_a(a);
        rotate_a(a);
    }
    else if (pos == 3)
        reverse_rotate_a(a);
    push_to_b(a, b);
    sort_three(a);
    push_to_a(b, a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	while (size--)
	{
		if ((*a)->index == 0 || (*a)->index == 1)
			push_to_b(a, b);
		else
			rotate_a(a);
	}
	sort_three(a);
	push_to_a(b, a);
	push_to_a(b, a);
	if ((*a)->index > (*a)->next->index)
		swap_a(a);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	max_number;
	int	max_bits;
	int	i;
	int	j;

	max_number = find_max_index(*a);
	max_bits = find_bits(max_number);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j <= max_number)
		{
			if (((*a)->index >> i) & 1)
				rotate_a (a);
			else
				push_to_b(a, b);
			j++;
		}
		while (*b)
			push_to_a(b, a);
		i++;
	}
}

void	sort(t_stack **a, t_stack **b)
{
	int 	size;

	size = stack_size(*a);
	if (is_sorted(a))
		return ;
	if (!is_sorted(a) && size <= 3)
		sort_three(a);
	else if (!is_sorted(a) && size == 4)
		sort_four(a, b);
	else if (!is_sorted(a) && size == 5)
		sort_five(a, b);
	else if (!is_sorted(a) && (size >= 15 && size <= 100))
	{
		push_a_bit(a, b);
		push_back(a, b);
	}
	else if (!is_sorted(a))
		radix_sort(a, b);
	else
	{
		free_stack(a);
		free_stack(b);
	}
}
