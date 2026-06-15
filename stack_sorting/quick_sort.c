/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:46:10 by anmakhov          #+#    #+#             */
/*   Updated: 2026/06/15 13:46:48 by anmakhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Lomuto partition scheme:
** Гарантовано ставить pivot на правильне місце і повертає його індекс.
*/
int	partition(int *arr, int left, int right)
{
	int	i;
	int	j;
	int	tmp;
	int	pivot;

	pivot = arr[right];
	i = left;
	j = left;
	while (j < right)
	{
		if (arr[j] < pivot)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
		}
		j++;
	}
	tmp = arr[i];
	arr[i] = arr[right];
	arr[right] = tmp;
	return (i);
}

void	quicksort(int *arr, int left, int right)
{
	int	pivot_index;

	if (left >= right)
		return ;
	pivot_index = partition(arr, left, right);
	quicksort(arr, left, pivot_index - 1);
	quicksort(arr, pivot_index + 1, right);
}
