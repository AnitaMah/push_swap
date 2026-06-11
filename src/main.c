/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:01:46 by anmakhov          #+#    #+#             */
/*   Updated: 2026/06/11 15:03:43 by anmakhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	init_stack(&a);
	init_stack(&b);
	if (!parse_args(&a, argv + 1))
		return (write(2, "Error\n", 6), 1);
	if (is_sorted(&a))
		return (0);
	sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
