/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:26:43 by oemelyan          #+#    #+#             */
/*   Updated: 2024/02/06 20:46:40 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	int				number;
	int				target_index;
	struct s_stack	*next;
}	t_stack;

//**organizing space**
void	create_arr(int argc, char **argv, int *arr);
void	get_indexes(int argc, int *arr, int *indexes);
int		malloc2(size_t count, void **ptr);
int		create_stack(int count, t_stack **node);
void	fill_stack(t_stack *node, int *numbers, int *indices, int count);
void	free_stack(t_stack *node);
void	free_stacks(t_stack **stack_a, t_stack **stack_b);

//**stack operations**
void	push_stack(t_stack **stack_1, t_stack **stack_2);
void	rotate_stack(t_stack **stack);
void	swap_stack(t_stack **stack);
void	rr_stack(t_stack **stack);

void	print_stack(t_stack **stack); //delete

//**sorting decision**
void	sort_choice(t_stack **stack_a, t_stack **stack_b, int args);
void	sort3(t_stack **stack);
void	sort7(t_stack **stack_a, t_stack **stack_b);
void	sort_em_all(t_stack **stack_a, t_stack **stack_b);

//**utils for sort functions**
t_stack		*get_min_node(t_stack **stack);
int			count_down(t_stack **stack, t_stack *node);
int			count_up(t_stack **stack, t_stack *node);
void		move_node_down(t_stack **stack, int moves);
void		move_node_up(t_stack **stack, int moves);
int			get_stack_size(t_stack **stack);
void		push_back_to_a(t_stack **stack_a, t_stack **stack_b);
double		square_root(int stack_size);
t_stack		*get_max_node(t_stack **stack);





#endif