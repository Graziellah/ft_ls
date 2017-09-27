/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 21:46:18 by ghippoda          #+#    #+#             */
/*   Updated: 2017/09/21 15:47:43 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	aff_visible(t_file *list, t_option *op)
{
	t_file	*tmp;

	tmp = list;
	while (list != NULL)
	{
		WHITE;
		if (list->s[0] != '.' && list->d_type == DT_REG)
			aff_visible2(op, list, TREG);
		else if (list->d_type == DT_REG && list->s[0] != '.' &&
				S_ISREG(list->buf.st_mode) && (list->buf.st_mode & 0111))
			aff_visible2(op, list, TEXE);
		else if (list->d_type == DT_DIR && list->s[0] != '.')
			aff_visible2(op, list, TDIR);
		else if (list->d_type == DT_FIFO && list->s[0] != '.')
			aff_visible2(op, list, TFIFO);
		else if (list->d_type == DT_SOCK && list->s[0] != '.')
			aff_visible2(op, list, TSOCK);
		else if (list->d_type == DT_CHR && list->s[0] != '.')
			aff_visible2(op, list, TCHR);
		else if (list->d_type == DT_BLK && list->s[0] != '.')
			aff_visible2(op, list, TBLK);
		else if (list->d_type == DT_LNK && list->s[0] != '.')
			aff_visible2(op, list, TLNK);
		list = list->next;
	}
}

void	aff_all(t_file *list, t_option *op)
{
	t_file	*tmp;

	tmp = list;
	while (list != NULL)
	{
		WHITE;
		if (list->d_type == DT_REG)
			aff_visible2(op, list, TREG);
		else if (list->d_type == DT_DIR)
			aff_visible2(op, list, TDIR);
		else if (list->d_type == DT_FIFO)
			aff_visible2(op, list, TFIFO);
		else if (list->d_type == DT_SOCK)
			aff_visible2(op, list, TSOCK);
		else if (list->d_type == DT_CHR)
			aff_visible2(op, list, TCHR);
		else if (list->d_type == DT_BLK)
			aff_visible2(op, list, TBLK);
		else if (list->d_type == DT_LNK)
			aff_visible2(op, list, TLNK);
		list = list->next;
	}
}

void	recursive(t_file *list, t_option *op)
{
	t_file	*list2;
	char	*str;

	str = NULL;
	while (list != NULL)
	{
		if (ft_strcmp(list->s, ".") == 0 || ft_strcmp(list->s, "..") == 0)
			list = list->next;
		if (list->s[0] != '.' && list->d_type == DT_DIR && op->a == 0)
		{
			str = ft_strjoin(list->parent, "/");
			str = ft_strjoin(str, list->s);
			list2 = ft_create_list(str);
			open_dir(str, list2, op);
		}
		else if (list->d_type == DT_DIR && op->a == 1 &&
				list->s[1] != '.')
		{
			str = ft_strjoin(list->parent, "/");
			str = ft_strjoin(str, list->s);
			list2 = ft_create_list(str);
			open_dir(str, list2, op);
		}
		list = list->next;
	}
}

void	aff_list(t_file *list, t_option *op)
{
	if (list_count(list) > 2)
		sort(&list, op);
	if (op->a == 0)
		aff_visible(list, op);
	else
		aff_all(list, op);
	if (op->rec == 1)
		recursive(list, op);
}

void	open_dir(char *s, t_file *list, t_option *op)
{
	YELLOW;
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putstr(s);
	ft_putchar(':');
	ft_putchar('\n');
	aff_list(list, op);
}
