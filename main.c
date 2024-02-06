/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:28:42 by oemelyan          #+#    #+#             */
/*   Updated: 2024/02/06 20:54:30 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			*arr;
	int			*indexes;

	if (argc < 2)
		return (1);
	arr = malloc((argc - 1) * sizeof(int));
	indexes = malloc((argc - 1) * sizeof(int));
	if (arr == NULL || indexes == NULL)
	{
		printf("memory allocation failed\n");
		return (1);
	}
	create_arr(argc, argv, arr);
	get_indexes(argc, arr, indexes);

	if (create_stack(argc - 1, &stack_a)) //instead argc count numbers
		return (write(1, "Creation of stack failed\n", 25), 1);

	fill_stack(stack_a, arr, indexes, argc - 1); //how many elements

	printf("stack a before sorting\n");
	print_stack(&stack_a); //delete



	printf("stack b is\n");
	print_stack(&stack_b);

	sort_choice(&stack_a, &stack_b, argc - 1);

	printf("stack a after sorting\n");
	print_stack(&stack_a); //delete

	printf("stack b after sorting\n");
	print_stack(&stack_b); //delete

	free_stacks(&stack_a, &stack_b);
	free(arr);
	free(indexes);
	return (0);
}
