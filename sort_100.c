/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:21:16 by zamohame          #+#    #+#             */
/*   Updated: 2025/03/17 13:37:22 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_index(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	max = -1;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int	get_pos(t_stack *stack, int target_index)
{
	int		pos;
	t_stack	*tmp;

	tmp = stack;
	pos = 0;
	while (tmp)
	{
		if (tmp->index == target_index)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (-1);
}

void	push_a_bit(t_stack **a, t_stack **b)
{
	int	total;
	int	bit_size;
	int	pushed;
	int	current_rank;

	total = stack_size(*a);
	bit_size = total / 15;
	pushed = 0;
	while (*a)
	{
		current_rank = (*a)->index;
		if (current_rank <= pushed + bit_size)
		{
			push_to_b(a, b);
			pushed++;
			if (*b && (*b)->index < pushed - (bit_size / 2))
				rotate_b(b);
		}
		else
			rotate_a(a);
	}
}

void	push_back(t_stack **a, t_stack **b)
{
	int	max;
	int	max_pos;
	int	size;

	while (*b)
	{
		max = get_max_index(*b);
		max_pos = get_pos(*b, max);
		size = stack_size(*b);
		if (max_pos <= (size / 2))
		{
			while (*b && (*b)->index != max)
				rotate_b(b);
		}
		else
		{
			while (*b && (*b)->index != max)
				reverse_rotate_b(b);
		}
		push_to_a(b, a);
	}
}
