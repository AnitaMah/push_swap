/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pasring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:43:41 by anmakhov          #+#    #+#             */
/*   Updated: 2026/06/15 13:43:53 by anmakhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

/*
** Helper to count words in a single split array.
*/
int	count_words_in_split(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	return (count);
}
