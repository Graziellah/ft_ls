/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 21:52:27 by ghippoda          #+#    #+#             */
/*   Updated: 2017/09/21 18:03:32 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	aff_right(struct stat buf)
{
	int		mode;

	mode = buf.st_mode & (MODE);
	if (S_ISREG(buf.st_mode))
		ft_putchar('-');
	else if (S_ISCHR(buf.st_mode))
		ft_putchar('c');
	else if (S_ISLNK(buf.st_mode))
		ft_putchar('l');
	else if (S_ISBLK(buf.st_mode))
		ft_putchar('b');
	else if (S_ISFIFO(buf.st_mode))
		ft_putchar('p');
	else if (S_ISDIR(buf.st_mode))
		ft_putchar('d');
	else if (S_ISSOCK(buf.st_mode))
		ft_putchar('s');
	ft_putchar(isuid(buf));
	ft_putchar(isgid(buf));
	ft_putchar(isvtx(buf));
}

void	aff_group(struct stat buf)
{
	struct passwd	*pw;
	struct group	*gr;
	int				len;
	int				i;

	len = 1;
	i = 0;
	pw = getpwuid(buf.st_uid);
	gr = getgrgid(buf.st_gid);
	ft_putstr(pw->pw_name);
	len = MAX - ft_strlen(pw->pw_name) + 1;
	while (len >= 0)
	{
		ft_putchar(' ');
		len--;
	}
	ft_putstr(gr->gr_name);
	len = MAX - ft_strlen(gr->gr_name) + 1;
	while (len >= 0)
	{
		ft_putchar(' ');
		len--;
	}
	ft_putstr(" ");
}

void	aff_majeur_mineur(struct stat buf)
{
	if (major(buf.st_rdev) >= 0)
		ft_putnbr(major(buf.st_rdev));
	else
		ft_putchar(' ');
	ft_putchar(',');
	ft_putchar('\t');
	if (minor(buf.st_rdev) >= 0)
		ft_putnbr(minor(buf.st_rdev));
	else
		ft_putchar(' ');
	ft_putchar('\t');
}

void	aff_info(struct stat buf)
{
	char	mtime[100];
	char	*time;

	aff_right(buf);
	ft_putstr("\t");
	ft_putnbr(buf.st_nlink);
	ft_putstr("\t");
	aff_group(buf);
	ft_putstr("\t\t");
	if (S_ISBLK(buf.st_mode) || S_ISCHR(buf.st_mode))
		aff_majeur_mineur(buf);
	else
	{
		ft_putchar('\t');
		ft_putnbr(buf.st_size);
		ft_putchar('\t');
	}
	ft_putstr("\t");
	ft_strcpy(mtime, ctime(&buf.st_mtime));
	time = ft_strsub(mtime, 4, 12);
	ft_putstr(time);
	ft_putstr("  ");
}

void	aff_total(t_file *list, t_option *op)
{
	int total;

	WHITE;
	total = 0;
	while (list != NULL)
	{
		if (op->a == 0 && list->s[0] == '.')
			list = list->next;
		total += list->buf.st_blocks;
		list = list->next;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putstr("\n");
}
