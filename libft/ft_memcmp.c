/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:01:49 by hznagui           #+#    #+#             */
/*   Updated: 2022/10/16 18:25:36 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*l;
	size_t			i;

	i = 0;
	p = (unsigned char *)s1;
	l = (unsigned char *)s2;
	while (i < n)
	{
		if (p[i] != l[i])
			return (p[i] - l[i]);
		i++;
	}
	return (0);
}
