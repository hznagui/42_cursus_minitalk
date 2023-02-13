/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:39:12 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/06 13:16:14 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	the_sender(char *c, int server_id)
{
	int	k;

	k = 0;
	while (k < 8)
	{
		if ((*c & 128))
			kill(server_id, SIGUSR1);
		else
			kill(server_id, SIGUSR2);
		*c <<= 1;
		usleep(500);
		k++;
	}
}

void	sending_null(int server_id)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(server_id, SIGUSR2);
		usleep(500);
		i++;
	}
}

void	test(int type)
{
	(void)type;
	ft_putstr_fd("the message have been sended", 1);
	exit (0);
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
			the_sender(&c, server_id);
			a++;
		}
		i++;
	}
	signal(SIGUSR1, test);
	sending_null(server_id);
}
