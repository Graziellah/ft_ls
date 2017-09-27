/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 21:56:46 by ghippoda          #+#    #+#             */
/*   Updated: 2017/09/21 15:48:06 by ghippoda         ###   ########.fr       */
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
