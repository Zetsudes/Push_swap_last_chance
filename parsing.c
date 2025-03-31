/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:22:16 by zamohame          #+#    #+#             */
/*   Updated: 2025/03/31 13:24:06 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_arg(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	has_duplicate(char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = count_arg(argv);
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current && current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
