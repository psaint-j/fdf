/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 15:50:55 by psaint-j          #+#    #+#             */
/*   Updated: 2016/02/09 08:23:59 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, t_env param)
{
	ft_putstr("Keycode : ");
	ft_putnbr(keycode);
	ft_putstr("\n");
	if (keycode == 126)
	{
		param.key_up++;
		param.key_down++;
	}
	if (keycode == 125)
	{
		param.key_up--;
		param.key_down--;
	}
	if (keycode == 53)
		exit(1);
	return (0);
}
