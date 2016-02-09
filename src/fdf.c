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

int		main(int ac, char **av)
{
	char	*line;
	t_env	s;
	(void)ac;

	/*s.i = 0;
	s.j = 0;
	s.xmax = 0;
	s.ymax = 0;
	s.i = 0;
	s.mlx = mlx_init();
	s.win = mlx_new_window(s.mlx, 800, 600, "FDF");
	s.map = malloc(2000);*/
	s = init_env(s);
	s = check_params(s, av[1]);
	s = init_map(s);
	//ft_putnbr(s.ymax);
	//ft_putstr(" <- Y . X -> ");
	//ft_putnbr(s.xmax);
	//ft_putstr("\n");
	s.fd = open(av[1], O_RDONLY);
	while (get_next_line(s.fd, &line) > 0)
	{
		s.ymax++;
		s.map[s.j] = ft_strsplit(line, ' ');
		ft_print_tab(s.map[s.j]);
		ft_putstr("\n");
		s.j++;
	}
	/*s.x = 0;
	s.y = 0; 
	s.e_x = 0;
	s.e_y = 0;*/
	while (s.map[s.x][s.y])
	{
		while (s.map[s.x])
		{
			s.i = ft_atoi(s.map[s.x][s.y]);
			if (s.i <= 0)
			mlx_pixel_put(s.mlx, s.win, s.e_y+ WIDTH/3, s.e_x + 10, 0xFFFFF);
			else
			mlx_pixel_put(s.mlx, s.win, s.e_y+ WIDTH/3, s.e_x + 10, 0xff0000);
			s.x++;
			s.e_x = s.e_x + (MARGIN + s.key_up);
		}
		s.e_x = 0;
		s.x = 0;
		s.y++;
		s.e_y = s.e_y + (MARGIN + s.key_down);
	}
	close(s.fd);
	mlx_key_hook(s.win, key_hook, &s);
	mlx_loop(s.mlx);
	return (0);
}
