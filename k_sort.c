/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:19:52 by oemelyan          #+#    #+#             */
/*   Updated: 2024/02/08 23:01:49 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_min_node(t_stack **stack)
{
	t_stack	*current;
	t_stack	*minimum;

	current = (*stack);
	minimum = (*stack);
	while (current != NULL)
	{
		if (current->number < minimum->number)
			minimum = current;
		current = current->next;
	}
	return (minimum);
}

t_stack	*get_max_node(t_stack **stack)
{
	t_stack	*current;
	t_stack	*maximum;

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

void	part_2_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*max;
	int		go_down;
	int		go_up;

	while (get_stack_size(stack_b) != 0)
	{
		max = get_max_node(stack_b);
		go_down = count_down(stack_b, max);
		go_up = count_up(stack_b, max);
		if (go_down < go_up)
			move_node_down(stack_b, go_down, 'b');
		else
			move_node_up(stack_b, go_up, 'b');
		push_stack(stack_a, stack_b, 'a');
	}
}

void	sort_em_all(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	int		index;
	int		range;

	current = (*stack_a);
	index = 0;
	range = ((int)square_root(get_stack_size(stack_a)) * 14) / 10;
	while (current != NULL)
	{
		if (current->target_index <= index)
		{
			push_stack(stack_b, stack_a, 'b');
			rotate_stack(stack_b, 'b');
			index++;
		}
		else if (current->target_index <= index + range)
		{
			push_stack(stack_b, stack_a, 'b');
			index++;
		}
		else
			rotate_stack(stack_a, 'a');
		current = (*stack_a);
	}
	part_2_sort(stack_a, stack_b);
}
