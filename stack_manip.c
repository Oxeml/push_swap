/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:30:03 by oemelyan          #+#    #+#             */
/*   Updated: 2024/02/06 13:03:25 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack **stack_1, t_stack **stack_2)//stack_1 it's where the new node goes
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
}

void	rotate_stack(t_stack **stack)
{
	t_stack		*element;

	element = (*stack);
	while (element->next)
		element = element->next;
	element->next = (*stack);
	(*stack) = (*stack)->next;
	element->next->next = NULL;
}

void	swap_stack(t_stack **stack)
{
	t_stack		*first;
	t_stack		*second;

	first = (*stack)->next;
	second = (*stack);
	second->next = first->next;
	first->next = second;
	(*stack) = first;
}

void rr_stack(t_stack **stack)
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
}
