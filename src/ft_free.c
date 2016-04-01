/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 16:54:53 by psaint-j          #+#    #+#             */
/*   Updated: 2016/04/01 14:35:27 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void		free_tab_2(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
}

void		free_tab(char ***tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free_tab_2(tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
}
