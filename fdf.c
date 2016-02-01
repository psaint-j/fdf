/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 12:29:35 by psaint-j          #+#    #+#             */
/*   Updated: 2016/02/01 16:04:13 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define _SIZE 2147483647

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	t_var	e;
	int		i;

	//e = init_var(e);
	e.i = 0;
	e.j = 0;
	e.xmax = 0;
	e.ymax = 0;
//	e.map = NULL;
//	e.tab_tmp = NULL;
	fd = open(av[1], O_RDONLY);
	//ft_putstr("2\t");
	e.map = malloc(2000);
	while (get_next_line(fd, &line) > 0)
	{
		//e = init_tab(line, e);
		e.ymax++;
		e.map[e.j] = ft_strsplit(line, ' ');
		ft_print_tab(e.map[e.j]);
		ft_putstr("\n");
		e.j++;
	}
	return (0);
}
