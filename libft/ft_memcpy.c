/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:51:19 by hznagui           #+#    #+#             */
/*   Updated: 2022/10/29 00:04:06 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*p;
	char	*o;

	i = 0;
	if (!dst && !src)
		return (0);
	if (src == dst)
		return (dst);
	p = (char *)dst;
	o = (char *)src;
	while (i < n)
	{
		p[i] = o[i];
		i++;
	}
	return (p);
}
