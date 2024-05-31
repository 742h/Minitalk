/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassaleh <hassaleh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:55:20 by hassaleh          #+#    #+#             */
/*   Updated: 2024/05/29 15:30:47 by hassaleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_track;

void	reciever(int sig_num)
{
	static char	c;

	g_track--;
	if (sig_num == SIGUSR1)
		c = 1 << g_track | c;
	if (g_track == 0)
	{
		write (1, &c, 1);
		g_track = 8;
		c = '\0';
	}
}

int	main(void)
{
	int	pid;

	g_track = 8;
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	signal(SIGUSR1, reciever);
	signal(SIGUSR2, reciever);
	while (1)
		pause ();
}
