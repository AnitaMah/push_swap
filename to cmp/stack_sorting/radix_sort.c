/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:07:04 by anmakhov          #+#    #+#             */
/*   Updated: 2026/06/15 13:45:27 by anmakhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

/*
** Pushes or rotates stack A depending on current bit.
*/
static void	handle_bit(t_stack *a, t_stack *b, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((a->top->index >> bit) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}

/*
** Returns number of bits needed for max index.
*/
static int	get_max_bits(t_stack *a)
{
	int		max;
	int		bits;
	t_node	*cur;

	if (!a || !a->top)
		return (0);
	cur = a->top;
	max = cur->index;
	while (cur)
	{
		if (cur->index > max)
			max = cur->index;
		cur = cur->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

/*
** Radix sorting main logic.
*/
void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	size;
	int	i;

	if (!a || !a->top)
		return ;
	max_bits = get_max_bits(a);
	size = a->size;
	i = 0;
	while (i < max_bits)
	{
		handle_bit(a, b, i, size);
		restore_to_a(a, b);
		i++;
	}
}
