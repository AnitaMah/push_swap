/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:01:53 by anmakhov          #+#    #+#             */
/*   Updated: 2026/06/11 15:01:56 by anmakhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** =========================
**      NODE OPS
** =========================
*/
static t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

static void	add_back(t_stack *a, t_node *node)
{
	if (!a->top)
	{
		a->top = node;
		a->bottom = node;
	}
	else
	{
		a->bottom->next = node;
		node->prev = a->bottom;
		a->bottom = node;
	}
	a->size++;
}

/*
** =========================
**      CHECKERS
** =========================
*/
static int	has_duplicate(t_stack *a, int value)
{
	t_node	*cur;

	cur = a->top;
	while (cur)
	{
		if (cur->value == value)
			return (1);
		cur = cur->next;
	}
	return (0);
}

/*
** =========================
**      MAIN PARSER
** =========================
*/
int	parse_args(t_stack *a, char **argv)
{
	int		i;
	int		value;
	int		error;
	t_node	*node;

	i = 0;
	while (argv[i])
	{
		value = ft_atoi_ps(argv[i], &error);
		if (error)
			return (0);
		if (has_duplicate(a, value))
			return (0);
		node = new_node(value);
		if (!node)
			return (0);
		add_back(a, node);
		i++;
	}
	return (1);
}
