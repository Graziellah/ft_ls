/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 01:41:56 by ghippoda          #+#    #+#             */
/*   Updated: 2017/09/23 18:52:24 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*create_path_name(char *child, char *parent)
{
	char	*new_path;

	new_path = ft_strjoin(parent, "/");
	new_path = ft_strjoin(new_path, child);
	return (new_path);
}

t_file		*ft_new_file(struct dirent *info, char *str, int option)
{
	t_file		*new;
	struct stat	buf;
	struct stat	bufl;
	char		*path;

	path = create_path_name(info->d_name, str);
	if (!(new = (t_file*)malloc(sizeof(*new))))
		return (NULL);
	if (option == 1)
		lstat(str, &buf);
	else
		lstat(path, &buf);
	new->buf = buf;
	new->d_type = info->d_type;
	new->d_ino = info->d_ino;
	new->s = ft_strdup(info->d_name);
	new->parent = str;
	new->time = "";
	new->next = NULL;
	return (new);
}

t_file		*get_name(char *str)
{
	struct stat		st;
	t_file			*new;
	t_file			*tmp;

	if (!(tmp = (t_file*)malloc(sizeof(*tmp))))
		return (NULL);
	if (!(new = (t_file*)malloc(sizeof(*new))))
		return (NULL);
	tmp = NULL;
	if (lstat(str, &st) != 0)
	{
		fprintf(stderr, "%X\n", errno);
		exit(EXIT_FAILURE);
	}
	new->buf = st;
	new->d_type = DT_LNK;
	new->d_ino = st.st_ino;
	new->s = ft_strdup(str);
	new->parent = "";
	tmp = new;
	new->next = NULL;
	return (tmp);
}

int			check_dev(char **str)
{
	int		dev;

	dev = 0;
	if (ft_strcmp(*str, "/dev") == 0)
	{
		RED;
		ft_putstr("Dans check dev\n");
		WHITE;
		*str = ft_strjoin(*str, "/");
		dev = 1;
	}
	return (dev);
}

t_file		*ft_create_list(char *str)
{
	struct dirent	*sd;
	t_file			*new;
	t_file			*tmp;
	DIR				*dir;
	int				dev;

	if (!(tmp = (t_file*)malloc(sizeof(*tmp))))
		return (NULL);
	if (!(dir = opendir(str)))
		return (NULL);
	dev = check_dev(&str);
	sd = readdir(dir );
	new = ft_new_file(sd, str, dev);
	tmp = new;
	while ((sd = readdir(dir)) != NULL)
	{
		if (dev == 1)
			new->next = ft_new_file(sd, ft_strjoin(str, sd->d_name), dev);
		else
			new->next = ft_new_file(sd, str, dev);
		new = new->next;
	}
	new->next = NULL;
	closedir(dir);
	return (tmp);
}
