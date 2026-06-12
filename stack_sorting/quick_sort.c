/*
** Lomuto partition scheme:
** Гарантовано ставить pivot на правильне місце і повертає його індекс.
*/
int	partition(int *arr, int left, int right)
{
	int	i;
	int	j;
	int	tmp;

	int pivot = arr[right]; // Беремо останній елемент як pivot
	i = left;
	j = left;
	while (j < right)
	{
		if (arr[j] < pivot)
		{
			// Міняємо місцями arr[i] та arr[j]
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
		}
		j++;
	}
	// Ставимо pivot на його фінальне місце
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
