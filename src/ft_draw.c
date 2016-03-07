/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:03:06 by psaint-j          #+#    #+#             */
/*   Updated: 2016/03/07 06:30:47 by psaint-j         ###   ########.fr       */
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

void    draw_line2(t_env env, int x, int y, int x2, int y2)
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
	bres.longest = abs(bres.w);
	bres.shortest = abs(bres.h);
	if (!(bres.longest > bres.shortest))
	{
		bres.longest = abs(bres.h);
		bres.shortest = abs(bres.w);
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
	if (z == 2)
	{
		if (s.map[s.y_tab + 1] != NULL)
		{
			if(s.map[s.y_tab + 1][s.x_tab + 1])
				return (ft_atoi(s.map[s.y_tab + 1][s.x_tab + 1]));
		}
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
	s.y = ((s.e_y + s.e_x)/2) - find_z(s, 0)*5;
	//x1
	s.x1 = (s.e_y - (s.e_x + MARGIN));
	s.y1 = (((s.e_x + MARGIN) + s.e_y)/2) - find_z(s, 1)*5;
	//x2
	s.x3 = ((s.e_y + MARGIN) - s.e_x);
	s.y3 = ((s.e_x + (s.e_y + MARGIN))/2) - find_z(s, 3)*5;
	//x3
	s.x2 = ((s.e_y + MARGIN) - (s.e_x + MARGIN));
	s.y2 = (((s.e_x + MARGIN) + (s.e_y + MARGIN))/2) - find_z(s, 2)*5;
	return (s);
}

void	ft_draw_pixel(t_env s)
{
	int		w_size;
	int		h_size;

	w_size = (WIDTH - (MARGIN*s.xmax))/2;
	h_size = (HEIGHT - (MARGIN*s.xmax))/2;
	//w_size = 0;
	//h_size = HEIGHT/2;
	while (s.map[s.y_tab])
	{
		while (s.map[s.y_tab][s.x_tab])
		{
			s = init_point(s);
			draw_line2(s, -s.x + w_size, s.y + h_size, -s.x1 + w_size, s.y1 + h_size);
			draw_line2(s, -s.x + w_size, s.y + h_size, -s.x3 + w_size, s.y3 + h_size);
			draw_line2(s, -s.x3 + w_size, s.y3 + h_size, -s.x2 + w_size, s.y2 + h_size);
			draw_line2(s, -s.x2 + w_size, s.y2 + h_size, -s.x1 + w_size, s.y1 + h_size);
			s.e_x += MARGIN;
			s.x_tab++;
		}
	//draw_line2(s, -s.x + HEIGHT/5, s.y + WIDTH/5, -s.x1 + HEIGHT/5, s.y1 + WIDTH/5);
	//draw_line2(s, -s.x + HEIGHT/5, s.y + WIDTH/5, -s.x3 + HEIGHT/5, s.y3 + WIDTH/5);
		s.e_x = 0;
		s.x_tab = 0;
		s.y_tab++;
		s.e_y += MARGIN;
	}
}
