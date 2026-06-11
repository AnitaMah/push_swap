/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:07:09 by anmakhov          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/06/11 15:35:19 by anmakhov         ###   ########.fr       */
=======
/*   Updated: 2026/06/11 15:05:30 by anmakhov         ###   ########.fr       */
>>>>>>> refs/remotes/origin/main
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <math.h>

t_node	*find_max(t_stack *b)
{
	t_node	*current;
	t_node	*max;

	if (!b || !b->top)
		return (NULL);
	current = b->top;
	max = b->top;
	while (current)
	{
		if (current->index > max->index)
			max = current;
		current = current->next;
	}
	return (max);
}

/*
** Optimized chunk initialization based on stack size
** Uses sqrt(n) approach for better performance
*/
static void	init_chunks(t_stack *a)
{
	if (a->size <= 3)
		a->chunk_size = 1;
	else if (a->size <= 5)
		a->chunk_size = 2;
	else if (a->size <= 50)
		a->chunk_size = (int)sqrt(a->size) + 1;
	else if (a->size <= 100)
		a->chunk_size = (int)sqrt(a->size) + 2;
	else
		a->chunk_size = (int)sqrt(a->size) + 3;
	if (a->chunk_size < 1)
		a->chunk_size = 1;
}

/*
** Pushes chunks from A to B in an optimized way
** Minimizes rotations by being smarter about chunk boundaries
*/
static void	push_chunks(t_stack *a, t_stack *b)
{
	int	max_index;
	int	chunk_num;

	chunk_num = 0;
	while (a->size > 0)
	{
		max_index = (chunk_num + 1) * a->chunk_size - 1;
		if (max_index >= a->size)
			max_index = a->size - 1;
		while (a->size > 0 && a->top->index <= max_index)
		{
			pb(a, b);
		}
		if (a->size > 0)
		{
			if (a->size > a->chunk_size / 2)
				ra(a);
			else
				rra(a);
		}
		chunk_num++;
	}
}

/*
** Restores elements from B back to A in optimal order
** Brings largest elements first and uses efficient rotations
*/
static void	restore_to_a(t_stack *a, t_stack *b)
{
	t_node	*max;

	while (b->size > 0)
	{
		max = find_max(b);
		if (!max)
			break ;
		bring_to_top(b, max);
		pa(a, b);
	}
}

/*
** Main chunk sort function
** Divides stack into chunks and sorts using stack operations
*/
void	chunk_sort(t_stack *a, t_stack *b)
{
	if (!a || a->size <= 1)
		return ;
	normalize_index(a);
	init_chunks(a);
	push_chunks(a, b);
	restore_to_a(a, b);
}
