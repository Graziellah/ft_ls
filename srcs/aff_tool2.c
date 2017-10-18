/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_tool2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 17:52:24 by ghippoda          #+#    #+#             */
/*   Updated: 2017/10/08 17:55:59 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		put_space_ls(int len)
{
	while (len >= 0)
	{
		ft_putchar(' ');
		len--;
	}
}

void			aff_group(struct stat buf)
{
	struct passwd	*pw;
	struct group	*gr;
	int				len;
	int				i;

	len = 1;
	i = 0;
	if ((pw = getpwuid(buf.st_uid)) == NULL)
	{
		ft_putstr("1004");
		len = MAX - 4 + 1;
	}
	else
	{
		ft_putstr(pw->pw_name);
		len = MAX - ft_strlen(pw->pw_name) + 1;
	}
	put_space_ls(len);
	if ((gr = getgrgid(buf.st_gid)) == NULL)
		ft_putstr("5101");
	else
		ft_putstr(gr->gr_name);
	put_space_ls(len);
	ft_putstr(" ");
}
