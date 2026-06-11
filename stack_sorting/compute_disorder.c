/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:25:44 by anmakhov          #+#    #+#             */
/*   Updated: 2026/06/11 15:25:45 by anmakhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

double	compute_disorder(t_stack *a)
{
	t_node	*i;
	t_node	*j;
	int		mistakes;
	int		total_pairs;

	if (!a || a->size < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = a->size * (a->size - 1) / 2;
	i = a->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->index > j->index)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return ((double)mistakes / total_pairs);
}
