/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:14:25 by hznagui           #+#    #+#             */
/*   Updated: 2022/10/07 16:29:58 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	y;
	size_t	u;

	i = 0;
	u = 0;
	y = 0;
	if ((!dst && !dstsize))
		return (ft_strlen(src));
	while (src[y])
		y++;
	while (dst[u])
		u++;
	if (dstsize <= u)
		return (y + dstsize);
	else
	{
		while (i < dstsize - u - 1 && src[i] != '\0')
		{
			dst[u + i] = src[i];
			i++;
		}
		dst[u + i] = '\0';
		return (y + u);
	}
}
