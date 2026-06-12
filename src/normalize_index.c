#include "../header_file/push_swap.h"

/*
** Assigns index based on how many smaller elements exist.
** (O(n^2) but perfectly fine for push_swap constraints)
*/
void	normalize_index(t_stack *a)
{
	t_node *i;
	t_node *j;
	int index;

	if (!a || !a->top)
		return ;

	i = a->top;
	while (i)
	{
		index = 0;
		j = a->top;
		while (j)
		{
			if (j->value < i->value)
				index++;
			j = j->next;
		}
		i->index = index;
		i = i->next;
	}
}
