/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:35:08 by oemelyan          #+#    #+#             */
/*   Updated: 2024/02/08 21:08:05 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_sorted(int *array, int *indexes, int nbrs)
{
	int		i;

	i = 0;
	while (i < nbrs - 1)
	{
		if (array[i] < array[i + 1])
			i++;
		else
			return ;
	}
	if (i == nbrs - 1)
	{
		write(1, "input is already sorted\n", 24);
		free (array);
		free (indexes);
		exit (1);
	}
}

int	count_words(char const *str, char delimiter)
{
	int			substr_counter;

	substr_counter = 0;
	while (*str)
	{
		if (*str != delimiter)
		{
			substr_counter++;
			while (*str && *str != delimiter)
				str++;
		}
		else
			str++;
	}
	return (substr_counter);
}

int	count_nbrs(int ac, char **av)
{
	int		nbrs;
	int		tmp;
	int		j;

	if (ac < 2)
	{
		write(1, "error, less than 2 argc\n", 24);
		return (1);
	}
	nbrs = 0;
	j = 1;
	while (j < ac)
	{
		tmp = count_words(av[j], ' ');
		nbrs = nbrs + tmp;
		j++;
	}
	if (nbrs < 2)
	{
		write(1, "error, less than 2 numbers\n", 27);
		exit (1);
	}
	return (nbrs);
}

int	duplicate_check(int nbr, int *array, char **arr_str)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (nbr == array[i])
		{
			write(1, "error, duplicate value\n", 23);
			free(array);
			free(arr_str);
			exit (1);
		}
		i++;
	}
	return (0);
}
