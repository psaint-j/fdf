/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:03:06 by psaint-j          #+#    #+#             */
/*   Updated: 2016/02/22 18:05:20 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"
#define U s.key_up
#define D s.key_down


void	ft_line2(int x1, int y1, int x2, int y2, t_env all)
{
	int dx;
	int dy;
	int	e;

	dx = x2 - x1;
	dy = y2 - y1;
	if (	dx != 0)
	{
		if (dx > 0)
		{
			if (dy != 0)
			{
				if (dy > 0)
				{
					if (dx >= dy)
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while (x1 != x2)
						{
							mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
							if ((e = e - dy) < 0)
							{
								y1 = y1 + 1;
								e = e + dx;
							}
							++x1;
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while (++y1 != y2)
						{
							mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
							if ((e = e - dx) < 0)
							{
								x1 = x1 + 1;
								e = e + dy;
							}
						}
					}
				}
				else
				{
					if (dx >= -dy)
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while ((x1 = x1 + 1) != x2)
						{
							mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
							if ((e = e + dy) < 0)
							{
								y1 = y1 - 1;
								e = e + dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while ((y1 = y1 - 1) != y2)
						{
							mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
							if ((e = e + dx) < 0)
							{
								x1 = x1 + 1;
								e = e + dy;
							}
						}
					}
				}
			}
			else
			{
				while ((x1 = x1 + 1) != x2)
					mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
			}
		}
		else
		{
			if ((dy = y2 - y1) != 0)
			{
				if (dy > 0)
				{
					if (-dx >= dy)
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while ((x1 = x1 - 1) != x2)
						{
							mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
							if ((e = e + dy) != 0)
							{
								y1 = y1 + 1;
								e = e + dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while ((y1 = y1 + 1) != y2)
						{
							mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
							if ((e = e + dx) != 0)
							{
								x1 = x1 - 1;
								e = e + dy;
							}
						}
					}
				}
				else
				{
					if (dx <= dy)
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while ((x1  = x1 - 1) != x2)
						{
							mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
							if ((e = e - dy) >= 0)
							{
								y1 = y1 - 1;
								e = e + dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while ((y1  = y1 - 1) != y2)
						{
							mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
							if ((e = e - dx) >= 0)
							{
								x1 = x1 - 1;
								e = e + dy;
							}
						}
					}
				}
			}
			else // dy = 0 and dx < 0
			{
				while ((x1 = x1 - 1) != x2)
					mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);					
			}
		}
	}
	else // dx = 0
	{
		if ((dy = y2 - y1) != 0)
		{
			if (dy > 0)
			{
				while ((y1 = y1 + 1) != y2)
					mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
			}
			else // dy < 0 and dx = 0
			{
				while ((y1 = y1 - 1) != y2)
					mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
			}
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
			//while (s.j < MARGIN)
			//{
			s.isoY = (s.e_y - s.e_x);
			s.isoX = ((s.e_x + s.e_y)/2);
			ft_line2(s.isoY + 250, s.isoX + 50, s.isoY + 270, s.isoX + 60, s);
			ft_line2(s.isoY + 270, s.isoX + 40, s.isoY + 250, s.isoX + 50, s);
			//mlx_pixel_put(s.mlx, s.win, s.isoY + WIDTH/3, s.isoX, 0xFFFFF);
			//mlx_pixel_put(s.mlx, s.win, s.isoY + WIDTH/3, s.isoX + s.j, 0xFFFFF);
			//other side
			//mlx_pixel_put(s.mlx, s.win, s.j + s.isoY + WIDTH/3, s.isoX + MARGIN, 0xFFFFF);
			//mlx_pixel_put(s.mlx, s.win, s.isoY + WIDTH/3 + MARGIN, s.isoX + s.j, 0xFFFFF);
			//s.j++;
			//	}
			//s.j = 0;
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
