/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 07:43:40 by ghippoda          #+#    #+#             */
/*   Updated: 2017/06/08 10:20:06 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_ls.h"
# define MODE (S_IRWXU | S_IRUSR | S_IWUSR | S_IXUSR | S_IRWXG | S_IRGRP | S_IWGRP | S_IXGRP | S_IRWXO | S_IROTH | S_IWOTH | S_IXOTH)


void	putstr_access(int nb)
{
	if (nb == 0 )
		printf("---");
	if (nb == 1 )
		printf("--x");
	if (nb == 2 )
		printf("-w-");
	if (nb == 3 )
		printf("-wx");
	if (nb == 4 )
		printf("r--");
	if (nb == 5 )
		printf("r-x");
	if (nb == 6 )
		printf("rw-");
	if (nb == 7 )
		printf("rwx");
}

void	get_access(int mode)
{
	int nb;

	printf("mode : %d", mode);
	nb = 0;
	nb = mode / 64;
		putstr_access(nb);
	mode = mode * nb / 64;
	nb = mode / 8;
		putstr_access(nb);
	mode = mode * nb / 8;
	nb = mode ;
		putstr_access(nb);
}

int		main(int argc, char *argv[])
{
	struct stat buf;
	char	mtime[100];
	int	modeee;

	stat("dossier_1", &buf);
	printf("total %lld\n", buf.st_blocks);
//	printf("-rw-r--r-- ");
	if (buf.st_mode & (S_IFDIR))
		printf("d");
	else
		printf("-");
	printf("buf: %o ", buf.st_mode & (MODE));
	modeee = buf.st_mode & (MODE);
	printf("modeee: %d", modeee);
	get_access(0x493);
	//get_access(buf.st_mode & (MODE));
	printf("\ndrwxr-xr-x ");
	printf("%o ", buf.st_mode & (MODE));
	printf("%d ", buf.st_nlink);
	printf("%d %d ", buf.st_uid, buf.st_gid); // http://forum.hardware.fr/hfr/Programmation/C/recuper-utilisateur-partir-sujet_131285_1.htm
	printf("%lld ", buf.st_size);
	strcpy(mtime, ctime(&buf.st_mtime));
	printf("%s ", &mtime[4]);
	printf("myfile.txt\n");
	printf("st_mode = %o\n", buf.st_mode);
	return (0);
}
