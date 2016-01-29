/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 17:50:29 by psaint-j          #+#    #+#             */
/*   Updated: 2014/11/19 18:00:23 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*chain;
	size_t	i;

	i = 0;
	chain = (ft_strnew(len + 1));
	if (s == NULL || chain == NULL)
		return (NULL);
	while (i < len)
	{
		chain[i] = s[start];
		i++;
		start++;
	}
	return (chain);
}
