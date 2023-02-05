/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:31:41 by hznagui           #+#    #+#             */
/*   Updated: 2023/02/05 18:57:12 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	unicode(int tmp)
{
	if ((tmp & 240) == 240)
		return (4);
	else if ((tmp & 224) == 224)
		return (3);
	else if ((tmp & 192) == 192)
		return (2);
	else if ((tmp & 128) == 128)
		return (1);
	else
		return (0);
}

void	ft_clean(int *timer, char **ret, int *index)
{
	*timer = 0;
	if (*ret)
		free(*ret);
	*ret = NULL;
	*index = 0;
}
