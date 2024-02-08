/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:28:42 by oemelyan          #+#    #+#             */
/*   Updated: 2024/02/08 22:20:23 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			nbrs;
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			*arr;
	int			*indexes;

	nbrs = count_nbrs(argc, argv);
	arr = malloc((nbrs) * sizeof(int));
	indexes = malloc((nbrs) * sizeof(int));
	if (arr == NULL || indexes == NULL)
	{
		write(1, "memory allocation failed\n", 25);
		return (1);
	}
	arr = parse_it(argc, argv, nbrs, arr);
	is_sorted(arr, indexes, nbrs);
	get_indexes(nbrs, arr, indexes);
	if (create_stack(nbrs, &stack_a))
		return (write(1, "Creation of stack failed\n", 25), 1);
	fill_stack(stack_a, arr, indexes, nbrs);
	sort_choice(&stack_a, &stack_b, nbrs);
	free_stacks(&stack_a, &stack_b);
	free(arr);
	free(indexes);
	return (0);
}
