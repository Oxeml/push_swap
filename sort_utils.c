/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:55:10 by oemelyan          #+#    #+#             */
/*   Updated: 2024/02/06 18:59:00 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double square_root(int stack_size)
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