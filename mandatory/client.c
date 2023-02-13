/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:39:12 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/06 12:42:25 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	the_sender(char c, int server_id)
{
	int	k;

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
}

int	main(int argc, char **argv)
{
	int		i;
	int		a;
	int		server_id;
	char	c;

	i = 2;
	if (argc != 3)
		exit (1);
	while (argv[i] != '\0')
	{
		a = 0;
		server_id = ft_atoi(argv[1]);
		while (argv[i][a] != '\0')
		{
			c = argv[2][a];
			the_sender(c, server_id);
			a++;
		}
		i++;
	}
}
