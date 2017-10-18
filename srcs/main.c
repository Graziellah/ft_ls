/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 21:15:49 by ghippoda          #+#    #+#             */
/*   Updated: 2017/10/17 16:15:24 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		error_type(char *str, int type)
{
	RED;
	if (type == NONE)
	{
		ft_putstr("ls : ");
		ft_putstr(str);
		ft_putstr(": No such file or directory\n");
	}
	else if (type == ACCESS)
	{
		ft_putstr("ls : ");
		ft_putstr(str);
		ft_putstr(": Permission denied\n");
	}
	WHITE;
}

int			display_simple_ls(t_option op)
{
	t_file	*list;

	list = ft_create_list(".");
	aff_list(list, &op);
	if (list == NULL)
		return (0);
	return (0);
}

int			display_ls_option_only(t_option op, char **argv)
{
	t_file	*list;
	int		i;

	i = 1;
	check_option(argv[1], &op);
	if (option_off_on(op) == 1)
		list = ft_create_list(".");
	else
		list = ft_create_list(argv[i]);
	aff_list(list, &op);
	return (0);
}

void		main_loop(int i, int argc, char **argv, t_option op)
{
	t_file		*list;
	int			p;

	while (i < argc)
	{
		p = check_argv(argv[i]);
		if (p == NONE || p == ACCESS)
			error_type(argv[i], p);
		if (p == FILES && op.list == 0)
			aff_files(argv, i, argc);
		else
		{
			aff_name(op, argc, argv[i], p);
			if ((p == TMP || p == FILES) && op.list == 1)
				list = get_name(argv[i]);
			else
				list = ft_create_list(argv[i]);
			if ((check_list(list, &op) == 1 && argc == 1) || argc >= 2)
			{
				aff_list(list, &op);
				print_space(argv, argc, i);
			}
		}
		i++;
	}
}

int			main(int argc, char **argv)
{
	t_option	op;
	int			i;
	char		**tab;
	int			nb;

	i = 1;
	op = init_op();
	if (argc == 1 && (display_simple_ls(op) == 0))
		return (0);
	if (argc == 2 && argv[1][0] == '-' && argv[1][1] &&
			display_ls_option_only(op, argv) == 0)
		return (0);
	while (argv[i] && argv[i][0] == '-' && argv[i][1])
	{
		check_option(argv[i], &op);
		i++;
	}
	(i + 1 == argc) ? i = i + 1 : i;
	if ((nb = argc - get_start(argv, argc)) > 0)
		tab = sort_arg(argv, argc, op);
	else
		return (display_ls_option_only(op, argv));
	i = 0;
	main_loop(i, nb, tab, op);
	return (0);
}
