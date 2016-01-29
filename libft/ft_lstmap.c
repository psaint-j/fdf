/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 18:12:41 by psaint-j          #+#    #+#             */
/*   Updated: 2015/02/24 18:09:09 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new;

	tmp = lst;
	new = f(tmp);
	tmp = tmp->next;
	while (tmp)
	{
		new->next = f(tmp);
		tmp = tmp->next;
	}
	return (new);
}
