/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:39:19 by hznagui           #+#    #+#             */
/*   Updated: 2023/01/31 12:17:28 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void test(int type)
{
    static char *str;
    if(type == 30)
        str = ft_strjoin(str, "1");
    else if (type == 31)
        str = ft_strjoin(str, "0");
}
int main()
{
    ft_putnbr_fd(getpid(),1);
    ft_putchar_fd('\n',1);
    while(1){
        signal(SIGUSR1,test);
        signal(SIGUSR2,test);
    }
    return(0);
}
