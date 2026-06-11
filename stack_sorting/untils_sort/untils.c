/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   untils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:35:28 by anmakhov          #+#    #+#             */
/*   Updated: 2026/06/11 15:36:33 by anmakhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	bring_to_top(t_stack *stack, t_node *target)
{
	int		pos;
	int		size;
	t_node	*tmp;

	if (!stack || !stack->top || !target)
		return ;
	pos = 0;
	size = stack->size;
	tmp = stack->top;
	while (tmp != target)
	{
		tmp = tmp->next;
		pos++;
	}
	// rotate direction
	if (pos <= size / 2)
	{
		while (stack->top != target)
			ra(stack);
	}
	else
	{
		while (stack->top != target)
			rra(stack);
	}
}
