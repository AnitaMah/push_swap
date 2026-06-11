/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:06:30 by anmakhov          #+#    #+#             */
/*   Updated: 2026/06/11 15:06:31 by anmakhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** Restores elements from stack B back to stack A
** Brings largest elements first for optimal sorting
** Used by chunk_sort, radix_sort, and selection sort
*/
void	restore_to_a(t_stack *a, t_stack *b)
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
