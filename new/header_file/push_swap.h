/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:02:38 by anmakhov          #+#    #+#             */
/*   Updated: 2026/06/15 13:59:32 by anmakhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

/*
** =========================================================
**                      STACK NODE
** =========================================================
*/

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

/*
** =========================================================
**                      STACK STRUCTURE
** =========================================================
*/

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;
	int				chunk_size;
	char			name;
}					t_stack;

typedef struct s_input
{
	int				*arr;
	int				size;
}					t_input;

/* =========================================================
** STACK OPERATIONS
** =========================================================
*/

/* Swap top 2 elements of stack A */
void				sa(t_stack *a);

/* Swap top 2 elements of stack B */
void				sb(t_stack *b);

/* Swap top 2 elements of both stacks */
void				ss(t_stack *a, t_stack *b);

/* Push top element from B to A */
void				pa(t_stack *a, t_stack *b);

/* Push top element from A to B */
void				pb(t_stack *a, t_stack *b);

/* Rotate stack A upwards */
void				ra(t_stack *a);

/* Rotate stack B upwards */
void				rb(t_stack *b);

/* Rotate both stacks upwards */
void				rr(t_stack *a, t_stack *b);

/* Reverse rotate stack A */
void				rra(t_stack *a);

/* Reverse rotate stack B */
void				rrb(t_stack *b);

/* Reverse rotate both stacks */
void				rrr(t_stack *a, t_stack *b);

/* =========================================================
** SORTING
** =========================================================
*/

/* Quick sort for array normalization */
void				quicksort(int *arr, int left, int right);

/* Convert stack values into normalized indexes */
void				normalize_index(t_stack *a);

/* Chunk-based sorting algorithm */
void				chunk_sort(t_stack *a, t_stack *b);

/* Move target node to top of stack efficiently */
void				bring_to_top(t_stack *stack, t_node *target);

/* Restore all elements from B back to A */
void				restore_to_a(t_stack *a, t_stack *b);

/* Find node with maximum index in stack B */
t_node				*find_max(t_stack *b);

/* Radix sort (bitwise sorting) */
void				radix_sort(t_stack *a, t_stack *b);

/*
** Simple selection sort (used for small stacks <= 3 or 5)
*/
void				selection_sort_adaptation(t_stack *a, t_stack *b);
/* Sort 2–3 elements */
void				sort_small(t_stack *a);

/* Sort 5 elements */
void				sort_five(t_stack *a, t_stack *b);

/* Convert stack to array (helper) */
int					*stack_to_array(t_stack *a);

/* Compute disorder level (0 sorted → 1 random) */
double				compute_disorder(int *arr, int size);

/* =========================================================
** CORE
** =========================================================
*/

/* Initialize stack structure */
void				init_stack(t_stack *stack, char name);

/* Check if stack A is sorted */
int					is_sorted(t_stack *a);

/* Main sorting dispatcher */
void				sort_stack(t_stack *a, t_stack *b);

/* Free entire stack */
void				free_stack(t_stack *a);

/* =========================================================
** PARSING
** =========================================================
*/

/* Parse argv into integer array */
int					*parse_args(int argc, char **argv, int *size);

/* Build stack from array */
int					stack_from_array(t_stack *a, int *arr, int size);

/* Validate numeric string */
int					is_valid_number(char *s);

/* Count arguments */
int					count_args(char **args);

/* Free args if split was used */
void				free_args_if_split(int argc, char **args);

/* Safe atoi with overflow check */
int					ft_atoi_ps(const char *str, int *error);
int					check_duplicates(int *array, int size);
void				sort_four_five(t_stack *a, t_stack *b, int size);
void				sort_three(t_stack *a);
void				sort_two(t_stack *a);

#endif
