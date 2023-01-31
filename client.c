/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:39:12 by hznagui           #+#    #+#             */
/*   Updated: 2023/01/31 13:27:30 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
int main(int argc,char **argv)
{
    int i = 2 ;
    int a ;
    int k;
	
    while (argv[i] != '\0')
    {
        a = 0;
        while (argv[i][a] != '\0')
        {
        	k = 0;
            while (k < 8)
            {
        		usleep(5000);
            	if ((argv[i][a] & 128) == 128)
            		kill(ft_atoi(argv[1]), SIGUSR1);
				else
            		kill(ft_atoi(argv[1]), SIGUSR2);
				argv[i][a] = argv[i][a] << 1;
            	k++;
            }
			a++; 
        }
        i++;
    }
}