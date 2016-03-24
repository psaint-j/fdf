/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:03:06 by psaint-j          #+#    #+#             */
/*   Updated: 2016/03/24 14:44:08 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"
#define U s.key_up
#define D s.key_down
#define WHITE 0x00FFFFFF
#define MAJENTA 0x00FF00
#define CYAN 0x0FFFF

void		pixel_put(t_env env, int x, int y)
{
	if (ft_strncmp(env.map[env.y_tab][env.x_tab], "0", 1) == 0)
		mlx_pixel_put(env.mlx, env.win, x, y, MAJENTA);
	else if (ft_strncmp(env.map[env.y_tab][env.x_tab], "-", 1) == 0)
		mlx_pixel_put(env.mlx, env.win, x, y, CYAN);
	else
		mlx_pixel_put(env.mlx, env.win, x, y, WHITE);
}

t_bresenham	line_direct(t_bresenham bres)
{
	if (bres.w < 0)
		bres.dx1 = -1;
	else if (bres.w > 0)
		bres.dx1 = 1;
	if (bres.h < 0)
		bres.dy1 = -1;
	else if (bres.h > 0)
		bres.dy1 = 1;
	if (bres.w < 0)
		bres.dx2 = -1;
	else if (bres.w > 0)
		bres.dx2 = 1;
	return (bres);
}

void		make_line(t_bresenham bres, t_env env, int x, int y)
{
	int	i;

	i = 0;
	while (i <= bres.longest)
	{
		pixel_put(env, x, y);
		bres.numerator += bres.shortest;
		if (!(bres.numerator < bres.longest))
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

void		draw_line(t_env env, t_bresenham bres)
{
	bres = init_bresenham(bres);
	bres.w = bres.x1 - bres.x;
	bres.h = bres.y1 - bres.y;
	bres = line_direct(bres);
	bres.longest = abs(bres.w);
	bres.shortest = abs(bres.h);
	if (!(bres.longest > bres.shortest))
	{
		bres.longest = abs(bres.h);
		bres.shortest = abs(bres.w);
		if (bres.h < 0)
			bres.dy2 = -1;
		else if (bres.h > 0)
			bres.dy2 = 1;
		bres.dx2 = 0;
	}
	bres.numerator = bres.longest >> 1;
	make_line(bres, env, bres.x, bres.y);
}

void		ft_draw_pixel(t_env s)
{
	t_bresenham bres;

	bres.h = 0;
	while (s.map[s.y_tab])
	{
		while (s.map[s.y_tab][s.x_tab])
		{
			s = init_point(s);
			draw_map(s, bres);
			s.e_x += s.margin;
			s.x_tab++;
		}
		s.e_x = 0;
		s.x_tab = 0;
		s.y_tab++;
		s.e_y += s.margin;
	}
}
