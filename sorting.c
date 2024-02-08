/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:11:14 by oemelyan          #+#    #+#             */
/*   Updated: 2024/02/08 22:14:01 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_stack **stack)
{
	if ((*stack)->number < (*stack)->next->next->number
		&& (*stack)->next->next->number < (*stack)->next->number
		&& (*stack)->number < (*stack)->next->number)
		sort_3_commands(stack);
	else if ((*stack)->number > (*stack)->next->number
		&& (*stack)->number < (*stack)->next->next->number
		&& (*stack)->next->number < (*stack)->next->next->number)
		swap_stack(stack, 'a');
	else if ((*stack)->number < (*stack)->next->number
		&& (*stack)->number > (*stack)->next->next->number
		&& (*stack)->next->number > (*stack)->next->next->number)
		rr_stack(stack, 'a');
	else if ((*stack)->number > (*stack)->next->number
		&& (*stack)->next->number > (*stack)->next->next->number
		&& (*stack)->number > (*stack)->next->next->number)
	{
		swap_stack(stack, 'a');
		rr_stack(stack, 'a');
	}
	else if ((*stack)->number > (*stack)->next->number
		&& (*stack)->number > (*stack)->next->next->number
		&& (*stack)->next->number < (*stack)->next->next->number)
		rotate_stack(stack, 'a');
}

int	get_stack_size(t_stack **stack)
{
	int		size;
	t_stack	*current;

	size = 0;
	current = (*stack);
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while (get_stack_size(stack_b) != 0)
		push_stack(stack_a, stack_b, 'a');
}

void	sort7(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*min_nbr;
	int			go_down;
	int			go_up;

	while (get_stack_size(stack_a) > 3)
	{
		min_nbr = get_min_node(stack_a);
		go_down = count_down(stack_a, min_nbr);
		go_up = count_up(stack_a, min_nbr);
		if (go_down < go_up)
			move_node_down(stack_a, go_down, 'a');
		else
			move_node_up(stack_a, go_up, 'a');
		push_stack(stack_b, stack_a, 'b');
	}
	sort3(stack_a);
	push_back_to_a(stack_a, stack_b);
}

void	sort_choice(t_stack **stack_a, t_stack **stack_b, int nbrs)
{
	if (nbrs == 2)
		rotate_stack(stack_a, 'a');
	else if (nbrs <= 3)
		sort3(stack_a);
	else if (nbrs <= 7)
		sort7(stack_a, stack_b);
	else
		sort_em_all(stack_a, stack_b);
}
