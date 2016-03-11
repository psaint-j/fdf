/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:27:44 by psaint-j          #+#    #+#             */
/*   Updated: 2016/03/11 15:52:27 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char *tmp1;
	char *tmp2;

	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	return (ft_strncmp(tmp1, tmp2, n));
}
