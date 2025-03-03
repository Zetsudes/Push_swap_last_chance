/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/01/24 14:05:49 by zamohame          #+#    #+#             */
/*   Updated: 2025/01/30 11:38:19 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*init_stack(int argc, char **argv)
{
	t_stack		*a;
	char	**tmp;
	int		i;

	a = NULL;
	i = 0;
	if (argc == 2)
		tmp = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		tmp = argv;
	}
	while (tmp[i])
	{
		insert_node(&a, ft_atoi(tmp[i]));
		i++;
	}
	if (argc == 2)
		free_array(tmp);
	return (a);
}

void	set_index(t_stack *stack, int size)
{
	t_stack	*max;
	t_stack	*tmp;

	while (size-- > 0)
	{
		max = NULL;
		tmp = stack;
		while (tmp)
		{
			if (!tmp->index && (max == NULL
					|| tmp->value > max->value))
				max = tmp;
			tmp = tmp->next;
		}
		if (max)
			max->index = size;
	}
}

t_stack		*new_node(int new)
{
	t_stack		*node;

	node = ft_calloc(1, sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = new;
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	insert_node(t_stack **head, int new)
{
	t_stack	*node;
	t_stack	*current;

	if (*head == NULL)
	{
		*head = new_node(new);
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	node = new_node(new);
	current->next = node;
}

int		stack_size(t_stack *head)
{
	int	i;

	i = 0;
	while (head != NULL)
	{
		head = head->next;
		i++;
	}
	return (i);
}