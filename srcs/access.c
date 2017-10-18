/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 21:56:46 by ghippoda          #+#    #+#             */
/*   Updated: 2017/10/04 14:14:33 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	isuid(struct stat st)
{
	(S_IRUSR & st.st_mode) ? ft_putchar('r') : ft_putchar('-');
	(S_IWUSR & st.st_mode) ? ft_putchar('w') : ft_putchar('-');
	if (S_ISUID & st.st_mode)
	{
		if (S_IXUSR & st.st_mode)
			return ('s');
		else
			return ('S');
	}
	else
	{
		if (S_IXUSR & st.st_mode)
			return ('x');
		else
			return ('-');
	}
}

char	isgid(struct stat st)
{
	(S_IRGRP & st.st_mode) ? ft_putchar('r') : ft_putchar('-');
	(S_IWGRP & st.st_mode) ? ft_putchar('w') : ft_putchar('-');
	if (S_ISGID & st.st_mode)
	{
		if (S_IXGRP & st.st_mode)
			return ('s');
		else
			return ('S');
	}
	else
	{
		if (S_IXGRP & st.st_mode)
			return ('x');
		else
			return ('-');
	}
}

char	isvtx(struct stat st)
{
	(S_IROTH & st.st_mode) ? ft_putchar('r') : ft_putchar('-');
	(S_IWOTH & st.st_mode) ? ft_putchar('w') : ft_putchar('-');
	if (S_ISVTX & st.st_mode)
	{
		if (S_IXOTH & st.st_mode)
			return ('t');
		else
			return ('T');
	}
	else
	{
		if (S_IXOTH & st.st_mode)
			return ('x');
		else
			return ('-');
	}
}

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
