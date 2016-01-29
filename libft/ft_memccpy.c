/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:49:16 by psaint-j          #+#    #+#             */
/*   Updated: 2015/03/02 20:46:28 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*p1;
	const char	*p2;
	size_t		i;

	if (!dst || !src || !n)
		return (NULL);
	i = 0;
	p1 = (char *)dst;
	p2 = (char *)src;
	while (i < n)
	{
		p1[i] = p2[i];
		if ((unsigned char)p1[i] == (unsigned char)c)
			return (p1 + i + 1);
		i++;
	}
	return (NULL);
}
