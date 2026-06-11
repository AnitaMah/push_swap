/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   untils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2026/06/11 15:35:28 by anmakhov          #+#    #+#             */
/*   Updated: 2026/06/11 15:36:33 by anmakhov         ###   ########.fr       */
=======
/*   Created: 2026/06/11 15:06:00 by anmakhov          #+#    #+#             */
/*   Updated: 2026/06/11 15:06:01 by anmakhov         ###   ########.fr       */
>>>>>>> refs/remotes/origin/main
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

<<<<<<< HEAD
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
=======
/* Placeholder utility functions for future sorting utilities */
/* Currently empty - can be extended with additional helper functions */
>>>>>>> refs/remotes/origin/main
