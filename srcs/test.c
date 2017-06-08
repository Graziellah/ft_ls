/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:25:20 by ghippoda          #+#    #+#             */
/*   Updated: 2017/06/08 08:46:48 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	aff_inode(struct dirent *sd)
{
	ft_putnbr(sd->d_ino);
	ft_putchar(' ');
}

void	aff_visible(t_file *list, t_option *op)
{
	while (list != NULL)
	{
		//ft_putstr("dans aff_list\n");
		if (list->sd->d_name[0] != '.' && list->sd->d_type != DT_DIR)
		{
			if (op->inode == 1)
				aff_inode(list->sd);
			GREEN;
			ft_putstr(list->sd->d_name);
			ft_putstr("\t\t");
/*			printf("\033[0m st_mode: %o\n", buf.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));
			printf("\033[0m st_mode: %o\n", buf.st_mode & (S_IFDIR | S_IFREG | S_IFLNK));
			strcpy(mtime, ctime(&buf.st_mtime));
			printf("st_mtime dernière modif: %s\n",mtime );
			strcpy(mtime, ctime(&buf.st_ctime));
			printf("st_ctime dernier changemnt de statut: %s\n",mtime );
			strcpy(mtime, ctime(&buf.st_atime));
			printf("st_atime dernier acces: %s\n",mtime );   
			printf(" inode %llu\n", buf.st_ino);
			printf("Link count %hd\n", buf.st_nlink);
			printf("Propriétaire UID=%u, GID=%u\n", buf.st_uid, buf.st_gid);
*/		}
		if ( list->sd->d_type == DT_DIR && list->sd->d_name[0] != '.')
		{
			if (op->inode == 1)
				aff_inode(list->sd);
			CYAN;
			ft_putstr(list->sd->d_name);
			ft_putstr("\t\t");
		}
		list = list->next;
	}
}

int		get_total(t_file *list)
{
//	struct stat		buf;
//	char			mtiome[100];
	char			*filename;

	filename = ft_strjoin(list->s, "/");
	filename = ft_strjoin(filename, list->sd->d_name);
	stat(filename, &(list->buf));
	return(list->buf.st_blocks);
}

void	aff_total(t_file *list)
{
	int		total;

	total = 0;
	while (list != NULL)
	{
		total += get_total(list);
		list = list->next;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putstr("\n");
}

void	aff_all(t_file *list, t_option *op)
{
	/*** Faire le tri des elements ici -r -t -c - u et reperer le total ***/
	if (op->list == 1)
		aff_total(list);
	while (list != NULL)
	{
		if (list->sd->d_type != DT_DIR)
		{
			if (op->inode == 1)
				aff_inode(list->sd);
			if (op->list == 1)
			{
				
			}
			GREEN;
			ft_putstr(list->sd->d_name);
			ft_putstr("\t\t");
		}
		if ( list->sd->d_type == DT_DIR)
		{
			if (op->inode == 1)
				aff_inode(list->sd);
			CYAN;
			ft_putstr(list->sd->d_name);
			ft_putstr("\t\t");
		}
		list = list->next;
	}
}


void	aff_list(t_file *list, t_option *op)
{
	char	*str;
	t_file	*list2;

	str = NULL;
	if (op->a == 0)
		aff_visible(list, op);
	else
		aff_all(list, op);
	ft_putstr("\n");
	if (op->rec == 1)
	{
	//	dir = opendir(s);
		while (list != NULL)
		{
			if (list->sd->d_name[0] != '.' && list->sd->d_type == DT_DIR)
			{
				str = ft_strjoin(list->s, "/");
				str = ft_strjoin(str, list->sd->d_name);
				list2 = ft_create_list(str);
				open_dir(str, list2, op);
				free(list2);
			}
//			PURPLE;
//			ft_putstr(list->sd->d_name);
//			ft_putstr("\n");
			list = list->next;
		}
	//	closedir(dir);
	}
}

void	open_dir(char *s, t_file *list, t_option *op)
{

	YELLOW;
	op->time = 1;
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putstr(s);
	ft_putchar(':');
	ft_putchar('\n');
	aff_list(list, op);
}

int main(int argc, char *argv[])
{
	t_option	op;
	int			i;
	t_file		*list;

	i = 1;
	argv[0] = "ft_ls\n";
	op = init_op();
	if (argc == 1)
	{
		list = ft_create_list(".");
		aff_list(list, &op);
		return(0);
	}
	if (argc == 2 && argv[1][0] == '-')
	{
		op = check_option(argv[1]);
		if (option_off_on(op) == 1)
			list = ft_create_list(".");
		else
			list = ft_create_list(argv[i]);
		aff_list(list, &op);
		return (0);
	}
	if (argv[1][0] == '-')
	{
		op = check_option(argv[1]);
		i = 2;
	}
	while (i < argc)
	{
		YELLOW;
		ft_putstr(argv[i]);
		ft_putstr(":\n");
		list = ft_create_list(argv[i]);
		aff_list(list, &op);
		if (i + 1 != argc)
			ft_putchar('\n');
		free(list);
		i++;
	}
	return (0);
}
