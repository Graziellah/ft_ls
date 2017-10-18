/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:18:54 by ghippoda          #+#    #+#             */
/*   Updated: 2017/10/17 16:24:10 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_space(char **str, int argc, int i)
{
	struct stat	buf;

	if (argc == i + 1)
		;
	else
	{
		lstat(str[i + 1], &buf);
		if ((S_ISDIR(buf.st_mode)))
			ft_putstr("\n");
	}
}

void	print_name(char *str)
{
	struct stat	buf;

	lstat(str, &buf);
	if ((S_ISDIR(buf.st_mode)) || S_ISLNK(buf.st_mode))
	{
		YELLOW;
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
	struct stat	st;
	int			type;

	lstat(str, &st);
	type = 0;
	if (!S_ISDIR(st.st_mode))
	{
		type = 5;
		if (S_ISLNK(st.st_mode))
			type = 4;
	}
	if (!(dir = opendir(str)) || type == 4)
	{
		if (check_file(str) != 1 || type == 4)
			return (val_errno(type));
		else
			return (val_errno(type));
	}
	closedir(dir);
	return (type);
}
