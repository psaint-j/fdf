/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:03:37 by psaint-j          #+#    #+#             */
/*   Updated: 2016/03/11 16:04:05 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define FD 0
#define LEN 1
#define LEN_TMP 2

t_env			init_env(t_env env)
{
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT, "Fdf");
	env.x_tab = 0;
	env.y_tab = 0;
	env.i = 0;
	env.j = 0;
	env.k = MARGIN;
	env.xmax = 0;
	env.ymax = 0;
	env.tab_tmp = NULL;
	env.e_y = 0;
	env.e_x = 0;
	env.fd = 0;
	env.key_up = 3;
	env.key_down = 3;
	env.z_x = 0;
	env.z_y = 0;
	env.v_map = 0;
	return (env);
}

t_env			init_map(t_env env)
{
	int		size;

	if (env.xmax > env.ymax)
		size = env.xmax;
	else
		size = env.ymax;
	env.map = malloc(999999999);
	return (env);
}

int				check_params(t_env env, char *file)
{
	char	*line;
	int		db[3];
	char	**tab;

	db[LEN] = -1;
	db[FD] = open(file, O_RDONLY);
	while (get_next_line(db[FD], &line) > 0)
	{
		db[LEN_TMP] = db[LEN];
		tab = ft_strsplit(line, ' ');
		db[LEN] = ft_countab(tab);
		if (env.ymax > 0 && db[LEN] != db[LEN_TMP])
			return (-1);
		env.ymax++;
	}
	close(db[LEN]);
	env.xmax = db[LEN];
	ft_putnbr(env.ymax);
	ft_putnbr(env.xmax);
	return (env.xmax);
}

void			check_line(t_env s)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(s.fd, &line) > 0)
	{
		s.map[i] = ft_strsplit(line, ' ');
		i++;
	}
	s.map[i] = NULL;
}

t_bresenham		init_bresenham(t_bresenham bres)
{
	bres.h = 0;
	bres.w = 0;
	bres.longest = 0;
	bres.shortest = 0;
	bres.numerator = 0;
	bres.dx1 = 0;
	bres.dy1 = 0;
	bres.dx2 = 0;
	bres.dy2 = 0;
	return (bres);
}
