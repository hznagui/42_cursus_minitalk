/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:04:12 by hznagui           #+#    #+#             */
/*   Updated: 2022/10/12 18:31:59 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	size_t		p;
	char		*o;
	char		*u;

	if (!dst && !src)
		return (0);
	i = 1;
	p = 0;
	o = (char *)dst;
	u = (char *)src;
	if (dst > src)
	{
		while (i <= len)
		{
			o[len - i] = u[len - i];
			i++;
		}
	}
	else
	{
		ft_memcpy(o, u, len);
	}
	return (o);
}
