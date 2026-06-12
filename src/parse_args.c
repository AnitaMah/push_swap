/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 14:20:00 by anmakhov          #+#    #+#             */
/*   Updated: 2026/06/12 14:44:09 by anmakhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

int	check_duplicates(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
** Звільняє пам'ять, виділену функцією ft_split
*/
static void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

/*
** Рахує загальну кількість чисел у всіх аргументах разом узятих.
** Якщо знаходить порожній аргумент (""), повертає -1 (помилка).
*/
static int	count_total_words(int argc, char **argv)
{
	int		i;
	int		j;
	int		count;
	char	**split;

	i = 1;
	count = 0;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split || !split[0])
		{
			if (split)
				free_split(split);
			return (-1);
		}
		j = 0;
		while (split[j])
		{
			count++;
			j++;
		}
		free_split(split);
		i++;
	}
	return (count);
}

/*
** Проходить по всіх аргументах,
	сплітить їх і заповнює масив інтами з валідацією
*/
static int	fill_all_nums(int argc, char **argv, int *nums)
{
	int		i;
	int		j;
	int		k;
	int		error;
	char	**split;

	i = 1;
	k = 0;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split[j])
		{
			error = 0;
			if (!is_valid_number(split[j]))
				return (free_split(split), 0);
			nums[k] = ft_atoi_ps(split[j], &error);
			if (error)
				return (free_split(split), 0);
			k++;
			j++;
		}
		free_split(split);
		i++;
	}
	return (1);
}

/*
** ГОЛОВНИЙ ПАРСЕР
*/
int	*parse_args(int argc, char **argv, int *size)
{
	int	*nums;
	int	len;

	if (argc < 2)
		return (NULL);
	len = count_total_words(argc, argv);
	if (len <= 0)
		return (NULL);
	nums = malloc(sizeof(int) * len);
	if (!nums)
		return (NULL);
	if (!fill_all_nums(argc, argv, nums))
	{
		free(nums);
		return (NULL);
	}
	*size = len;
	return (nums);
}
