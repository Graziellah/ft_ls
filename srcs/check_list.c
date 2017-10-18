/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 15:13:40 by ghippoda          #+#    #+#             */
/*   Updated: 2017/10/15 21:16:01 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				check_list(t_file *list, t_option *op)
{
	t_file		*tmp;

	tmp = list;
	if (op->a == 1)
		return (1);
	while (tmp != NULL)
	{
		if (tmp->s[0] != '.')
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void			aff_name(t_option op, int argc, char *argv, int p)
{
	if ((ft_strcmp(argv, "/tmp") == 0) && op.list == 1)
		return ;
	if (op.rec == 1 || (option_off_on(op) == 1 && argc > 2 && p != TMP) ||
			(option_off_on(op) == 0 && argc > 2 && p != TMP) || argc != 1)
		print_name(argv);
	else if ((ft_strcmp(argv, "/tmp") == 0 && op.list == 0 && argc < 2))
		print_name(argv);
}

unsigned char	get_type(struct stat st)
{
	if (S_ISREG(st.st_mode))
		return (DT_REG);
	if (S_ISCHR(st.st_mode))
		return (DT_CHR);
	if (S_ISFIFO(st.st_mode))
		return (DT_FIFO);
	if (S_ISLNK(st.st_mode))
		return (DT_LNK);
	if (S_ISSOCK(st.st_mode))
		return (DT_SOCK);
	return (DT_UNKNOWN);
}

static void		aff_dir(char *s, t_file *list, t_option *op)
{
	YELLOW;
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putstr(s);
	ft_putchar(':');
	ft_putchar('\n');
}

void			recursive2(char *parent, char *enfant, t_option *op)
{
	t_file	*list2;
	char	*str;

	str = ft_strjoin(parent, "/");
	str = ft_strjoin(str, enfant);
	list2 = ft_create_list(str);
	if (check_list(list2, op) == 1)
		open_dir(str, list2, op);
	else
		aff_dir(str, list2, op);
}
