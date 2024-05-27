/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassaleh <hassaleh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:52:30 by hassaleh          #+#    #+#             */
/*   Updated: 2024/05/27 19:59:23 by hassaleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	over_flow(int sign)
{
	if (sign == 1)
		return (-1);
	else
		return (0);
}

int	result_check(long long result, char *str)
{
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
	{
		if (result > (2147483647))
		{
			over_flow(sign);
			return (over_flow(sign));
		}
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * sign);
}

int	ft_atoi(const char *str)
{
	long long	result;
	int			i;

	i = 0;
	result = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (result_check(result, (char *)str + i));
}
