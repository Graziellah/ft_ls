/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:21:22 by ghippoda          #+#    #+#             */
/*   Updated: 2017/10/02 15:16:38 by ghippoda         ###   ########.fr       */
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
# define BG_YELLOW ft_putstr("\033[43m")
# define BG_CYAN ft_putstr("\033[46m")
# define _BSD_VISIBLE
# define _BSD_SOURCE
# define TDIR 1
# define TREG 2
# define TEXE 3
# define TFIFO 4
# define TSOCK 5
# define TCHR 6
# define TBLK 7
# define TLNK 8
# define ACCESS 1
# define NONE 2
# define LINK 4
# define MAX 10
# define MODE (S_IRWXU | S_IRUSR | S_IWUSR | S_IXUSR | S_IRWXG | S_IRGRP)
# define MODE2 (S_IWGRP | S_IXGRP | S_IRWXO | S_IROTH | S_IWOTH | S_IXOTH)
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <dirent.h>
# include <string.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <errno.h>
# include "../libft/libft.h"
# include <sys/acl.h>

typedef struct		s_file
{
	char			*path;
	DIR				*name;
	ino_t			d_ino;
	unsigned char	d_type;
	struct dirent	*sd;
	struct stat		buf;
	char			*time;
	char			*s;
	char			*parent;
	int				lenght_max;
	struct s_file	*next;
}					t_file;

typedef struct		s_gen
{
	int				group;
	int				user;
}					t_gen;

typedef struct		s_option
{
	int				rec;
	int				list;
	int				rev;
	int				a;
	int				time;
	int				inode;
	int				change;
	int				access;
	int				end;
	int				line;
}					t_option;

int					check_list(t_file *list, t_option *op);
void				aff_inode(ino_t d_ino);
void				new_sort_ascii(t_file **ls);
char				**rev_tab_end(char **tab, int nb);
void				print_space(char **str, int argc, int i);
char				**sort_tab2(char **tab, t_option *op, int nb);
int					get_start(char **argv, int argc);
void				swap_tab(char **tab1, char **tab2);
char				**sort_tab_bytime(char **tab);
char				**reverse_tab(char **tab);
char				**sort_tab_byaccess(char **tab);
char				**sort_tab_bychange(char **tab);
char				**sort_tab_ascii(char **tab);
char				**sort_arg(char **argv, int argc, t_option op);
void				print_name(char *str);
t_file				*get_name(char *str);
int					check_argv(char *str);
int					list_count(t_file *list);
void				info(t_file *list, int type, t_option *op);
char				isuid(struct stat st);
char				isgid(struct stat st);
char				isvtx(struct stat st);
t_option			init_op(void);
void				check_option(char *str, t_option *op);
int					option_off_on(t_option op);
t_file				*ft_new_file(struct dirent *info, char *str, int option);
t_file				*ft_create_list(char *str);
int					oct_to_int(int mode);
void				putstr_access(int nb);
void				get_access(int mode);
void				aff_inode(ino_t d_ino);
void				aff_right(struct stat buf);
void				aff_group(struct stat buf);
void				aff_info(struct stat buf);
void				aff_visible(t_file *list, t_option *op);
void				aff_total(t_file *list, t_option *op);
void				aff_all(t_file *list, t_option *op);
void				aff_list(t_file *list, t_option *op);
void				open_dir(char *s, t_file *list, t_option *op);
t_file				*sort_list_bytime(t_file *ls);
t_file				*sort_list_byaccess(t_file *ls);
t_file				*sort_list_bychange(t_file *ls);
t_file				*sort_list_rev(t_file *ls);
t_file				*sort_ascii(t_file *list);
t_file				*reverse(t_file *list);
void				color(int type);
void				end(int type);
void				aff_visible2(t_option *op, t_file *list, int type);
void				sort(t_file **list, t_option *op);
t_file				*create_file();
void				cpy_file(t_file **ls, t_file *l2);
void				swap_file(t_file **ls, t_file **l2);
#endif
