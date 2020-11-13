#include <stdio.h>
#include <unistd.h>
#include  <signal.h>

/*void c_blocker(int sig)
{
	signal(sig, SIG_IGN);
	printf(" Pathetic.\nYou can't stop me.\n");
	signal(SIGINT, c_blocker);
	}*/

void main (void)
{
	int i = 10;

	signal(SIGINT, SIG_IGN);
	while (i >= 0)
	{
		printf("%i\n", i--);
		sleep(1);
	}
}
