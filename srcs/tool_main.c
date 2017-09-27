/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:18:54 by ghippoda          #+#    #+#             */
/*   Updated: 2017/09/17 15:59:27 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_space(char **str, int argc, int i)
{
	struct stat	buf;

	lstat(str[i], &buf);
	if ((S_ISDIR(buf.st_mode)))
		i + 1 < argc ? ft_putstr("\n\n") : ft_putstr("\n");
	else
	{
		lstat(str[i + 1], &buf);
		if ((S_ISDIR(buf.st_mode)))
			ft_putstr("\n\n");
		else
			(i + 1 < argc) ? ft_putstr(" ") : ft_putstr("\n");
	}
}

void	print_name(char *str)
{
	struct stat	buf;

	lstat(str, &buf);
	if ((S_ISDIR(buf.st_mode)))
	{
		ft_putstr(str);
		ft_putstr(":\n");
	}
	return ;
}

int		get_start(char **argv, int argc)
{
	int		start;
	int		i;

	i = 1;
	start = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			start++;
		i++;
	}
	return (start);
}

int		check_file(char *str)
{
	struct dirent	*sd;
	DIR				*dir;

	dir = opendir(".");
	sd = readdir(dir);
	while ((sd = readdir(dir)) != NULL)
	{
		if (ft_strcmp(sd->d_name, str) == 0)
		{
			closedir(dir);
			return (1);
		}
	}
	closedir(dir);
	return (0);
}

int		check_argv(char *str)
{
	DIR			*dir;
	int			errno;
	struct stat	st;

	errno = 0;
	lstat(str, &st);
	if (S_ISLNK(st.st_mode))
		return (LINK);
	if (!(dir = opendir(str)))
	{
		if (check_file(str) != 1)
		{
			if (errno == EACCES)
				return (ACCESS);
			if (errno == ENOENT)
				return (NONE);
		}
		return (0);
	}
	closedir(dir);
	return (0);
}
