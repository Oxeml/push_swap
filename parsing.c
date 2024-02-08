/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:26:08 by oemelyan          #+#    #+#             */
/*   Updated: 2024/02/08 22:24:34 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int nbrs, int	*arr)
{
	int		i;
	int		temp;
	int		swapped;

	swapped = 1;
	while (swapped)
	{
		i = 1;
		swapped = 0;
		while (i < nbrs)
		{
			if (arr[i - 1] > arr[i])
			{
				temp = arr[i];
				arr[i] = arr [i - 1];
				arr[i - 1] = temp;
				swapped = 1;
			}
			i++;
		}
	}
}

void	put_index(int nbrs, int *arr, int *sorted, int *indexes)
{
	int		i;
	int		j;

	i = 0;
	while (i < nbrs)
	{
		j = 0;
		while (j < nbrs)
		{
			if (arr[i] == sorted[j])
			{
				indexes[i] = j;
			}
			j++;
		}
		i++;
	}
}

void	get_indexes(int nbrs, int *arr, int *indexes)
{
	int		*sorted_arr;
	int		i;

	sorted_arr = malloc((nbrs) * sizeof(int));
	if (sorted_arr == NULL)
	{
		write(1, "memory allocation failed\n", 25);
		return ;
	}
	i = 0;
	while (i < nbrs)
	{
		sorted_arr[i] = arr[i];
		i++;
	}
	bubble_sort(nbrs, sorted_arr);
	put_index(nbrs, arr, sorted_arr, indexes);
	free(sorted_arr);
}
