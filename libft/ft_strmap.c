/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 11:14:42 by psaint-j          #+#    #+#             */
/*   Updated: 2015/01/13 15:16:43 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew_new(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	str[size] = '\0';
	return (str);
}

char		*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*p;

	if (!(s && f))
		return (NULL);
	len = ft_strlen(s);
	p = ft_strnew_new(len);
	if (!p)
		return (NULL);
	while (len--)
		*(p + len) = f(*(s + len));
	return (p);
}
