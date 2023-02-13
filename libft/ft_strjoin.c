/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:29:38 by hznagui           #+#    #+#             */
/*   Updated: 2022/11/03 17:59:34 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_return(char *p, char const *s1, char const *s2)
{
	size_t	y;
	size_t	a;

	a = 0;
	y = 0;
	while (y < ft_strlen(s1))
	{
		p[y] = s1[y];
		y++;
	}
	while (a <= ft_strlen(s2))
	{
		p[y + a] = s2[a];
		a++;
	}
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!p)
		return (0);
	return (ft_return(p, s1, s2));
}
