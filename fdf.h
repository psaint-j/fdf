/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 12:17:17 by psaint-j          #+#    #+#             */
/*   Updated: 2016/02/01 15:44:03 by psaint-j         ###   ########.fr       */
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
#include "libft/libft.h"

#define BUF_SIZE 2048

typedef struct		s_var
{
	int		i;
	int		j;
	int		xmax;
	int		ymax;
	char	***map;
	char	**tab_tmp;
}					t_var;

typedef struct		s_env
{
}					t_env;
//initialise les valeur X = 0 or NULL
t_var		*init_var(t_var *e);
t_var		*init_tab(char *str, t_var *e);
void		ft_tabstr(char **z, int y, char ***map);
void		ft_print_tab(char **tab);
#endif
