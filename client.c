/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassaleh <hassaleh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:15:48 by hassaleh          #+#    #+#             */
/*   Updated: 2024/05/27 20:40:01 by hassaleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_convert(int pid, char *str)
{
	int	i;
	int	b;

	i = 0;
	while (str[i])
	{
		b = 7;
		while (b >= 0)
		{
			if ((str[i] & (1 << b)) > 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			b--;
			usleep(150);
		}
		i++;
	}
}

int	main(int ac, char *av[])
{
	if (ac != 3)
	{
		write(1, "ERROR: Wrong Arguments Amount\n", 30);
		return (0);
	}
	char_convert(ft_atoi(av[1]), av[2]);
	return (0);
}
