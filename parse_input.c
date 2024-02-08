/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:46:36 by oemelyan          #+#    #+#             */
/*   Updated: 2024/02/08 22:57:34 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_range(char c, int res, int sign)
{
	if (sign < 0)
	{
		if ((((INT_MIN + (c - '0')) / 10) > -res))
		{
			write(1, "out of range\n", 13);
			exit (1);
		}
	}
	else if ((((INT_MAX - (c - '0')) / 10) < res))
	{
		write(1, "out of range\n", 13);
		exit (1);
	}
}

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
		check_range(str[i], res, sign);
		res = (str[i] - '0') + res * 10;
		i++;
	}
	return (res * sign);
}

int	is_a_number(char c)
{
	int		i;
	char	*nbrs;

	nbrs = "0123456789";
	i = 0;
	while (i < 10)
	{
		if (c == nbrs[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	only_integers(char **arr_str, int *array)
{
	int		i;
	int		j;

	i = 0;
	while (arr_str[i] != NULL)
	{
		j = 0;
		while (arr_str[i][j] != '\0')
		{
			if (arr_str[i][j] == '-')
				j++;
			if (!is_a_number(arr_str[i][j]))
			{
				write(1, "error, it's not a number\n", 25);
				free(arr_str);
				free (array);
				exit (1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	parse_it(int ac, char **av, int *array)
{
	int		j;
	int		i;
	char	**arr_str;
	int		k;

	j = 1;
	k = 0;
	while (j < ac)
	{
		arr_str = ft_split(av[j], ' ');
		only_integers(arr_str, array);
		i = 0;
		while (arr_str[i])
		{
			duplicate_check(ft_atoi(arr_str[i]), array, arr_str);
			array[k] = ft_atoi(arr_str[i]);
			free(arr_str[i]);
			k++;
			i++;
		}
		free(arr_str);
		j++;
	}
}
