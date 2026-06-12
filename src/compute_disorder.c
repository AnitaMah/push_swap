/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 11:57:53 by anmakhov          #+#    #+#             */
/*   Updated: 2026/06/12 11:58:19 by anmakhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	compute_disorder(int *arr, int size)
{
	int	total;
	int	i;
	int	j;
	int	mistakes;

	mistakes = 0;
	total = size * (size - 1) / 2;
	if (size <= 1)
		return (0.0);
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
				mistakes++;
		}
	}
	return ((double)mistakes / (double)total);
}
