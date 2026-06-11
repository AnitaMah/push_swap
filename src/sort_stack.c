/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03                                #+#    #+#             */
/*   Updated: 2026/06/11                                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** =========================
**      SMALL SORT
** =========================
*/

static void	sort_small(t_stack *a)
{
	if (a->size == 2 && a->top->value > a->top->next->value)
		sa(a);
	else if (a->size == 3)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
		if (a->top->next->value > a->bottom->value)
		{
			rra(a);
			if (a->top->value > a->top->next->value)
				sa(a);
		}
	}
}

/*
** =========================
**      MEDIUM DISORDER
** =========================
*/

static void	sort_medium(t_stack *a, t_stack *b)
{
	chunk_sort(a, b);
}

/*
** =========================
**      HIGH DISORDER
** =========================
*/

static void	sort_large(t_stack *a, t_stack *b)
{
	radix_sort(a, b);
}

/*
** =========================
**      MAIN DISPATCHER
** =========================
*/

void	sort_stack(t_stack *a, t_stack *b)
{
	double disorder;

	if (!a || a->size <= 1 || is_sorted(a))
		return ;
	if (a->size <= 3)
	{
		sort_small(a);
		return ;
	}
	disorder = compute_disorder(a);
	if (disorder < 0.2)
		sort_small(a);
	else if (disorder < 0.5)
		sort_medium(a, b);
	else
		sort_large(a, b);
}
