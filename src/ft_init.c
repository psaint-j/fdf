/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:03:37 by psaint-j          #+#    #+#             */
/*   Updated: 2016/02/02 17:03:44 by psaint-j         ###   ########.fr       */
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

void		print_mlx(t_env env, char **map, int x)
{
	int		y;
	int		tmp_x;
	int		tmp_y;
	int		e_x;
	int		e_y;

	y  = 0;
	e_y = 0;
	e_x = 0;
	while (map[y])
	{
		tmp_y = y + e_y;
		tmp_x = x + e_x;
		//mlx_pixel_put(env.mlx, env.win, x, y, 0xFFFFFF);
		mlx_pixel_put(env.mlx, env.win, x + 250, y + 350, 0xFFFFFF);
		//ft_put_pixel(env, x, tmp_y, map[y]);
		y++;
		e_x = e_x + 10;
		e_y = e_y + 10;
	}
	y = 0;
}
