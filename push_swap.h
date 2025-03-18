/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:18:08 by zamohame          #+#    #+#             */
/*   Updated: 2025/03/14 10:43:31 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "greg_lib/libft.h"
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define MAX_SIZE 100

typedef struct s_stack
{
	long			value;
	int				index;
	struct s_stack	*next;
}					t_stack;

void				push(t_stack **stack, t_stack **new);
void				push_to_a(t_stack **b, t_stack **a);
void				push_to_b(t_stack **a, t_stack **b);

void				swap(t_stack **stack);
void				swap_a(t_stack **a);
void				swap_b(t_stack **b);
void				swap_both(t_stack **a, t_stack **b);

void				rotate(t_stack **stack);
void				rotate_a(t_stack **a);
void				rotate_b(t_stack **b);
void				rotate_both(t_stack **a, t_stack **b);

void				reverse_rotate(t_stack **stack);
void				reverse_rotate_a(t_stack **a);
void				reverse_rotate_b(t_stack **b);
void				reverse_rotate_both(t_stack **a, t_stack **b);

void				sort(t_stack **a, t_stack **b);
void				sort_three(t_stack **stack);
void				sort_four(t_stack **a, t_stack **b);
void				sort_five(t_stack **a, t_stack **b);

int					count_arg(char **array);
int					has_duplicate(char **argv);
int					is_sorted(t_stack **s);
int					is_number(char *str);
void				handle_input(int argc, char **argv);

t_stack				*init_stack(int argc, char **argv);
t_stack				*new_node(int new);
void				set_index(t_stack *stack, int size);
void				insert_node(t_stack **head, int new);
int					stack_size(t_stack *head);

int					handle_error(void);
void				free_array(char **array);
void				free_stack(t_stack **stack);
int					find_max_index(t_stack *head);
int					find_bits(int max_number);

int					get_pos(t_stack *stack, int target_index);
int					get_max_index(t_stack *stack);
void				push_back(t_stack **a, t_stack **b);
void				push_a_bit(t_stack **a, t_stack **b);

char				**initialize_array(int argc, char **argv);
long				long_atoi(const char *str);
void				validate_input(char **array);

#endif
