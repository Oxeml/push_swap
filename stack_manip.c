/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:30:03 by oemelyan          #+#    #+#             */
/*   Updated: 2024/02/08 22:25:13 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack **stack_1, t_stack **stack_2, char c)
{
	t_stack		*first;

	first = (*stack_2);
	(*stack_2) = (*stack_2)->next;
	if ((*stack_1) == NULL)
	{
		(*stack_1) = first;
		(*stack_1)->next = NULL;
	}
	else
	{
		first->next = (*stack_1);
		(*stack_1) = first;
	}
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	rotate_stack(t_stack **stack, char c)
{
	t_stack		*element;

	element = (*stack);
	while (element->next)
		element = element->next;
	element->next = (*stack);
	(*stack) = (*stack)->next;
	element->next->next = NULL;
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	swap_stack(t_stack **stack, char c)
{
	t_stack		*first;
	t_stack		*second;

	first = (*stack)->next;
	second = (*stack);
	second->next = first->next;
	first->next = second;
	(*stack) = first;
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	rr_stack(t_stack **stack, char c)
{
	t_stack		*element;
	t_stack		*last;

	last = NULL;
	element = (*stack);
	while (element->next)
	{
		last = element;
		element = element->next;
	}
	last->next = NULL;
	element->next = (*stack);
	(*stack) = element;
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	sort_3_commands(t_stack **stack)
{
	swap_stack(stack, 'a');
	rotate_stack(stack, 'a');
}
