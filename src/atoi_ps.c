/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:05:00 by anmakhov          #+#    #+#             */
/*   Updated: 2026/06/11 15:50:33 by anmakhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

/*
** Converts string to integer with error checking.
** Sets error to 1 if:
** - String is not a valid integer
** - Integer overflows/underflows (> INT_MAX or < INT_MIN)
** - Empty string
** Returns 0 on error (error flag will be set)
*/
int	ft_atoi_ps(const char *str, int *error)
{
	long	result;
	int		sign;
	int		i;

	*error = 0;
	if (!str || *str == '\0')
	{
		*error = 1;
		return (0);
	}
	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
	{
		*error = 1;
		return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result > INT_MAX || result * sign < INT_MIN)
		{
			*error = 1;
			return (0);
		}
		i++;
	}
	if (str[i] != '\0')
	{
		*error = 1;
		return (0);
	}
	return ((int)(result * sign));
}
