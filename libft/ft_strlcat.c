/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 17:49:58 by psaint-j          #+#    #+#             */
/*   Updated: 2014/11/20 17:54:40 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	lendst;
	int				lensrc;
	int				i;
	int				result;

	i = 0;
	lensrc = ft_strlen(src);
	lendst = ft_strlen(dst);
	result = size - lendst - 1;
	while (i < result)
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = '\0';
	if (size < lendst)
		return (lensrc + size);
	return (lendst + lensrc);
}
