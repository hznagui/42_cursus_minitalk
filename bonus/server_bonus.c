/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:39:19 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/05 20:16:38 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	continue_func(int str, int timer, char *ret, int index)
{
}

void	unicode_handler(int str)
{
	static int	timer;
	static char	*ret;
	static int	index;

	if (str == -1)
		ft_clean(&timer, &ret, &index);
	else if (!unicode(str) && !timer)
		ft_putchar_fd(str, 1);
	else if (unicode(str) && !timer)
	{
		timer = unicode(str) - 1;
		ret = malloc ((unicode(str) + 1) * sizeof(char));
		if (!(ret))
			exit(1);
		ret[index++] = str;
	}
	else
	{
		timer--;
		ret[index++] = str;
		if (!timer)
		{
			ret[index] = '\0';
			ft_putstr_fd(ret, 1);
			ft_clean(&timer, &ret, &index);
		}
	}
}

int	the_converter(int i, int client_pid)
{
	int	the_rest;
	int	base;
	int	ret;

	base = 1;
	ret = 0;
	while (i > 0)
	{
		the_rest = i % 10;
		ret = ret + (the_rest * base);
		base = base * 2;
		i = i / 10;
	}
	if (!ret)
		kill(client_pid, SIGUSR1);
	return (ret);
}

void	test(int type, siginfo_t *info, void *context)
{
	static char	*str;
	static char	*tmp;
	static int	client_pid;

	(void)context;
	if (client_pid != info->si_pid)
	{
		if (str)
			free(str);
		str = NULL;
		client_pid = info->si_pid;
		unicode_handler(-1);
	}
	if (type == 30)
		str = ft_strjoin(str, "1");
	else if (type == 31)
		str = ft_strjoin(str, "0");
	if (ft_strlen(str) == 8)
	{
		unicode_handler(the_converter(ft_atoi(str), client_pid));
		if (str)
			free(str);
		str = NULL;
	}
}

int	main(void)
{
	struct sigaction	act;

	act.sa_sigaction = test;
	act.sa_flags = SA_SIGINFO;
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
