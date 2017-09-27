/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_aff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 21:58:44 by ghippoda          #+#    #+#             */
/*   Updated: 2017/09/21 15:48:18 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	color(int type)
{
	if (type == TREG)
		GREEN;
	else if (type == TDIR)
		CYAN;
	else if (type == TFIFO)
		YELLOW;
	else if (type == TLNK)
		PURPLE;
	else if (type == TEXE)
		RED;
	else
		WHITE;
}

void	end(int type)
{
	if (type == TEXE)
		ft_putchar('*');
	else if (type == TDIR)
		ft_putchar('/');
	else if (type == TFIFO)
		ft_putchar('|');
	else if (type == TLNK)
		ft_putchar('@');
	else if (type == TSOCK)
		ft_putchar('=');
	else
		ft_putstr("");
}

void	link_path(t_file *list)
{
	char	target_path[256];
	char	*link_path;
	int		len;

	if (list->parent[0] == '/' && list->parent[1] == 'd' && list->parent[2]
			== 'e' && list->parent[3] == 'v')
		link_path = list->parent;
	else
		link_path = list->s;
	ft_putstr(" -> ");
	len = readlink(link_path, target_path, sizeof(target_path));
	target_path[len] = '\0';
	ft_putstr(target_path);
	list = NULL;
}

void	aff_visible2(t_option *op, t_file *list, int type)
{
	if (op->inode == 1)
		aff_inode(list->d_ino);
	if (op->list == 1)
		aff_info(list->buf);
	if (S_ISREG(list->buf.st_mode) && (list->buf.st_mode & 0111)
			&& type == TREG)
		type = TEXE;
	color(type);
	ft_putstr(list->s);
	if (op->list == 1 && list->d_type == DT_LNK)
		link_path(list);
	if (op->end == 1)
		end(type);
	if ((op->list == 1 || op->line == 1) && list->next != NULL)
		ft_putstr("\n");
	else
		ft_putstr("\t");
	WHITE;
}

void	sort(t_file **list, t_option *op)
{
	*list = sort_ascii(*list);
	if (op->time == 1)
		*list = sort_list_bytime(*list);
	if (op->rev == 1)
		*list = reverse(*list);
	if (op->access == 1)
		*list = sort_list_byaccess(*list);
	if (op->change == 1)
		*list = sort_list_bychange(*list);
	if (op->list == 1)
		aff_total(*list, op);
}
