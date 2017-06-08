/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 21:54:28 by ghippoda          #+#    #+#             */
/*   Updated: 2017/06/08 01:41:36 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_option		check_option(char *str)
{
	t_option	op;
	int			i;

	i = 1;
	op = init_op();
	if (str[0] != '-')
	{
		ft_putstr("usage\n");
		exit(1);
	}
	while(str[i])
	{
		if (str[i] == 'R')
			op.rec = 1;
		if (str[i] == 'l')
			op.list = 1;
		if (str[i] == 'r')
			op.rev = 1;
		if (str[i] == 'a')
			op.a = 1;
		if (str[i] == 't')
			op.time = 1;
		if(str[i] == 'i')
			op.inode = 1;
		i++;
	}
	return(op);
}

t_option		init_op()
{
	t_option	op;

	op.rec = 0;
	op.list = 0;
	op.rev = 0;
	op.a = 0;
	op.time = 0;
	op.inode = 0;
	return (op);
}

int		option_off_on(t_option op)
{
	if (op.rec == 1 || op.list == 1 || op.rev == 1 || op.a == 1 || op.time == 1 ||
			op.inode == 1)
		return(1);
	return(0);
}
