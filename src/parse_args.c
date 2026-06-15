/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 14:20:00 by anmakhov          #+#    #+#             */
/*   Updated: 2026/06/15 13:44:10 by anmakhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

/*
** Checks if the array contains any duplicate integers.
** Returns 1 if duplicates are found, 0 otherwise.
*/
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
** Frees memory allocated by the ft_split function.
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
** Counts the total number of integers across all arguments combined.
** If an empty argument ("") is encountered, returns -1 (error).
*/
static int	count_total_words(int argc, char **argv)
{
	int		i;
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
		count += count_words_in_split(split);
		free_split(split);
		i++;
	}
	return (count);
}

/*
** Iterates through all arguments, splits them,
** and fills the array with validated integers.
*/
static int	fill_all_nums(int argc, char **argv, int *nums)
{
	int		i;
	int		k;
	char	**split;

	i = 1;
	k = 0;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!fill_single_split(split, nums, &k))
		{
			free_split(split);
			return (0);
		}
		free_split(split);
		i++;
	}
	return (1);
}

/*
** MAIN PARSER
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
