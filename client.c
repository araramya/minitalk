#include "minitalk.h"

void ft_sendmessage(int pid, char *str)
{
    int i;
    int shift;

    i = 0;
    while(str[i])
    {
        shift = 0;
        while (shift <= 7)
        {
            if((str[i] << shift) & 128)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            usleep(20);
            shift++;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    int pid;
    pid = ft_atoi(argv[1]);

    if(argc == 3)
        ft_sendmessage(pid, argv[2]);
}
