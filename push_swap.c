/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:18:13 by zamohame          #+#    #+#             */
/*   Updated: 2025/03/13 11:18:22 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	handle_input(argc, argv);
	a = init_stack(argc, argv);
	b = NULL;
	set_index(a, stack_size(a));
	sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
