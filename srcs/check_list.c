/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 15:13:40 by ghippoda          #+#    #+#             */
/*   Updated: 2017/10/02 16:40:25 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			check_list(t_file *list, t_option *op)
{
	t_file		*tmp;

	tmp = list;
	if (op->a == 1)
		return (1);
	while (tmp != NULL)
	{
		if (tmp->s[0] != '.')
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void		aff_name(t_option op, int argc, char *argv, int p)
{
	if (op.rec == 1 || (option_off_on(op) == 1 && argc > 3 && p != 4) ||
			(option_off_on(op) == 0 && argc > 2 && p != 4) || argc != 1)
		print_name(argv);
}
