/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:14:19 by zamohame          #+#    #+#             */
/*   Updated: 2025/03/13 11:52:21 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**initialize_array(int argc, char **argv)
{
	char	**array;

	if (argc == 2)
		array = ft_split(argv[1], ' ');
	else
		array = argv + 1;
	return (array);
}

long	long_atoi(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

void	validate_input(char **array)
{
	int		i;
	long	tmp_argv;

	i = 0;
	while (array[i])
	{
		if (!is_number(array[i]))
			handle_error();
		tmp_argv = long_atoi(array[i]);
		if (tmp_argv < INT_MIN || tmp_argv > INT_MAX)
			handle_error();
		i++;
		if (has_duplicate(array))
			handle_error();
	}
}
