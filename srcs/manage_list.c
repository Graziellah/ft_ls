/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:17:22 by ghippoda          #+#    #+#             */
/*   Updated: 2017/09/12 20:36:45 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file		*sort_list_bytime(t_file *ls)
{
	t_file	*tmp;
	t_file	*l2;
	t_file	*tmp2;

	tmp = ls;
	l2 = ls->next;
	tmp2 = l2;
	while (l2 != NULL)
	{
		tmp2 = l2;
		if (ls->buf.st_mtime < l2->buf.st_mtime)
		{
			swap_file(&ls, &l2);
			ls = tmp;
			l2 = tmp2;
		}
		ls = ls->next;
		l2 = ls->next;
	}
	ls = tmp;
	return (ls);
}

t_file		*reverse(t_file *ls)
{
	t_file	*l;
	t_file	*r;
	t_file	*p;

	l = ls;
	r = NULL;
	while (l != NULL)
	{
		p = l;
		l = l->next;
		p->next = r;
		r = p;
	}
	return (r);
}

t_file		*sort_ascii(t_file *ls)
{
	t_file	*tmp;
	t_file	*l2;
	t_file	*tmp2;

	l2 = ls->next;
	tmp2 = l2;
	tmp = ls;
	while (l2 != NULL)
	{
		if (ft_strcmp(ls->s, l2->s) > 0)
		{
			swap_file(&ls, &l2);
			ls = tmp;
			l2 = tmp2;
		}
		else
		{
			ls = ls->next;
			l2 = ls->next;
		}
	}
	return (tmp);
}

t_file		*sort_list_byaccess(t_file *ls)
{
	t_file	*tmp;
	t_file	*l2;
	t_file	*tmp2;

	tmp = ls;
	l2 = ls->next;
	tmp2 = l2;
	while (l2 != NULL)
	{
		tmp2 = l2;
		if (ls->buf.st_atime < l2->buf.st_atime)
		{
			swap_file(&ls, &l2);
			ls = tmp;
			l2 = tmp2;
		}
		ls = ls->next;
		l2 = ls->next;
	}
	ls = tmp;
	return (tmp);
}

t_file		*sort_list_bychange(t_file *ls)
{
	t_file	*tmp;
	t_file	*l2;
	t_file	*tmp2;

	tmp = ls;
	l2 = ls->next;
	tmp2 = l2;
	while (l2 != NULL)
	{
		tmp2 = l2;
		if (ls->buf.st_ctime < l2->buf.st_ctime)
		{
			swap_file(&ls, &l2);
			ls = tmp;
			l2 = tmp2;
		}
		ls = ls->next;
		l2 = ls->next;
	}
	ls = tmp;
	return (tmp);
}
