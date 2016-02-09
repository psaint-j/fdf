/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 12:29:35 by psaint-j          #+#    #+#             */
/*   Updated: 2016/02/09 08:12:38 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	char	*line;
	t_env	s;
	(void)ac;

	s = init_env(s);
	s = check_params(s, av[1]);
	s = init_map(s);
	s.fd = open(av[1], O_RDONLY);
	while (get_next_line(s.fd, &line) > 0)
	{
		s.ymax++;
		s.map[s.j] = ft_strsplit(line, ' ');
		ft_print_tab(s.map[s.j]);
		ft_putstr("\n");
		s.j++;
	}
	ft_draw_pixel(s);
	close(s.fd);
	mlx_key_hook(s.win, key_hook, &s);
	mlx_loop(s.mlx);
	return (0);
}
