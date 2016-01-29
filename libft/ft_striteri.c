/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 16:50:18 by psaint-j          #+#    #+#             */
/*   Updated: 2014/11/17 12:08:30 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int size;
	unsigned int i;

	i = 0;
	size = ft_strlen(s);
	while (i < size)
	{
		(*f)(i, s);
		s++;
		i++;
	}
}
