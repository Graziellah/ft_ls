/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:17:22 by ghippoda          #+#    #+#             */
/*   Updated: 2017/09/19 15:53:30 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file		*create_file(void)
{
	t_file	*new;

	new = NULL;
	new->next = NULL;
	return (new);
}

void		cpy_file(t_file **ls, t_file *l2)
{
	(*ls)->buf = l2->buf;
	(*ls)->sd = l2->sd;
	(*ls)->s = l2->s;
	(*ls)->parent = l2->parent;
	(*ls)->d_type = l2->d_type;
	(*ls)->d_ino = l2->d_ino;
}

void		swap_file(t_file **ls, t_file **l2)
{
	t_file	tmp;

	tmp = **ls;
	cpy_file(ls, *l2);
	cpy_file(l2, &tmp);
}

int			list_count(t_file *list)
{
	int		i;

	i = 0;
	while (list != NULL)
	{
		i++;
		list = list->next;
	}
	return (i);
}
