/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:19:52 by oemelyan          #+#    #+#             */
/*   Updated: 2024/02/06 20:53:11 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_max_node(t_stack **stack)
{
	t_stack		*current;
	t_stack		*maximum;

	current = (*stack);
	maximum = (*stack);
	while (current != NULL)
	{
		if (current->number > maximum->number)
			maximum = current;
		current = current->next;
	}
	return (maximum);
}

void part_2_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*max;
	int			go_down;
	int			go_up;

	while (get_stack_size(stack_b) != 0)
	{
		max = get_max_node(stack_b);
		go_down = count_down(stack_b, max);
		printf("to move the node down we need %d moves\n", go_down);
		go_up = count_up(stack_b, max);
		printf("to move the node up we need %d moves\n", go_up);
		if (go_down < go_up)
			move_node_down(stack_b, go_down);
		else
			move_node_up(stack_b, go_up);
		push_stack(stack_a, stack_b);
	}
}

void	sort_em_all(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*current;
	int			index;
	int			range;

	printf("big sort starts here\n");
	current = (*stack_a);
	index = 0;
	range = ((int)square_root(get_stack_size(stack_a)) * 14) / 10;
	while (current != NULL)
	{
		if (current->target_index <= index)
		{

			push_stack(stack_b, stack_a);
			rotate_stack(stack_b);
			index++;
		}
		else if (current->target_index <= index + range)
		{

			push_stack(stack_b, stack_a);
			index++;
		}
		else
			rotate_stack(stack_a);
		current = (*stack_a);
	}
	printf("stack a after k_sort\n");
	print_stack(stack_a); //delete

	printf("stack b after k_sort\n");
	print_stack(stack_b); //delete
	part_2_sort(stack_a, stack_b);
}