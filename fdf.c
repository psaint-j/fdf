/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 12:29:35 by psaint-j          #+#    #+#             */
/*   Updated: 2016/01/29 15:41:43 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define _SIZE 2147483647

int		main(int ac, char **av)
{
/*	int		fd;
	int		buf_size;
	char	buf[_SIZE];

	buf_size = _SIZE;
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		read(fd, buf, buf_size);
		ft_putstr(buf);
		close(fd);
	}*/

	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_putstr(line);
		ft_putstr("\n");
	}
	return (0);
}
