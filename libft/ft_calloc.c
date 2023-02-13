/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:39:30 by hznagui           #+#    #+#             */
/*   Updated: 2022/10/31 15:40:14 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	*a;
	size_t	tsize;

	tsize = count * size;
	if (count != 0 && size != (tsize / count))
		return (0);
	a = malloc(tsize);
	if (!a)
		return (0);
	ft_memset(a, 0, tsize);
	return (a);
}
