/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:26:04 by anmakhov          #+#    #+#             */
/*   Updated: 2026/06/12 11:37:31 by anmakhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

/*
** =========================
**      CORE LOGIC
** =========================
*/

/*
** Checks if stack A is sorted in ascending order
** Returns:
** 1 -> sorted
** 0 -> not sorted
*/
int	is_sorted(t_stack *a)
{
	t_node	*cur;

	if (!a || !a->top)
		return (1);
	cur = a->top;
	while (cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}
