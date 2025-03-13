/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:18:00 by zamohame          #+#    #+#             */
/*   Updated: 2025/03/13 11:18:24 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack, t_stack **new)
{
	t_stack	*tmp;

	if (stack == NULL || *stack == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	if (new == NULL)
		*new = tmp;
	else
	{
		tmp->next = *new;
		*new = tmp;
	}
}

void	push_to_a(t_stack **b, t_stack **a)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	push_to_b(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
