/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:25:20 by ghippoda          #+#    #+#             */
/*   Updated: 2017/05/31 15:29:51 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	aff_list(char const *s)
{
	DIR 	*dir;
	struct dirent	*sd;
	struct stat 		buf;
	char				mtime[100];

	dir = opendir(s);
	while ((sd = readdir(dir)) != NULL)
	{
		if (sd->d_name[0] != '.')
		{
			printf("\033[32m%s\t\t",sd->d_name);
			stat(sd->d_name, &buf);
			printf("\033[0m st_mode: %o\n", buf.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));
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
		}
	}
	ft_putchar('\n');
	printf("\n");
	closedir(dir);
}

void	open_dir(char *s)
{
	struct dirent		*sd;
	struct dirent		*td;
	DIR					*dos;
	DIR 				*dir;
	int					i;

	dir = opendir(s);
	while((sd = readdir(dir)) != NULL)
	{
		if (sd->d_type == 4 && sd->d_name[0] != '.')
		{
			i = 0;
			printf("\033[31m \n./%s:\n", sd->d_name);
			dos = opendir(sd->d_name);
			while((td = readdir(dos)) != NULL)
			{
				ft_putstr("lol\n");
				if (td->d_name[0] != '.')
					printf("%s\t\t",td->d_name);
				if ((i > 7 && i % 7 == 0) || i == 8)
					printf("XOP%d\n", i);
				printf("ici\n");
				if(td->d_type == 4 && sd->d_name[0] != '.')
					open_dir(".");
				i++;
			}
			printf("\n");
		}
	}
	closedir(dir);
}

int main(int argc, char *argv[])
{

	argv[0] = "ft_ls\n";
	if (argc == 1)
	aff_list(".");
	open_dir(".");
	printf("\n");
	return (0);
}
