/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 12:17:17 by psaint-j          #+#    #+#             */
/*   Updated: 2016/03/11 14:24:45 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>

# define BUF_SIZE 2048
# define WIDTH 1920
# define HEIGHT 1080
# define MARGIN 22
# define C1 0.75
# define C2 0.75

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			x_tab;
	int			y_tab;
	int			i;
	int			j;
	int			xmax;
	int			ymax;
	char		***map;
	char		**tab_tmp;
	int			e_y;
	int			e_x;
	int			fd;
	int			key_up;
	int			key_down;
	int			k;
	float		z_x;
	float		z_y;
	float		x;
	float		y;
	float		x1;
	float		y1;
	float		x2;
	float		y2;
	float		x3;
	float		y3;
	int			v_map;
}				t_env;

typedef struct	s_bresenham
{
	int			w;
	int			h;
	int			longest;
	int			shortest;
	int			numerator;
	int			dx2;
	int			dy2;
	int			dx1;
	int			dy1;
}				t_bresenham;

t_bresenham		init_bresenham(t_bresenham bres);
t_env			init_map(t_env env);
t_env			init_env(t_env env);
int				check_params(t_env env, char *file);
void			ft_line2(int x1, int y1, int x2, int y2, t_env all);
void			ft_tabstr(char **z, int y, char ***map);
void			ft_print_tab(char **tab);
void			print_mlx(t_env env, char **map, int x);
int				key_hook(int keycode, t_env param);
void			ft_draw_pixel(t_env s);
void			check_line(t_env s);
int				find_z(t_env s, int z);
t_env			init_point(t_env s);
#endif
