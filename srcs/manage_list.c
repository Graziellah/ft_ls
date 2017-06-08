/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:17:22 by ghippoda          #+#    #+#             */
/*   Updated: 2017/06/08 01:53:19 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_file		*create_file()
{
	t_file	*new;
	new->next = NULL;
	return (new);
}

t_file		*add_file(DIR *dir, t_file *ls)
{
	t_file	*tmp;

	tmp = ls;
	while(ls != NULL)
		ls = ls->next;
	ls->next = create_file();
	return(tmp);
}

t_list		delete_file(t_file *ls, )

t_list		sort_list_by_type(t_file *ls, int type)

t_list		sort_list_by_time(t_file *ls, int time)
