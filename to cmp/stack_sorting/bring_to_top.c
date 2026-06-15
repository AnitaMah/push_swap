/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_to_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:05:15 by anmakhov          #+#    #+#             */
/*   Updated: 2026/06/15 13:45:53 by anmakhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

/*
** Counts operations needed to bring a node to top using rotate
** Returns positive for rotate, negative for reverse rotate
*/
static int	count_operations_to_top(t_stack *stack, t_node *target)
{
	t_node	*current;
	int		pos_from_top;
	int		pos_from_bottom;

	if (!stack || !target)
		return (0);
	pos_from_top = 0;
	current = stack->top;
	while (current && current != target)
	{
		pos_from_top++;
		current = current->next;
	}
	if (!current)
		return (0);
	pos_from_bottom = stack->size - pos_from_top;
	if (pos_from_top <= pos_from_bottom)
		return (pos_from_top);
	return (-pos_from_bottom);
}

/*
** Brings target node to the top of stack using appropriate operations
** Uses stack->name ('a' or 'b') to dynamically choose between ra/rb and rra/rrb
*/
void	bring_to_top(t_stack *stack, t_node *target)
{
	int	ops;

	if (!stack || !target)
		return ;
	ops = count_operations_to_top(stack, target);
	if (ops > 0)
	{
		while (ops > 0)
		{
			if (stack->name == 'a')
				ra(stack);
			else
				rb(stack);
			ops--;
		}
	}
	else if (ops < 0)
	{
		ops = -ops;
		while (ops > 0)
		{
			if (stack->name == 'a')
				rra(stack);
			else
				rrb(stack);
			ops--;
		}
	}
}
