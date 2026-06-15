/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   untils_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 11:51:48 by anmakhov          #+#    #+#             */
/*   Updated: 2026/06/15 13:42:50 by anmakhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

/*
** Frees memory allocated by ft_split.
** Used only when input was a single quoted string (argc == 2).
*/
void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

/*
** Checks if a string is a valid integer format.
** Allows optional '+' or '-' sign at the beginning.
** Ensures at least one digit exists.
*/
int	is_valid_number(char *s)
{
	int	i;

	if (!s || !s[0])
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
** Counts number of strings in a NULL-terminated char** array.
*/
int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

/*
** Frees args only if they were created using ft_split.
** Prevents accidental free of argv memory.
*/
void	free_args_if_split(int argc, char **args)
{
	if (argc == 2)
		free_split(args);
}

/*
** Helper to iterate through a split array and populate the nums array.
** Returns 0 on failure, 1 on success.
*/
int	fill_single_split(char **split, int *nums, int *k)
{
	int	j;
	int	error;

	j = 0;
	while (split[j])
	{
		error = 0;
		if (!is_valid_number(split[j]))
			return (0);
		nums[*k] = ft_atoi_ps(split[j], &error);
		if (error)
			return (0);
		(*k)++;
		j++;
	}
	return (1);
}
