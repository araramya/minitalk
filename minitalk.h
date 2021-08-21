#ifndef MINITALK_H
#define MINITALK_H
#include <stdio.h> // delete after
#include <signal.h>
#include <unistd.h>
#include "libft.h"
typedef struct s_message
{
    char *str;
    int i;
}             t_message;
int		ft_atoi_base(char *str, char *base);
#endif
// void	ft_putnbr_fd(int n);
// long	ft_atoi(const char *str);