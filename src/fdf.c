/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 12:29:35 by psaint-j          #+#    #+#             */
/*   Updated: 2016/04/04 17:35:30 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	usage(int usage)
{
	if (usage == 1)
		ft_putendl("fdf:Usage: fdf [file ...]");
	if (usage == 2)
		ft_putendl("fdf:Error Map formating...");
	if (usage == 3)
		ft_putendl("fdf:Something wrong with the file");
}

int		calcul_margin(t_env s)
{
	float	taille[2];
	float	ntaille[2];

	taille[1] = s.margin * s.xmax;
	taille[0] = s.margin * s.ymax;
	ntaille[0] = 0;
	ntaille[1] = 0;
	if (taille[0] > WIDTH || taille[1] > HEIGHT)
	{
		if (taille[0] > taille[1])
		{
			ntaille[0] = 800 / taille[0];
			s.margin *= ntaille[0];
		}
		else if (taille[0] <= taille[1])
		{
			ntaille[1] = 600 / taille[1];
			s.margin *= ntaille[1];
		}
		if (s.margin <= 0)
			s.margin = 1;
		return (s.margin);
	}
	return (s.margin);
}

t_env	init_fdf(t_env s, char *file)
{
	int		size;

	s = init_env(s);
	if (!(s.fd = open(file, O_RDONLY)))
		exit(-2);
	size = check_line(s);
	s = init_map(s, size);
	close(s.fd);
	s = check_params(s, file);
	return (s);
}

int		main(int ac, char **av)
{
	t_env	s;

	s.usage = 0;
	if (ac == 2)
	{
		s = init_fdf(s, av[1]);
		if (s.usage == 0)
		{
			mlx_key_hook(s.win, key_hook, &s);
			s.margin = calcul_margin(s);
			s = center_map(s);
			ft_draw_pixel(s);
			free_tab(s.map);
			mlx_loop(s.mlx);
		}
		else
		{
			usage(2);
			return (0);
		}
	}
	usage(1);
	return (0);
}
