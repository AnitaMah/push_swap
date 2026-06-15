/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:48:01 by anmakhov          #+#    #+#             */
/*   Updated: 2026/06/15 13:50:54 by anmakhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

static int	handle_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

static void	cleanup(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}

static int	init_and_fill_stack(t_stack *a, int argc, char **argv, t_input *in)
{
	in->arr = parse_args(argc, argv, &in->size);
	if (!in->arr || in->size <= 0)
		return (0);
	if (check_duplicates(in->arr, in->size))
	{
		free(in->arr);
		return (0);
	}
	if (!stack_from_array(a, in->arr, in->size))
	{
		free(in->arr);
		return (0);
	}
	return (1);
}

static void	select_sort(t_stack *a, t_stack *b, int size, double disorder)
{
	if (size <= 1)
		return ;
	if (size <= 3)
		sort_three(a);
	else if (size <= 4 || size <= 5)
		sort_four_five(a, b, size);
	else if (size <= 100)
	{
		if (disorder < 0.15)
			selection_sort_adaptation(a, b);
		else
			chunk_sort(a, b);
	}
	else
	{
		if (disorder < 0.10)
			selection_sort_adaptation(a, b);
		else
			radix_sort(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	double	disorder;
	t_input	in;

	if (argc < 2)
		return (0);
	init_stack(&a, 'a');
	init_stack(&b, 'b');
	if (!init_and_fill_stack(&a, argc, argv, &in))
		return (handle_error());
	if (is_sorted(&a))
		return (cleanup(&a, &b), 0);
	disorder = compute_disorder(in.arr, in.size);
	free(in.arr);
	normalize_index(&a);
	select_sort(&a, &b, in.size, disorder);
	cleanup(&a, &b);
	return (0);
}
