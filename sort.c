/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:21:57 by zamohame          #+#    #+#             */
/*   Updated: 2025/03/03 15:22:01 by zamohame         ###   ########.fr       */
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

void	sort_four(t_stack **a, t_stack **b)
{
	int		pos;
	t_stack	*temp;

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

void	sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (is_sorted(a))
		return ;
	if (!is_sorted(a) && size <= 3)
		sort_three(a);
	else if (!is_sorted(a) && size == 4)
		sort_four(a, b);
	else if (!is_sorted(a) && size == 5)
		sort_five(a, b);
	else if (!is_sorted(a))
	{
		push_a_bit(a, b);
		push_back(a, b);
	}
	else
	{
		free_stack(a);
		free_stack(b);
	}
}
