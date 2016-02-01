/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:03:37 by psaint-j          #+#    #+#             */
/*   Updated: 2016/02/01 16:05:21 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_var	*init_tab(char *str, t_var *e)
{
	e->tab_tmp = ft_strsplit(str, ' ');
	while (e->tab_tmp != '\0')
	{
	//	e->map[e->j][e->i] = e->tab_tmp[e->i][0];
		e->i++;
	}
	return (e);
}

t_var	*init_var(t_var *e)
{
	e->i = 0;
	e->j = 0;
	e->xmax = 0;
	e->ymax = 0;
	return(e);
}

void	ft_tabstr(char **tab, int y, char ***map)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		map[y][i] = tab[i];
		i++;
	}
}
void	ft_print_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putstr("\t");
		i++;
	}
}
