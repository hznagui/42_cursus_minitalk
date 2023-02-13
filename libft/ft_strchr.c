/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:53:13 by hznagui           #+#    #+#             */
/*   Updated: 2022/10/31 15:49:03 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		o;
	char	*u;

	u = (char *)s;
	i = 0;
	o = ft_strlen(s);
	while (i <= o)
	{
		if (s[i] == (char)c)
			return (u + i);
		i++;
	}
	return (0);
}
