/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 12:17:17 by psaint-j          #+#    #+#             */
/*   Updated: 2016/04/01 17:08:19 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <errno.h>

#define BUF_SIZE 2048
# define WIDTH 1920
# define HEIGHT 1080
# define C1 0.999

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			x_tab;
	int			y_tab;
	float		margin;
	int			xmax;
	int			ymax;
	char		***map;
	int			e_y;
	int			e_x;
	int			fd;
	float		w_size;
	float		h_size;
	float		x;
	float		y;
	float		x1;
	float		y1;
	float		x2;
	float		y2;
	float		x3;
	float		y3;
	int			usage;
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
	float		x;
	float		y;
	float		x1;
	float		y1;
}				t_bresenham;

t_env			init_fdf(t_env s, char *file);
t_bresenham		init_bresenham(t_bresenham bres);
t_env			init_map(t_env env, int size);
t_env			init_env(t_env env);
void			draw_line(t_env env, t_bresenham bres);
void			draw_map(t_env s, t_bresenham bres);
t_env			check_params(t_env env, char *file);
void			ft_tabstr(char **z, int y, char ***map);
void			ft_print_tab(char **tab);
void			print_mlx(t_env env, char **map, int x);
int				key_hook(int keycode, t_env param);
void			ft_draw_pixel(t_env s);
int				check_line(t_env s);
int				find_z(t_env s, int z);
t_env			init_point(t_env s);
void			free_tab_2(char **tab);
void			free_tab(char ***tab);
int				calcul_margin(t_env env);
t_env			center_map(t_env s);
void			free_tab(char ***tab);
#endif
