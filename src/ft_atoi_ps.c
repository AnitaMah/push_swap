/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:45:02 by anmakhov          #+#    #+#             */
/*   Updated: 2026/06/11 16:01:47 by anmakhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	*move_iter_after_space(const char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	return ((char *)str);
}

int	ft_atoi_ps(const char *str, int *error)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	*error = 0;
	str = move_iter_after_space(str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str == '\0')
		return (*error = 1, 0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (*error = 1, 0);
		n = n * 10 + (*str - '0');
		if ((n * sign) > 2147483647 || (n * sign) < -2147483648)
			return (*error = 1, 0);
		str++;
	}
	return ((int)(n * sign));
}
