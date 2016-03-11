/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:03:06 by psaint-j          #+#    #+#             */
/*   Updated: 2016/03/11 16:08:32 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"
#define U s.key_up
#define D s.key_down
#define WHITE 0x00FFFFFF
#define MAJENTA 0x0FF1493
#define CYAN 0x0FFFF

void	pixel_put(t_env env, int x, int y)
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

void		draw_line(t_env env, int x, int y, int x2, int y2)
{
	t_bresenham	bres;

	bres = init_bresenham(bres);
	bres.w = x2 - x;
	bres.h = y2 - y;
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
	make_line(bres, env, x, y);
}

void	ft_draw_pixel(t_env s)
{
	int		w_size;
	int		h_size;

	//w_size = (WIDTH - (MARGIN * s.xmax)) / 4;
	w_size = 150;
	h_size = 250;
	while (s.map[s.y_tab])
	{
		while (s.map[s.y_tab][s.x_tab])
		{
			if (s.map[s.y_tab][s.x_tab + 1] == NULL)
				break ;
			s = init_point(s);
			draw_line(s, -s.x + w_size, s.y + h_size,
					-s.x1 + w_size, s.y1 + h_size);
			draw_line(s, -s.x + w_size, s.y + h_size,
					-s.x3 + w_size, s.y3 + h_size);
			draw_line(s, -s.x3 + w_size, s.y3 + h_size,
					-s.x2 + w_size, s.y2 + h_size);
			draw_line(s, -s.x2 + w_size, s.y2 + h_size,
					-s.x1 + w_size, s.y1 + h_size);
			s.e_x += MARGIN;
			s.x_tab++;
		}
		if (s.map[s.y_tab + 1] == NULL)
			break ;
		s.e_x = 0;
		s.x_tab = 0;
		s.y_tab++;
		s.e_y += MARGIN;
	}
}
