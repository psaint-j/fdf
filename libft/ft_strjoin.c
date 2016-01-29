/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 19:49:32 by psaint-j          #+#    #+#             */
/*   Updated: 2015/04/03 04:48:17 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*chain;
	size_t		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	chain = (char *)malloc(sizeof(char) * (len + 1));
	if (chain == NULL)
		return (NULL);
	ft_strcpy((char *)chain, (char *)s1);
	ft_strcat((char *)chain, (char *)s2);
	chain[len] = 0;
	return (chain);
}
