/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassaleh <hassaleh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:55:31 by hassaleh          #+#    #+#             */
/*   Updated: 2024/07/16 22:44:11 by hassaleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	verifier(int signal)
{
	(void)signal;
	write(1, "\e[0;32m OK\n", 12);
}

void	char_convert(int pid, char *str)
{
	int	i;
	int	b;
	int	n;

	signal(SIGUSR1, verifier);
	i = 0;
	while (str[i])
	{
		b = 7;
		while (b >= 0)
		{
			if ((str[i] & (1 << b)) > 0)
				n = kill(pid, SIGUSR1);
			else
				n = kill(pid, SIGUSR2);
			b--;
			usleep(150);
		}
		i++;
	}
	if (n == -1)
	{
		write (1, "PID error\n", 11);
		exit(1);
	}
}

int	main(int ac, char *av[])
{
	int	pid;

	if (ac != 3)
	{
		write(1, "ERROR: Wrong Arguments Amount\n", 30);
		return (0);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		return (write (1, "Argument Error\n", 16), 1);
	char_convert(pid, av[2]);
	return (0);
}
