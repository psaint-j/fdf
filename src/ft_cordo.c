/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cordo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:47:46 by psaint-j          #+#    #+#             */
/*   Updated: 2016/03/14 15:09:07 by psaint-j         ###   ########.fr       */
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

void	draw_map(t_env s, t_bresenham bres)
{
	int		w_size;
	int		h_size;

	h_size = 250;
	w_size = 150;
	bres.x = -s.x + w_size;
	bres.y = s.y + h_size;
	bres.x1 = -s.x1 + w_size;
	bres.y1 = s.y1 + h_size;
	draw_line(s, bres);
	bres.x = -s.x + w_size;
	bres.y = s.y + h_size;
	bres.x1 = -s.x3 + w_size;
	bres.y1 = s.y3 + h_size;
	draw_line(s, bres);
	bres.x = -s.x3 + w_size;
	bres.y = s.y3 + h_size;
	bres.x1 = -s.x2 + w_size;
	bres.y1 = s.y2 + h_size;
	draw_line(s, bres);
	bres.x = -s.x2 + w_size;
	bres.y = s.y2 + h_size;
	bres.x1 = -s.x1 + w_size;
	bres.y1 = s.y1 + h_size;
	draw_line(s, bres);
}

t_env	init_point(t_env s)
{
	s.x = (s.e_y - s.e_x);
	s.y = ((s.e_y + s.e_x) / 2) - find_z(s, 0) * C1;
	s.x1 = (s.e_y - (s.e_x + MARGIN));
	s.y1 = (((s.e_x + MARGIN) + s.e_y) / 2) - find_z(s, 1) * C1;
	s.x3 = ((s.e_y + MARGIN) - s.e_x);
	s.y3 = ((s.e_x + (s.e_y + MARGIN)) / 2) - find_z(s, 3) * C1;
	s.x2 = ((s.e_y + MARGIN) - (s.e_x + MARGIN));
	s.y2 = (((s.e_x + MARGIN) + (s.e_y + MARGIN)) / 2) - find_z(s, 2) * C1;
	return (s);
}
