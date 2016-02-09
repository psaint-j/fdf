/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:03:06 by psaint-j          #+#    #+#             */
/*   Updated: 2016/02/09 08:22:53 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"
#define U s.key_up
#define D s.key_down

void	ft_draw_pixel(t_env s)
{
	s.key_up = 3;
	s.key_down = 3;

	while (s.map[s.x][s.y])
	{
		while (s.map[s.x])
		{
			s.i = ft_atoi(s.map[s.x][s.y]);
			if (s.i <= 0)
			mlx_pixel_put(s.mlx, s.win, s.e_y+ WIDTH/U, s.e_x + 10, 0xFFFFF);
			else
			mlx_pixel_put(s.mlx, s.win, s.e_y+ WIDTH/D, s.e_x + 10, 0xff0000);
			s.x++;
			s.e_x = s.e_x + (MARGIN + s.key_up);
		}
		s.e_x = 0;
		s.x = 0;
		s.y++;
		s.e_y = s.e_y + (MARGIN + s.key_down);
	}
}
