/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 01:41:56 by ghippoda          #+#    #+#             */
/*   Updated: 2017/06/08 06:55:58 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_file		*ft_new_file(struct dirent *info, char *str)
{
	t_file		*new;

//	new = init_piece();
	if (!(new = (t_file*)malloc(sizeof(*new))))
		return NULL;
	new->sd = info;
	new->s = str;
	new->next = NULL;
	return (new);
}

t_file		*ft_create_list(char *str)
{
	struct dirent	*sd;
	t_file			*new;
	t_file			*tmp;
	DIR				*dir;

	sd = NULL;
	if (!(tmp = (t_file*)malloc(sizeof(*tmp))))
		return NULL;
	tmp = NULL;
	dir = opendir(str);
	sd = readdir(dir);
	new = ft_new_file(sd, str);
	tmp = new;
	while((sd = readdir(dir)) != NULL)
	{
//	printf("name TMP: %s\n", tmp->sd->d_name);
//	tmp = tmp->next;
		new->next = ft_new_file(sd, str);
	//	printf("name: %s\n", new->sd->d_name);
		new = new->next;
	}
	new->next = NULL;
	closedir(dir);
/*	printf("name TMP: %s\n", tmp->sd->d_name);
	tmp = tmp->next;
	printf("name TMP: %s\n", tmp->sd->d_name);
	tmp = tmp->next;
	printf("name TMP: %s\n", tmp->sd->d_name);
	tmp = tmp->next;
	while(tmp != NULL)
	{
		BLUE;
		printf("name tmp: %s\n", tmp->sd->d_name);
		tmp = tmp->next;
	}
*/	return(tmp);
}


/*
int			main()
{
	t_file		*hey;

	hey = ft_create_list(".");
	while(hey != NULL)
	{
		printf("name: %s type: %d\n", hey->sd->d_name, hey->sd->d_type);
		hey = hey->next;
	}
	return (0);
}*/
