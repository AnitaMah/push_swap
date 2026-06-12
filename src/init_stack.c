/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:01:36 by anmakhov          #+#    #+#             */
/*   Updated: 2026/06/12 13:59:24 by anmakhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

/*
** Initializes stack structure:
** - top = NULL
** - bottom = NULL
** - size = 0
** - chunk_size = 0
** - name = 'a' or 'b'
*/
void	init_stack(t_stack *stack, char name)
{
	if (!stack)
		return ;
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	stack->chunk_size = 0;
	stack->name = name;
}
