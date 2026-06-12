/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:07:15 by anmakhov          #+#    #+#             */
/*   Updated: 2026/06/12 13:07:29 by anmakhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_file/push_swap.h"

/*
** Skip whitespace characters
*/
static void	skip_spaces(const char *s, int *i)
{
	while (s[*i] == ' ' || (s[*i] >= 9 && s[*i] <= 13))
		(*i)++;
}

/*
** Handle optional sign
*/
static int	handle_sign(const char *s, int *i)
{
	int	sign;

	sign = 1;
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

/*
** Parse digits safely with overflow check
*/
static int	parse_digits(const char *s, int *i, int *error)
{
	long	result;

	result = 0;
	if (s[*i] < '0' || s[*i] > '9')
		return (*error = 1, 0);
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		result = result * 10 + (s[*i] - '0');
		if (result > 2147483647)
			return (*error = 1, 0);
		(*i)++;
	}
	return ((int)result);
}

/*
** Main safe atoi (push_swap version)
*/
int	ft_atoi_ps(const char *s, int *error)
{
	int	i;
	int	sign;
	int	value;

	i = 0;
	*error = 0;
	skip_spaces(s, &i);
	sign = handle_sign(s, &i);
	value = parse_digits(s, &i, error);
	if (*error)
		return (0);
	if (s[i] != '\0')
		return (*error = 1, 0);
	return (value * sign);
}
