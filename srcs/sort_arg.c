/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 13:37:46 by ghippoda          #+#    #+#             */
/*   Updated: 2017/09/17 14:59:42 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	swap_tab(char **tab1, char **tab2)
{
	char	*tmp;

	tmp = *tab1;
	*tab1 = *tab2;
	*tab2 = tmp;
}

char	**clean_tab(char **tab, int nb)
{
	char		**tab2;
	int			i;
	int			j;
	struct stat	st;

	i = 0;
	j = -1;
	tab2 = (char **)malloc(sizeof(char*) * nb);
	while (i < nb)
	{
		lstat(tab[i], &st);
		if (!(S_ISDIR(st.st_mode)))
			tab2[++j] = ft_strdup(tab[i]);
		i++;
	}
	i = 0;
	while (i < nb)
	{
		lstat(tab[i], &st);
		if ((S_ISDIR(st.st_mode)))
			tab2[++j] = ft_strdup(tab[i]);
		i++;
	}
	return (tab2);
}

char	**sort_tab2(char **tab, t_option *op, int nb)
{
	tab = sort_tab_ascii(tab);
	if (op->time == 1)
		tab = sort_tab_bytime(tab);
	if (op->access == 1)
		tab = sort_tab_byaccess(tab);
	if (op->change == 1)
		tab = sort_tab_bychange(tab);
	if (op->rev == 1)
		tab = rev_tab_end(tab, nb);
	tab = clean_tab(tab, nb);
	return (tab);
}

char	**sort_arg(char **argv, int argc, t_option op)
{
	int		i;
	int		j;
	char	**tab;
	int		nb;

	i = 1;
	j = 0;
	tab = (char**)malloc(sizeof(char*) * argc);
	while (argv[i] != NULL && argv[i][0] == '-')
		i++;
	while (argv[i] != NULL)
	{
		tab[j] = ft_strdup(argv[i]);
		i++;
		j++;
	}
	tab[j] = NULL;
	i = 0;
	nb = argc - get_start(argv, argc);
	tab = sort_tab2(tab, &op, nb);
	return (tab);
}
