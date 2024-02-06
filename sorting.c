/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:11:14 by oemelyan          #+#    #+#             */
/*   Updated: 2024/02/06 19:00:02 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort3(t_stack **stack)
{
	printf("the sort 3 starts\n");
	if ((*stack)->number < (*stack)->next->next->number && \
		(*stack)->next->next->number < (*stack)->next->number && \
			(*stack)->number < (*stack)->next->number)
	{
		swap_stack(stack);
		write(1, "sa\n", 3);
		rotate_stack(stack);
		write(1, "ra\n", 3);
	}
	else if ((*stack)->number > (*stack)->next->number && \
		(*stack)->number < (*stack)->next->next->number && \
			(*stack)->next->number < (*stack)->next->next->number)
	{
		swap_stack(stack);
		write(1, "sa\n", 3);
	}
	else if ((*stack)->number < (*stack)->next->number && \
		(*stack)->number > (*stack)->next->next->number && \
		(*stack)->next->number > (*stack)->next->next->number)
	{
		rr_stack(stack);
		write(1, "rra\n", 4);
	}
	else if ((*stack)->number > (*stack)->next->number && \
		(*stack)->next->number > (*stack)->next->next->number && \
			(*stack)->number > (*stack)->next->next->number)
	{
		swap_stack(stack);
		write(1, "sa\n", 3);
		rr_stack(stack);
		write(1, "rra\n", 4);
	}
	else if ((*stack)->number > (*stack)->next->number && \
		(*stack)->number > (*stack)->next->next->number && \
			(*stack)->next->number < (*stack)->next->next->number)
	{
		rotate_stack(stack);
		write(1, "ra\n", 3);
	}
}

t_stack *get_min_node(t_stack **stack)
{
	t_stack		*current;
	t_stack		*minimum;

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

int		count_down(t_stack **stack, t_stack *node)
{
	int		down_moves;
	t_stack	*current;

	down_moves = 0;
	current = (*stack);

	while (current != node)
	{
		current = current->next;
	}
	while (current != NULL)
	{
		down_moves++;
		current = current->next;
	}
	return (down_moves);
}

int		count_up(t_stack **stack, t_stack *node)
{
	int		up_moves;
	t_stack	*current;

	current = (*stack);
	up_moves = 0;
	while (current != node)
	{
		up_moves++;
		current = current->next;
	}
	return (up_moves);
}

void move_node_down(t_stack **stack, int moves)
{
	while (moves)
	{
		rr_stack(stack);
		moves--;
	}
}

void move_node_up(t_stack **stack, int moves)
{
	while (moves)
	{
		rotate_stack(stack);
		moves--;
	}
}

int		get_stack_size(t_stack **stack)
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

void push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while (get_stack_size(stack_b) != 0)
		push_stack(stack_a, stack_b);
}

void sort7(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*min_nbr;
	int			go_down;
	int			go_up;

	printf("stack_a size before pushing %d\n", get_stack_size(stack_a));

	while (get_stack_size(stack_a) > 3)
	{
		min_nbr = get_min_node(stack_a);
		printf("min number is: %d\n", min_nbr->number);
		go_down = count_down(stack_a, min_nbr);
		printf("to move the node down we need %d moves\n", go_down);
		go_up = count_up(stack_a, min_nbr);
		printf("to move the node up we need %d moves\n", go_up);
		if (go_down < go_up)
			move_node_down(stack_a, go_down);
		else
			move_node_up(stack_a, go_up);
		push_stack(stack_b, stack_a);
	}

	printf("stack_a size after pushing %d\n", get_stack_size(stack_a));

	printf("stack a before sort3\n");
	print_stack(stack_a); //delete

	printf("stack b before sort3\n");
	print_stack(stack_b); //delete

	sort3(stack_a);

	printf("stack a after sort3\n");
	print_stack(stack_a); //delete

	printf("stack b after sort3\n");
	print_stack(stack_b); //delete

	push_back_to_a(stack_a, stack_b);

	printf("stack a finally\n");
	print_stack(stack_a); //delete

	printf("stack b finally\n");
	print_stack(stack_b); //delete
}





void	sort_choice(t_stack **stack_a, t_stack **stack_b, int args)
{
	if (args <= 3)
		sort3(stack_a);
	else if (args <= 7)
		sort7(stack_a, stack_b);
	else
		sort_em_all(stack_a, stack_b);
}