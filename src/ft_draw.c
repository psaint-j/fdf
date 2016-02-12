/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:03:06 by psaint-j          #+#    #+#             */
/*   Updated: 2016/02/12 12:52:18 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"
#define U s.key_up
#define D s.key_down

void	ft_line(int x1, int x2, int y1, int y2, void *win, 		void *mlx)
{
	int 	dy;
	int		dx;
	int		e;

	dy = (y2 - y1) * 2;
	e = x1				 - x2;
	dx = e * 2;
	while (x1 <= x2)
	{
		mlx_pixel_put(mlx, win, x1, y1, 0x00FFFFFF);
		x1++;
		if ((e = e - dy) <= 0)
		{
			y1++;
			e = e + dx;
		}
	}
}

void	ft_draw_pixel(t_env s)
{
	s.key_up = 3;
	s.key_down = 3;

	while (s.map[s.x][s.y])
	{
		while (s.map[s.x])
		{
			//s.i = ft_atoi(s.map[s.x][s.y]);
			//if (s.i <= 0)
			//{
			while (s.j < MARGIN)
			{
				s.isoY = (s.e_x - s.e_y);
				s.isoX = ((s.e_x + s.e_y)/2);
				mlx_pixel_put(s.mlx, s.win, s.j + s.isoY + WIDTH/3, s.isoX, 0xFFFFF);
				mlx_pixel_put(s.mlx, s.win, s.isoY + WIDTH/3, s.isoX + s.j, 0xFFFFF);
				//other side
				mlx_pixel_put(s.mlx, s.win, s.j + s.isoY + WIDTH/3, s.isoX + MARGIN, 0xFFFFF);
				mlx_pixel_put(s.mlx, s.win, s.isoY + WIDTH/3 + MARGIN, s.isoX + s.j, 0xFFFFF);
				s.j++;
			}
			s.j = 0;
			/*	}
				else
				{
				while (s.j < MARGIN)
				{
				mlx_pixel_put(s.mlx, s.win, s.j + s.e_y + WIDTH/U, s.e_x, 0xFF0000);
				mlx_pixel_put(s.mlx, s.win, s.e_y + WIDTH/U, s.e_x + s.j, 0xFF0000);
			//other side
			mlx_pixel_put(s.mlx, s.win, s.j + s.e_y + WIDTH/U, s.e_x + MARGIN, 0xFF0000);
			mlx_pixel_put(s.mlx, s.win, s.e_y + WIDTH/U + MARGIN, s.e_x + s.j, 0xFF0000);
			s.j++;
			}
			s.j = 0;
			}*/
			s.x++;
			s.e_x = s.e_x + (MARGIN);
		}
		s.e_x = 0;
		s.x = 0;
		s.y++;
		s.e_y = s.e_y + (MARGIN);
	}
}
