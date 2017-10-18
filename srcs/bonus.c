/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 14:11:12 by ghippoda          #+#    #+#             */
/*   Updated: 2017/10/15 22:19:21 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	aff_inode(ino_t d_ino)
{
	ft_putnbr(d_ino);
	ft_putchar(' ');
}

void	aff_files(char **argv, int i, int argc)
{
	int			type;
	struct stat	buf;
	struct stat	lm;

	stat(argv[i], &buf);
	if (S_ISREG(buf.st_mode) && (buf.st_mode & 0111))
		RED;
	else
		GREEN;
	ft_putendl(argv[i]);
	if (i + 1 != argc)
	{
		lstat(argv[i + 1], &lm);
		if (S_ISDIR(lm.st_mode) || (S_ISLNK(lm.st_mode)))
			ft_putchar('\n');
	}
}

int		val_errno(int type)
{
	if (errno == EACCES)
		return (ACCESS);
	if (errno == ENOENT)
		return (NONE);
	return (type);
}
