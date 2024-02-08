/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:26:43 by oemelyan          #+#    #+#             */
/*   Updated: 2024/02/08 22:56:39 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				number;
	int				target_index;
	struct s_stack	*next;
}					t_stack;

//**organizing space**
int					count_nbrs(int ac, char **av);
int					count_words(char const *str, char delimiter);
void				parse_it(int ac, char **av, int *array);
int					duplicate_check(int nbr, int *array, char **arr_str);
char				**ft_split(char const *s, char c);
void				get_indexes(int argc, int *arr, int *indexes);
void				is_sorted(int *array, int *indexes, int nbrs);
int					malloc2(size_t count, void **ptr);
int					create_stack(int count, t_stack **node);
void				fill_stack(t_stack *node, int *numbers, int *indices,
						int count);
void				free_stack(t_stack *node);
void				free_stacks(t_stack **stack_a, t_stack **stack_b);

//**stack operations**
void				push_stack(t_stack **stack_1, t_stack **stack_2, char c);
void				rotate_stack(t_stack **stack, char c);
void				swap_stack(t_stack **stack, char c);
void				rr_stack(t_stack **stack, char c);

//**sorting decision**
void				sort_choice(t_stack **stack_a, t_stack **stack_b, int nbrs);
void				sort3(t_stack **stack);
void				sort_3_commands(t_stack **stack);
void				sort7(t_stack **stack_a, t_stack **stack_b);
void				sort_em_all(t_stack **stack_a, t_stack **stack_b);

//**utils for sort functions**
t_stack				*get_min_node(t_stack **stack);
int					count_down(t_stack **stack, t_stack *node);
int					count_up(t_stack **stack, t_stack *node);
void				move_node_down(t_stack **stack, int moves, char c);
void				move_node_up(t_stack **stack, int moves, char c);
int					get_stack_size(t_stack **stack);
void				push_back_to_a(t_stack **stack_a, t_stack **stack_b);
double				square_root(int stack_size);
t_stack				*get_max_node(t_stack **stack);

#endif