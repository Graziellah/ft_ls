/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg_tool.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:45:50 by ghippoda          #+#    #+#             */
/*   Updated: 2017/10/08 18:34:36 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		**sort_tab_bytime(char **tab)
{
	int			i;
	struct stat	st;
	struct stat	st_cmp;

	i = 0;
	while (tab[i + 1])
	{
		lstat(tab[i], &st);
		lstat(tab[i + 1], &st_cmp);
		if (st.st_mtime == st_cmp.st_mtime &&
				(ft_strcmp(tab[i], tab[i + 1]) > 0))
		{
			swap_tab(&tab[i], &tab[i + 1]);
			i = -1;
		}
		else if (st.st_mtime < st_cmp.st_mtime)
		{
			swap_tab(&tab[i], &tab[i + 1]);
			i = -1;
		}
		i++;
	}
	return (tab);
}

char		**rev_tab_end(char **tab, int nb)
{
	char	**tab2;
	int		j;

	j = 0;
	if (!(tab2 = (char**)malloc(sizeof(char*) * nb)))
		return (NULL);
	nb = nb - 1;
	while (nb >= 0)
	{
		tab2[j] = ft_strdup(tab[nb]);
		nb--;
		j++;
	}
	return (tab2);
}

char		**sort_tab_byaccess(char **tab)
{
	int			i;
	struct stat	st;
	struct stat	st_cmp;

	i = 0;
	while (tab[i + 1])
	{
		lstat(tab[i], &st);
		lstat(tab[i + 1], &st_cmp);
		if (st.st_atime == st_cmp.st_atime &&
				(ft_strcmp(tab[i], tab[i + 1]) > 0))
		{
			swap_tab(&tab[i], &tab[i + 1]);
			i = -1;
		}
		else if (st.st_atime < st_cmp.st_atime)
		{
			swap_tab(&tab[i], &tab[i + 1]);
			i = -1;
		}
		i++;
	}
	return (tab);
}

char		**sort_tab_bychange(char **tab)
{
	int			i;
	struct stat	st;
	struct stat	st_cmp;

	i = 0;
	while (tab[i + 1])
	{
		lstat(tab[i], &st);
		lstat(tab[i + 1], &st_cmp);
		if (st.st_ctime == st_cmp.st_ctime &&
				(ft_strcmp(tab[i], tab[i + 1]) > 0))
		{
			swap_tab(&tab[i], &tab[i + 1]);
			i = -1;
		}
		else if (st.st_ctime < st_cmp.st_ctime)
		{
			swap_tab(&tab[i], &tab[i + 1]);
			i = -1;
		}
		i++;
	}
	return (tab);
}

char		**sort_tab_ascii(char **tab)
{
	int		i;
	char	*tmp;

	i = 0;
	while (tab[i + 1])
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	return (tab);
}
