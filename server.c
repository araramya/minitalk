#include "minitalk.h"
static t_message msg;

void get_str(int signum)
{
   char c;

      //  printf("hi\n");
       // printf(" signum %d\n", signum);
       // printf(" siguser1 %d\n", SIGUSR1);
       // printf(" siguser2 %d\n", SIGUSR2);

        if(signum == SIGUSR1)
        {
            //printf("1\n");
            msg.str[msg.i] = '1';
            msg.i++;
            //printf("%c\n", msg.str[msg.i]);
        }

        if(signum == SIGUSR2)
        {
           // printf("0\n");
            msg.str[msg.i] = '0';
            msg.i++;
          //  printf("%c\n", msg.str[msg.i]);
        }
         if(msg.i == 8)
         {
           // printf("%s\n", msg.str);
             c = ft_atoi_base(msg.str, "01");
           // printf("c = %d \n", c );
                write(1, &c, 1);
            msg.i = 0;
           // free(msg.str);
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
        {
            printf("ASENQ VOCH MALLOCIN ");
            exit(0);
        }
    msg.i = 0;
    while(1)
    {
        signal(SIGUSR1, get_str);
        signal(SIGUSR2, get_str);
       
    }
}