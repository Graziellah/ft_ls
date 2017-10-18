/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 21:52:27 by ghippoda          #+#    #+#             */
/*   Updated: 2017/10/15 22:56:07 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		aff_majeur_mineur(struct stat buf)
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

static void	aff_time(struct stat buf)
{
	char	mtime[100];
	char	*times;
	time_t	now;
	double	diff;
	char	*year;

	now = time(&now);
	diff = difftime(now, buf.st_mtime);
	ft_strcpy(mtime, ctime(&buf.st_mtime));
	if (diff < MONTHS)
	{
		times = ft_strsub(mtime, 4, 12);
		ft_putstr(times);
	}
	else
	{
		times = ft_strsub(mtime, 4, 7);
		year = ft_strsub(mtime, 20, 4);
		ft_putstr(times);
		ft_putchar(' ');
		ft_putstr(year);
	}
}

void		aff_size(struct stat buf)
{
	int		len;

	ft_putchar('\t');
	ft_putnbr(buf.st_size);
	len = ft_intlen(buf.st_size);
	if (len < 9)
	{
		while (len <= 9)
		{
			ft_putchar(' ');
			len++;
		}
	}
	ft_putchar(' ');
}

void		aff_info(struct stat buf)
{
	aff_right(buf);
	ft_putstr("\t");
	ft_putnbr(buf.st_nlink);
	ft_putstr("\t");
	aff_group(buf);
	ft_putstr("\t\t");
	if (S_ISBLK(buf.st_mode) || S_ISCHR(buf.st_mode))
		aff_majeur_mineur(buf);
	else
		aff_size(buf);
	ft_putstr("\t");
	aff_time(buf);
	ft_putstr("  ");
}

void		aff_total(t_file *list, t_option *op)
{
	int total;

	WHITE;
	total = 0;
	while (list != NULL)
	{
		if (op->a == 0 && list->s[0] == '.')
			;
		else
			total += list->buf.st_blocks;
		list = list->next;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putstr("\n");
}
