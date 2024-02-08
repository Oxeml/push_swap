/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:55:10 by oemelyan          #+#    #+#             */
/*   Updated: 2024/02/08 21:53:15 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	square_root(int stack_size)
{
	double		x;
	double		epsilon;

	x = stack_size;
	epsilon = 0.000001;
	while ((x - stack_size / x) > epsilon)
	{
		x = (x + stack_size / x) / 2;
	}
	return (x);
}

int	count_down(t_stack **stack, t_stack *node)
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

int	count_up(t_stack **stack, t_stack *node)
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

void	move_node_down(t_stack **stack, int moves, char c)
{
	while (moves)
	{
		rr_stack(stack, c);
		moves--;
	}
}

void	move_node_up(t_stack **stack, int moves, char c)
{
	while (moves)
	{
		rotate_stack(stack, c);
		moves--;
	}
}
