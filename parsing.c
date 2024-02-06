/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:26:08 by oemelyan          #+#    #+#             */
/*   Updated: 2024/02/04 21:05:43 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//add split for "  " argument

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == '-') || (str [i] == '+'))
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while ((char)str[i] >= '0' && (char)str[i] <= '9')
	{
		res = (str[i] - '0') + res * 10;
		i++;
	}
	return (res * sign);
}

void	bubble_sort(int argc, int	*arr)
{
	int		i;
	int		temp;
	int		swapped = 1;

	while (swapped)
	{
		i = 1;
		swapped = 0;
		while (i < argc - 1)
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
		//delete
	printf("sorted arr: \n");
	i = 0;
	while (i < argc - 1)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	//delete above
}

void	put_index(int argc, int *arr, int *sorted, int *indexes)
{
	int		i;
	int		j;

	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (j < argc - 1)
		{
			if (arr[i] == sorted[j])
			{
				indexes[i] = j;
			}
			j++;
		}
		i++;
	}

	printf("indexes arr is: \n");
	i = 0;
	while (i < argc - 1)
	{
		printf("%d ", indexes[i]);
		i++;
	}
	printf("\n");
}

void get_indexes(int argc, int *arr, int *indexes)
{
	int		*sorted_arr;
	int		i;

	sorted_arr = malloc((argc - 1) * sizeof(int));
	if (sorted_arr == NULL)
	{
		printf("memory allocation failed\n");
		return ;
	}
	i = 0;
	while (i < argc - 1) //we need to count how many elements
	{
		sorted_arr[i] = arr[i];
		i++;
	}
	bubble_sort(argc, sorted_arr);
	put_index(argc, arr, sorted_arr, indexes);
	free(sorted_arr);
}

void	create_arr(int argc, char **argv, int *arr)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (i < argc - 1)
	{
		arr[i] = ft_atoi(argv[j]);
		i++;
		j++;
	}
}
