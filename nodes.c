/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:42:38 by oemelyan          #+#    #+#             */
/*   Updated: 2024/02/08 22:23:55 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	malloc2(size_t count, void **ptr)
{
	*ptr = malloc(count);
	return (*ptr == NULL);
}

int	create_stack(int count, t_stack **node)
{
	if (count == 0)
		return (0);
	if (malloc2(sizeof(t_stack), (void **)node))
		return (1);
	(*node)->number = 0;
	(*node)->target_index = 0;
	(*node)->next = NULL;
	if (create_stack(count - 1, &(*node)->next))
		return (free(*node), 1);
	return (0);
}

void	fill_stack(t_stack *node, int *numbers, int *indices, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		node->number = numbers[i];
		node->target_index = indices[i];
		node = node->next;
		i++;
	}
}

void	free_stack(t_stack *node)
{
	t_stack	*next;

	while (node != NULL)
	{
		next = node->next;
		free(node);
		node = next;
	}
}

void	free_stacks(t_stack **stack_a, t_stack **stack_b)

{
	free_stack(*stack_a);
	free_stack(*stack_b);
}
