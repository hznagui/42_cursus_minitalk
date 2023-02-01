/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:39:12 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/01 15:04:02 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
int main(int argc,char **argv)
{
    int i = 2 ;
    int a ;
    int k;
    int server_id;
    char c;
	
    if(argc != 3)
        exit (1);
    while (argv[i] != '\0')
    {
        a = 0;
        server_id = ft_atoi(argv[1]);
        while (argv[i][a] != '\0')
        {
            c = argv[2][a];
        	k = 0;
            while (k < 8)
            {
            	if ((c & 128))
            		kill(server_id, SIGUSR1);
				else
            		kill(server_id, SIGUSR2);
				c <<= 1;
        		usleep(500);
            	k++;
            }
			a++; 
        }
        i++;
    }
}