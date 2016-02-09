/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 12:17:17 by psaint-j          #+#    #+#             */
/*   Updated: 2016/02/09 08:10:42 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "../mlx/mlx.h"

#define BUF_SIZE 2048
#define WIDTH 800
#define HEIGHT 600
#define MARGIN 6

typedef struct		s_env
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		i;
	int		j;
	int		xmax;
	int		ymax;
	char	***map;
	char	**tab_tmp;
	int		e_y;
	int		e_x;
	int		fd;
	int		key_up;
	int		key_down;
}					t_env;


//initialise les valeur X = 0 or NULL
t_env		init_map(t_env env);
t_env		init_env(t_env env);
t_env		check_params(t_env env, char *file);
void		ft_tabstr(char **z, int y, char ***map);
void		ft_print_tab(char **tab);
void		print_mlx(t_env env, char **map, int x);
int			key_hook(int keycode, t_env param);
//void		ft_put_pixel(t_env mlx, int x, int y, int z);
void	ft_draw_pixel(t_env s);
#endif
