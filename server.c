#include "minitalk.h"

int track;

void reciever(int sig_num)
{
	static char c;

	track--;
	if(sig_num == SIGUSR1)
		c = 1 << track | c;
	if (track == 0)
	{
		write (1, &c, 1);
		track = 8;
		c = '\0';
	}
}

int main(void)
{
	track = 8;
	printf("%d\n", getpid());
	signal(SIGUSR1, reciever);
	signal(SIGUSR2, reciever);
	while(1)
		pause();
}
