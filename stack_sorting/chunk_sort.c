/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:07:09 by anmakhov          #+#    #+#             */
/*   Updated: 2026/06/12 13:24:39 by anmakhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

/*
** Finds max node in stack B.
*/
t_node	*find_max(t_stack *b)
{
	t_node	*cur;
	t_node	*max;

	if (!b || !b->top)
		return (NULL);
	cur = b->top;
	max = b->top;
	while (cur)
	{
		if (cur->index > max->index)
			max = cur;
		cur = cur->next;
	}
	return (max);
}

/*
** Defines chunk size depending on stack size.
*/
static void	init_chunks(t_stack *a)
{
	if (a->size <= 100)
		a->chunk_size = a->size / 5;
	else
		a->chunk_size = a->size / 11;
	if (a->chunk_size < 1)
		a->chunk_size = 1;
}

/*
** Pushes elements from A to B in chunks.
*/
static void	push_chunks(t_stack *a, t_stack *b)
{
	int	max;
	int	pushed;

	max = a->chunk_size;
	pushed = 0;
	while (a->size > 0)
	{
		if (a->top->index <= max)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
		if (pushed == max)
			max += a->chunk_size;
	}
}

/*
** Chunk sort main entry.
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
