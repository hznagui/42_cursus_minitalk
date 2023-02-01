/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:39:19 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/01 15:03:54 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    the_converter(int i)
{
    int the_rest;
    int base ;
    int ret;
    
    base = 1;
    ret = 0;
    while (i > 0)
    {
        the_rest = i % 10;
        ret = ret + (the_rest * base);
        base = base * 2;
        i = i / 10;
    }
    ft_putchar_fd(ret,1);
}
void test(int type, siginfo_t *info, void *context)
{
    static char *str;
    static int client_pid;
    (void)context;
    if(client_pid != info->si_pid)
    {
        if(str)
            free(str);
        str = NULL;
        client_pid = info->si_pid;
    }
    if(type == 30)
        str = ft_strjoin(str, "1");
    else if (type == 31)
        str = ft_strjoin(str, "0");
    if (ft_strlen(str) == 8)
    {
        the_converter(ft_atoi(str));
        if(str)
            free(str);
        str = NULL;
    }      
}
int main(int ac, char **av)
{
    (void)av;
    struct sigaction act;
    
    ft_putnbr_fd(getpid(),1);
    ft_putchar_fd('\n',1);
    act.sa_sigaction = test;
    act.sa_flags = SA_SIGINFO;

    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    // signal(SIGUSR1,test);
    // signal(SIGUSR2,test);
    while(1){
        pause();
    }
    return(0);
}
