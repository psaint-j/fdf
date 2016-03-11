/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 12:29:35 by psaint-j          #+#    #+#             */
/*   Updated: 2016/03/11 15:11:04 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	usage(void)
{
	ft_putendl("Usage: fdf [file ...]");
}

int		main(int ac, char **av)
{
	t_env	s;

	if (ac == 2)
	{
		s = init_env(s);
		if (check_params(s, av[1]) > 0)
		{
			s = init_map(s);
			s.fd = open(av[1], O_RDONLY);
			check_line(s);
			mlx_key_hook(s.win, key_hook, &s);
			ft_draw_pixel(s);
			close(s.fd);
			mlx_loop(s.mlx);
		}
	}
	usage();
	return (0);
}
