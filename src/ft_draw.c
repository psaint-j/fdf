/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:03:06 by psaint-j          #+#    #+#             */
/*   Updated: 2016/03/03 17:18:54 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"
#define U s.key_up
#define D s.key_down

void	ft_put_pixel(t_env env, int x, int y)
{
	mlx_pixel_put(env.mlx, env.win, x + WIDTH/3, y + HEIGHT/3, 0xFFFFFFF);
}

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
							ft_put_pixel(all, x1, y1);
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
							ft_put_pixel(all, x1, y1);
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
							ft_put_pixel(all, x1, y1);
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
							ft_put_pixel(all, x1, y1);
							if ((e = e - dx) < 0)
							{
								x1 = x1 + 1;
								e = e - dy;
							}
						}
					}
				}
			}
			else
			{
				while ((x1 = x1 + 1) != x2)
					ft_put_pixel(all, x1, y1);
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
							ft_put_pixel(all, x1, y1);
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
							ft_put_pixel(all, x1, y1);
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
							ft_put_pixel(all, x1, y1);
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
							ft_put_pixel(all, x1, y1);
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
					ft_put_pixel(all, x1, y1);
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
					ft_put_pixel(all, x1, y1);
			}
			else // dy < 0 and dx = 0
			{
				while ((y1 = y1 - 1) != y2)
					ft_put_pixel(all, x1, y1);
			}
		}
	}
}

t_env	init_point(t_env s)
{
	s.x = (s.e_y - s.e_x);
	s.y = (s.e_x + s.e_y)/2;
	//x1
	s.x1 = (s.e_y - (s.e_x + 20));
	s.y1 = ((s.e_x + 20) + s.e_y)/2;
	//x2
	s.x3 = ((s.e_y + 20) - s.e_x);
	s.y3 = (s.e_x + (s.e_y + 20))/2;
	//x3
	s.x2 = ((s.e_y + 20) - (s.e_x + 20));
	s.y2 = ((s.e_x + 20) + (s.e_y + 20))/2;
	return (s);
}

void	ft_draw_pixel(t_env s)
{
	int		z;

	z = 0;
	while (s.map[s.y_tab])
	{
		while (s.map[s.y_tab][s.x_tab])
		{
			z = ft_atoi(s.map[s.y_tab][s.x_tab]);
			s = init_point(s);
				ft_line2(s.x, s.y - (z * 10), s.x1, s.y1 - (z * 10), s);
				ft_line2(s.x1, s.y1 - (z * 10), s.x2, s.y2 - (z * 10), s);
			s.e_x = s.e_x + (MARGIN);
			s.x_tab++;
		}
		s.e_y = s.e_y + (MARGIN);
		s.e_x = 0;
		s.x_tab = 0;
		s.y_tab++;
	}
}

//ft_line2(s.z_y + 250, s.z_x + 50, s.z_y + 270, s.z_x + 60, s);
//ft_line2(s.z_y + 270, s.z_x + 40, s.z_y + 250, s.z_x + 50, s);
//y2 = s.isoY;
//x2 = s.isoX;
//x3 = (s.e_y + 20 - s.e_x);
//y3 = ((s.e_x + s.e_y + 20)/2);
