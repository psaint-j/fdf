/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cordo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:47:46 by psaint-j          #+#    #+#             */
/*   Updated: 2016/04/01 15:25:28 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		find_z3(t_env s)
{
	if (s.map[s.y_tab + 1] != NULL)
	{
		if (s.map[s.y_tab + 1][s.x_tab])
			return (ft_atoi(s.map[s.y_tab + 1][s.x_tab]));
	}
	return (0);
}

int		find_z(t_env s, int z)
{
	if (z == 0)
	{
		if (s.map[s.y_tab][s.x_tab])
			return (ft_atoi(s.map[s.y_tab][s.x_tab]));
	}
	if (z == 1)
	{
		if (s.map[s.y_tab][s.x_tab + 1])
			return (ft_atoi(s.map[s.y_tab][s.x_tab + 1]));
	}
	if (z == 2)
	{
		if (s.map[s.y_tab + 1] != NULL)
		{
			if (s.map[s.y_tab + 1][s.x_tab + 1])
				return (ft_atoi(s.map[s.y_tab + 1][s.x_tab + 1]));
		}
	}
	if (z == 3)
		return (find_z3(s));
	return (0);
}

t_env	center_map(t_env s)
{
	s.w_size = (WIDTH - (s.margin * s.xmax)) / 2;
	s.h_size = (HEIGHT - (s.margin * s.ymax)) / 10;
	return (s);
}

void	draw_map(t_env s, t_bresenham bres)
{
	bres.x = -s.x;
	bres.y = s.y;
	bres.x1 = -s.x1;
	bres.y1 = s.y1;
	draw_line(s, bres);
	bres.x = -s.x;
	bres.y = s.y;
	bres.x1 = -s.x3;
	bres.y1 = s.y3;
	draw_line(s, bres);
	bres.x = -s.x3;
	bres.y = s.y3;
	bres.x1 = -s.x2;
	bres.y1 = s.y2;
	draw_line(s, bres);
	bres.x = -s.x2;
	bres.y = s.y2;
	bres.x1 = -s.x1;
	bres.y1 = s.y1;
	draw_line(s, bres);
}

t_env	init_point(t_env s)
{
	s.x = (s.e_y - s.e_x);
	s.y = ((s.e_y + s.e_x) / 2) - find_z(s, 0) * C1;
	s.x1 = (s.e_y - (s.e_x + s.margin));
	s.y1 = (((s.e_x + s.margin) + s.e_y) / 2) - find_z(s, 1) * C1;
	s.x3 = ((s.e_y + s.margin) - s.e_x);
	s.y3 = ((s.e_x + (s.e_y + s.margin)) / 2) - find_z(s, 3) * C1;
	s.x2 = ((s.e_y + s.margin) - (s.e_x + s.margin));
	s.y2 = (((s.e_x + s.margin) + (s.e_y + s.margin)) / 2) - find_z(s, 2) * C1;
	return (s);
}
