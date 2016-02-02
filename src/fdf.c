/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 12:29:35 by psaint-j          #+#    #+#             */
/*   Updated: 2016/02/02 17:54:12 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_env mlx, int x, int y, char *z)
{
	//int		tmp_x;
	//int		tmp_y;

	(void)z;
	//tmp_y = y + 10;
	//tmp_x = x + 10;
	while (y < 200)
	{
		while (x < 200)
		{
			mlx_pixel_put(mlx.mlx, mlx.win, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		x;
	int		y;
	int		e_y;
	int		e_x;
	t_var	e;
	t_env	mlx;
	int		i;
	(void)ac;

	e.i = 0;
	e.j = 0;
	e.xmax = 0;
	e.ymax = 0;
	i = 0;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 800, 600, "FDF");
	fd = open(av[1], O_RDONLY);
	e.map = malloc(2000);
	while (get_next_line(fd, &line) > 0)
	{
		e.ymax++;
		e.map[e.j] = ft_strsplit(line, ' ');
		ft_print_tab(e.map[e.j]);
		ft_putstr("\n");
		e.j++;
	}
	e.j = 0;
	x = 0;
	y = 0;
	e_x = 0;
	e_y = 0;
	while (e.map[x][y])
	{
		while (e.map[x])
		{
			i = ft_atoi(e.map[x][y]);
			if (i <= 0)
			mlx_pixel_put(mlx.mlx, mlx.win, e_y+ 10, e_x + 10, 0xFFFFF);
			else
			mlx_pixel_put(mlx.mlx, mlx.win, e_y+ 10, e_x + 10, 0xff0000);
			x++;
			e_x = e_x + 10;
		}
		e_x = 0;
		x = 0;
		y++;
		e_y = e_y + 10;
	}
	mlx_loop(mlx.mlx);
	return (0);
}
