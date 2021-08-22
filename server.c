#include "minitalk.h"
static t_message msg;

void get_str(int signum)
{
   char c;

        if(signum == SIGUSR1)
        {
            msg.str[msg.i] = '1';
            msg.i++;
        }
        else if(signum == SIGUSR2)
        {
            msg.str[msg.i] = '0';
            msg.i++;
        }
         if(msg.i == 8)
         {
           
             c = ft_atoi_base(msg.str, "01");
        
                write(1, &c, 1);
                msg.i = 0;           
         }
    
}

int main()
{
    int PID;
    PID = getpid();
    write(1, "Server PID: ", 12);
    ft_putnbr_fd(PID, 1);
    write(1,"\n", 1); 
    msg.str = (char *)malloc(8);
    if(!msg.str)
        exit(1);
    msg.i = 0;
    while(1)
    {
        signal(SIGUSR1, get_str);
        signal(SIGUSR2, get_str);
    }
}