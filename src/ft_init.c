/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:03:37 by psaint-j          #+#    #+#             */
/*   Updated: 2016/02/09 13:50:53 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_env	init_env(t_env env)
{
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx,WIDTH, HEIGHT,"Fdf" );
	env.x = 0;
	env.y = 0;
	env.i = 0;
	env.j = 0;
	env.k = 0;
	env.xmax = 0;
	env.ymax = 0;
//	env.map = malloc(1000);
	env.tab_tmp = NULL;
	env.e_y = 0;
	env.e_x = 0;
	env.fd = 0;
	env.key_up = 3;
	env.key_down = 3;
	return (env);
}

t_env	init_map(t_env env)
{
	int		size;

	if (env.xmax > env.ymax)
		size = env.xmax;
	else
		size = env.ymax;
	env.map = malloc(size * size * size);
	return (env);
}

t_env	check_params(t_env env,char *file)
{
	char	*line;
	int		fd;
	int		len;

	len = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (len < (int)ft_strlen(line))
			len = ft_strlen(line);
		env.ymax++;
	}
	close(fd);
	env.xmax = len;
	return (env);
}

void	check_line(t_env s)
{
	char *line;

	line = NULL;
	while (get_next_line(s.fd, &line) > 0)
	{
		s.ymax++;
		s.map[s.j] = ft_strsplit(line, ' ');
		ft_print_tab(s.map[s.j]);
		ft_putstr("\n");
		s.j++;
	}
}

void	ft_print_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putstr("\t");
		i++;
	}
}
