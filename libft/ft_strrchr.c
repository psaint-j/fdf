/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 10:36:31 by psaint-j          #+#    #+#             */
/*   Updated: 2014/11/19 17:51:33 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	char	cc;

	i = ft_strlen(s);
	cc = (char)c;
	while (s[i] != s[0] && s[i] != cc)
		i--;
	if (s[i] == cc)
		return ((char *)s + i);
	return (NULL);
}
