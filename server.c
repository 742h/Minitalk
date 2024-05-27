/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassaleh <hassaleh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:16:02 by hassaleh          #+#    #+#             */
/*   Updated: 2024/05/27 19:58:52 by hassaleh         ###   ########.fr       */
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
	g_track = 8;
	printf("%d\n", getpid());
	signal(SIGUSR1, reciever);
	signal(SIGUSR2, reciever);
	while (1)
		pause ();
}
