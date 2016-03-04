/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:03:06 by psaint-j          #+#    #+#             */
/*   Updated: 2016/03/04 19:07:57 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"
#define U s.key_up
#define D s.key_down
# define WHITE 0x00FFFFFF
# define MAJENTA 0x0FF1493
# define CYAN 0x0FFFF

void	pixel_put(t_env env, int x, int y)
{
	if (ft_strncmp(env.map[env.y_tab][env.x_tab], "0", 1) == 0)
		mlx_pixel_put(env.mlx, env.win, x, y, WHITE);
	else if (ft_strncmp(env.map[env.y_tab][env.x_tab], "-", 1) == 0)
		mlx_pixel_put(env.mlx, env.win, x, y, CYAN);
	else
		mlx_pixel_put(env.mlx, env.win, x, y, MAJENTA);
}

/*void    draw_line2(t_env env, int x, int y, int x2, int y2)
{
	int         i;
	t_bresenham bres;

	i = 0;
	bres = init_bresenham(bres);
	bres.w = x2 - x;
	bres.h = y2 - y;
	if (bres.w < 0) bres.dx1 = -1; else if (bres.w > 0) bres.dx1 = 1;
	if (bres.h < 0) bres.dy1 = -1; else if (bres.h > 0) bres.dy1 = 1;
	if (bres.w < 0) bres.dx2 = -1; else if (bres.w > 0) bres.dx2 = 1;
	bres.longest = ft_abs(bres.w);
	bres.shortest = ft_abs(bres.h);
	if (!(bres.longest > bres.shortest))
	{
		bres.longest = ft_abs(bres.h);
		bres.shortest = ft_abs(bres.w);
		if (bres.h < 0) bres.dy2 = -1; else if (bres.h > 0) bres.dy2 = 1;
		bres.dx2 = 0;
	}
	bres.numerator = bres.longest >> 1;
	while (i <= bres.longest)
	{
		pixel_put(env, x, y);
		bres.numerator += bres.shortest;
		if (!(bres.numerator<bres.longest))
		{
			bres.numerator -= bres.longest;
			x += bres.dx1;
			y += bres.dy1;
		}
		else
		{
			x += bres.dx2;
			y += bres.dy2;
		}
		i++;
	}
}
*/
void		draw_line(t_env env, int y1, int x1, int y2, int x2)
{
	int dx;
	int dy;
	int	e;

	dx = x2 - x1;
	dy = y2 - y1;
	if (dx != 0)
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
							pixel_put(env, x1, y1);
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
							pixel_put(env, x1, y1);
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
							pixel_put(env, x1, y1);
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
							pixel_put(env, x1, y1);
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
					pixel_put(env, x1, y1);
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
							pixel_put(env, x1, y1);
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
							pixel_put(env, x1, y1);
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
							pixel_put(env, x1, y1);
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
							pixel_put(env, x1, y1);
							if ((e = e - dx) >= 0)
							{
								x1 = x1 - 1;
								e = e + dy;
							}
						}
					}
				}
			}
			else
			{
				while ((x1 = x1 - 1) != x2)
					pixel_put(env, x1, y1);
			}
		}
	}
	else
	{
		if ((dy = y2 - y1) != 0)
		{
			if (dy > 0)
			{
				while ((y1 = y1 + 1) != y2)
					pixel_put(env, x1, y1);
			}
			else
			{
				while ((y1 = y1 - 1) != y2)
					pixel_put(env, x1, y1);
			}
		}
	}
}

int		find_z(t_env s, int z)
{
	if (z == 0)
	{
		if(s.map[s.y_tab][s.x_tab])
			return (ft_atoi(s.map[s.y_tab][s.x_tab]));
	}
	if (z == 1)
	{
		if(s.map[s.y_tab][s.x_tab + 1])
			return (ft_atoi(s.map[s.y_tab][s.x_tab + 1]));
	}
	if (z == 3)
	{
		if (s.map[s.y_tab + 1] != NULL)
		{
			if(s.map[s.y_tab + 1][s.x_tab])
				return (ft_atoi(s.map[s.y_tab + 1][s.x_tab]));
		}
	}
	return(0);
}

t_env	init_point(t_env s)
{
	//ft_putnbr(z);
	s.x = (s.e_y - s.e_x);
	if (find_z(s, 0) > 0)
		s.y = ((s.e_y + s.e_x)/2) - find_z(s, 0)*3;
	else
		s.y = ((s.e_y + s.e_x)/2) + find_z(s, 0)*3;
	//x1
	s.x1 = (s.e_y - (s.e_x + MARGIN));
	if (find_z(s, 0) > 0)
		s.y1 = (((s.e_x + MARGIN) + s.e_y)/2) - find_z(s, 1)*3;
	else
		s.y1 = (((s.e_x + MARGIN) + s.e_y)/2) + find_z(s, 1)*3;
	//x2
	s.x3 = ((s.e_y + MARGIN) - s.e_x);
	if (find_z(s, 0) > 0)
		s.y3 = ((s.e_x + (s.e_y + MARGIN))/2) - find_z(s, 3)*3;
	else
		s.y3 = ((s.e_x + (s.e_y + MARGIN))/2) + find_z(s, 3)*3;
	//x3
	s.x2 = ((s.e_y + MARGIN) - (s.e_x + MARGIN));
	s.y2 = ((s.e_x + MARGIN) + (s.e_y + MARGIN))/2;
	return (s);
}

void	ft_draw_pixel(t_env s)
{
	while (s.map[s.y_tab])
	{
		while (s.map[s.y_tab][s.x_tab])
		{
			/*x_tmp = s.x;
			  y_tmp = s.y;
			  s.x = (s.e_y - s.e_x);
			  s.y = ((s.e_y + s.e_x)/2) - z*3;*/
			s = init_point(s);
			draw_line(s, s.y + HEIGHT/2, -s.x + WIDTH/3, s.y1 + HEIGHT/2, -s.x1 + WIDTH/3);
			//draw_line(s, s.y + HEIGHT/2, -s.x + WIDTH/3, y_tmp + HEIGHT/2, -x_tmp + WIDTH/3);
			draw_line(s, s.y + HEIGHT/2, -s.x + WIDTH/3, s.y3 + HEIGHT/2, -s.x3 + WIDTH/3);
			s.e_x += MARGIN;
			s.x_tab++;
		}
		s.e_x = 0;
		s.x_tab = 0;
		s.y_tab++;
		s.e_y += MARGIN;
	}
}

//ft_line2(s.z_y + 250, s.z_x + 50, s.z_y + 270, s.z_x + 60, s);
//ft_line2(s.z_y + 270, s.z_x + 40, s.z_y + 250, s.z_x + 50, s);
//y2 = s.isoY;
//x2 = s.isoX;
//x3 = (s.e_y + 20 - s.e_x);
//y3 = ((s.e_x + s.e_y + 20)/2);
