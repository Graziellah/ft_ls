/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 21:54:28 by ghippoda          #+#    #+#             */
/*   Updated: 2017/09/17 15:20:32 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			check_option2(char str, t_option *op)
{
	if (str == 'R')
		op->rec = 1;
	if (str == 'l')
		op->list = 1;
	if (str == 'r')
		op->rev = 1;
	if (str == 'a')
		op->a = 1;
	if (str == 't')
		op->time = 1;
	if (str == 'i')
		op->inode = 1;
	if (str == 'u')
		op->access = 1;
	if (str == 'c')
		op->change = 1;
	if (str == 'F')
		op->end = 1;
	if (str == '1')
		op->line = 1;
}

int				check_letter(char c)
{
	if (c == 'R' || c == 'l' || c == 'r' || c == 'a' || c == 't' || c == 'i' ||
			c == 'u' || c == 'c' || c == 'F' || c == '1')
		return (0);
	else
	{
		ft_putstr("ls : illegal option -- ");
		ft_putchar(c);
		ft_putstr(" \n");
		ft_putstr("usage: ls [-FRacilrtu1] [file ...]\n");
		exit(EXIT_FAILURE);
	}
}

void			check_option(char *str, t_option *op)
{
	int			i;

	i = 1;
	while (str[i])
	{
		if (check_letter(str[i]) == 0)
			check_option2(str[i], op);
		i++;
	}
}

t_option		init_op(void)
{
	t_option	op;

	op.rec = 0;
	op.list = 0;
	op.rev = 0;
	op.a = 0;
	op.time = 0;
	op.inode = 0;
	op.change = 0;
	op.access = 0;
	op.end = 0;
	op.line = 1;
	return (op);
}

int				option_off_on(t_option op)
{
	if (op.rec == 1 || op.list == 1 || op.rev == 1 || op.a == 1 || op.time == 1
			|| op.inode == 1 || op.change == 1 || op.end == 1 || op.access == 1
			|| op.line == 1)
		return (1);
	return (0);
}
