/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/01/14 09:49:22 by zamohame          #+#    #+#             */
/*   Updated: 2025/02/10 11:23:30 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	reverse_rotate(t_stack **stack)
{
	t_stack 	*prev;
	t_stack 	*new;

	if (!*stack || !(*stack)->next)
		return ;
	prev = *stack;
	while (prev->next)
	{
		new = prev;
		prev = prev->next;
	}
	prev->next = *stack;
	new->next = NULL;
	*stack = prev;
}

void	reverse_rotate_a(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	reverse_rotate_both(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
