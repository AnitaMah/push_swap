/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2026/06/11 15:05:00 by anmakhov          #+#    #+#             */
/*   Updated: 2026/06/11 15:50:33 by anmakhov         ###   ########.fr       */
=======
/*   Created: 2026/06/11 14:45:02 by anmakhov          #+#    #+#             */
/*   Updated: 2026/06/11 14:45:37 by anmakhov         ###   ########.fr       */
>>>>>>> refs/remotes/origin/main
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
<<<<<<< HEAD
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
=======
	*error = 0;
	str = move_iter_after_space(str);
	if (*str == '-' || *str == '+')
>>>>>>> refs/remotes/origin/main
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
