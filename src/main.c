/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 12:21:42 by anmakhov          #+#    #+#             */
/*   Updated: 2026/06/12 14:48:52 by anmakhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"
#include <stdio.h>

/*
** Prints error message.
*/
static int	handle_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

/*
** Frees both stacks safely.
*/
static void	cleanup(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}

/*
** Builds stack, checks parsing, and validates duplicates.
*/
static int	init_and_fill_stack(t_stack *a, int argc, char **argv, int **arr,
		int *size)
{
	*arr = parse_args(argc, argv, size);
	if (!*arr || *size <= 0)
		return (0);
	/* 1. ADDED: Check for duplicates directly after parsing */
	if (check_duplicates(*arr, *size))
	{
		free(*arr);
		return (0);
	}
	if (!stack_from_array(a, *arr, *size))
	{
		free(*arr);
		return (0);
	}
	/* FIX: Removed free(*arr) from here so main can use it for disorder calculation */
	return (1);
}

/*
** Selects sorting algorithm based on disorder.
*/
static void	select_sort(t_stack *a, t_stack *b, int size, double disorder)
{
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4 || size == 5)
		sort_four_five(a, b, size);
	else
	{
		if (disorder < 0.25)
			selection_sort_adaptation(a, b);
		else if (disorder < 0.55)
			chunk_sort(a, b);
		else
			radix_sort(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		*arr;
	int		size;
	double	disorder;

	if (argc < 2)
		return (0);
	init_stack(&a, 'a');
	init_stack(&b, 'b');
	if (!init_and_fill_stack(&a, argc, argv, &arr, &size))
		return (handle_error());
	if (is_sorted(&a))
	{
		return (cleanup(&a, &b), 0);
	}
	disorder = compute_disorder(arr, size);
	free(arr);
	normalize_index(&a);
	select_sort(&a, &b, size, disorder);
	cleanup(&a, &b);
	return (0);
}
