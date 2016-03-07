/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cordo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:47:46 by psaint-j          #+#    #+#             */
/*   Updated: 2016/03/07 15:50:11 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	{
		if (s.map[s.y_tab + 1] != NULL)
		{
			if (s.map[s.y_tab + 1][s.x_tab])
				return (ft_atoi(s.map[s.y_tab + 1][s.x_tab]));
		}
	}
	return (0);
}

t_env	init_point(t_env s)
{
	s.x = (s.e_y - s.e_x);
	s.y = ((s.e_y + s.e_x) / 2) - find_z(s, 0) * 5;
	s.x1 = (s.e_y - (s.e_x + MARGIN));
	s.y1 = (((s.e_x + MARGIN) + s.e_y) / 2) - find_z(s, 1) * 5;
	s.x3 = ((s.e_y + MARGIN) - s.e_x);
	s.y3 = ((s.e_x + (s.e_y + MARGIN)) / 2) - find_z(s, 3) * 5;
	s.x2 = ((s.e_y + MARGIN) - (s.e_x + MARGIN));
	s.y2 = (((s.e_x + MARGIN) + (s.e_y + MARGIN)) / 2) - find_z(s, 2) * 5;
	return (s);
}
