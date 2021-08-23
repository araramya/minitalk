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
    if(argc != 3)
    {
        write(1, "ERROR: Usage client <PID> <MESSAGE>\n", 36);
        return (1);
    }
    int pid;
    pid = ft_atoi(argv[1]);
    ft_sendmessage(pid, argv[2]);
    return (0);
}
