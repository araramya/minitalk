#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
long	ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);

typedef struct s_message
{
    char *str;
    int i;
}             t_message;
int		ft_atoi_base(char *str, char *base);
#endif
