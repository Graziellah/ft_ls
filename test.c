/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:25:20 by ghippoda          #+#    #+#             */
/*   Updated: 2017/06/08 02:49:20 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	aff_inode(struct dirent *sd)
{
	ft_putnbr(sd->d_ino);
	ft_putchar(' ');
}

void	aff_visible(struct dirent *sd, DIR *dir, t_option *op)
{
	while ((sd = readdir(dir)) != NULL)
	{
		//ft_putstr("dans aff_list\n");
		if (sd->d_name[0] != '.' && sd->d_type != DT_DIR)
		{
			if (op->inode == 1)
				aff_inode(sd);
			GREEN;
			ft_putstr(sd->d_name);
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
		if ( sd->d_type == 4 && sd->d_name[0] != '.')
		{
			if (op->inode == 1)
				aff_inode(sd);
			CYAN;
			ft_putstr(sd->d_name);
			ft_putstr("\t\t");
		}
	}
}

void	aff_all(struct dirent *sd, DIR *dir, t_option *op)
{
	while ((sd = readdir(dir)) != NULL)
	{
		if (sd->d_type != 4)
		{
			if (op->inode == 1)
				aff_inode(sd);
			GREEN;
			ft_putstr(sd->d_name);
			ft_putstr("\t\t");
		}
		if ( sd->d_type == 4)
		{
			if (op->inode == 1)
				aff_inode(sd);
			CYAN;
			ft_putstr(sd->d_name);
			ft_putstr("\t\t");
		}
	}
}


void	aff_list(char *s, t_option *op)
{
	DIR 	*dir;
	struct dirent	*sd;
//	struct stat 		buf;
//	char				mtime[100];
	char			*str;

	dir = opendir(s);
	str = NULL;
	sd = NULL;
	if (op->a == 0)
		aff_visible(sd, dir, op);
	else
		aff_all(sd, dir, op);
	ft_putstr("\n");
	closedir(dir);
	if (op->rec == 1)
	{
		dir = opendir(s);
		while ((sd = readdir(dir)) != NULL)
		{
			if (sd->d_name[0] != '.' && sd->d_type == 4)
			{
				str = ft_strjoin(s, "/");
				str = ft_strjoin(str, sd->d_name);
				open_dir(str, op);
			}
		}
		closedir(dir);
	}
}

void	open_dir(char *s, t_option *op)
{
	DIR 		*dir;
	char		*str;

	str = NULL;
	YELLOW;
	dir = opendir(s);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putstr(s);
	ft_putchar(':');
	ft_putchar('\n');
	aff_list(s, op);
}

int main(int argc, char *argv[])
{
	t_option	op;
	int			i;

	i = 1;
	argv[0] = "ft_ls\n";
	op = init_op();
	if (argc == 1)
	{
		aff_list(".", &op);
		return(0);
	}
	if (argc == 2 && argv[1][0] == '-')
	{
		op = check_option(argv[1]);
		if (option_off_on(op) == 1)
			aff_list(".", &op);
		else
			aff_list(argv[1], &op);
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
		aff_list(argv[i], &op);
		if (i + 1 != argc)
			ft_putchar('\n');
		i++;
	}
	return (0);
}
