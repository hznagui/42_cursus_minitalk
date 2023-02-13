/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:29:55 by hznagui           #+#    #+#             */
/*   Updated: 2022/11/03 17:16:12 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	a;
	char	*o;

	a = 0;
	if (!s || !f)
		return (0);
	o = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!o)
		return (0);
	while (a < ft_strlen(s))
	{
		o[a] = f(a, s[a]);
		a++;
	}
	o[a] = '\0';
	return (o);
}
