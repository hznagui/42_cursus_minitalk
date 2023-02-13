/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:48:32 by hznagui           #+#    #+#             */
/*   Updated: 2022/10/29 20:55:00 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_here(char s1, char const *set)
{
	size_t	k;

	k = 0;
	while (set[k])
	{
		if (set[k] == s1)
			return (1);
		k++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	l;
	size_t	o;
	char	*p;

	if (!s1 || !set)
		return (0);
	o = 0;
	l = ft_strlen(s1);
	while (s1[o] && is_here(s1[o], set))
		o++;
	if (o == l)
		return (ft_strdup(""));
	while (is_here(s1[l - 1], set))
		l--;
	p = ft_substr(s1, o, l - o);
	return (p);
}
