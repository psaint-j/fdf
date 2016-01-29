/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 17:34:12 by psaint-j          #+#    #+#             */
/*   Updated: 2015/02/17 18:16:09 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		len;

	len = ft_strlen(s2);
	i = 0;
	if (!s2 || n <= 0)
		return ((char *)s1);
	while (s1[i] && ((size_t)(i + len) <= n))
	{
		if (ft_strncmp(&s1[i], s2, len) == 0)
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
