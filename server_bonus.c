/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassaleh <hassaleh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:55:20 by hassaleh          #+#    #+#             */
/*   Updated: 2024/07/16 22:07:52 by hassaleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_track;

void	reciever(int sig_num, siginfo_t *info, void *ptr)
{
	static char	c;

	(void)ptr;
	g_track--;
	if (sig_num == SIGUSR1)
		c = 1 << g_track | c;
	if (g_track == 0)
	{
		write (1, &c, 1);
		g_track = 8;
		c = '\0';
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_sigaction = &reciever;
	sa.sa_flags = SA_SIGINFO;
	g_track = 8;
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause ();
}
