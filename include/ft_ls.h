/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:21:22 by ghippoda          #+#    #+#             */
/*   Updated: 2017/06/01 16:22:03 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define RED ft_putstr("\033[31m")
# define CLEAR ft_putstr("\033[0m")
# define UNDERLINE ft_putstr("\033[4m")
# define BLINK ft_putstr("\033[5m")
# define BLACK ft_putstr("\033[30m")
# define GREEN ft_putstr("\033[32m")
# define YELLOW ft_putstr("\033[33m")
# define BLUE ft_putstr("\033[34m")
# define PURPLE ft_putstr("\033[35m")
# define CYAN ft_putstr("\033[36m")
# define WHITE ft_putstr("\033[37m")
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <time.h>
# include "../libft/libft.h"

typedef struct		s_file
{
	DIR				*name;
	struct dirent	*sd;
	struct stat		buf;
	char			*time;
	struct s_file	*next;
}					t_file;

typedef struct		s_option
{
	int				rec;
	int				list;
	int				rev;
	int				a;
	int				time;
}					t_option;

void				open_dir(char *str, t_option *op);
t_option			init_op();
t_option			check_option(char *str);
int					option_off_on(t_option op);

#endif
