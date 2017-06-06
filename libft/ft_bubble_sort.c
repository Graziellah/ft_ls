/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 17:13:39 by ghippoda          #+#    #+#             */
/*   Updated: 2017/06/01 17:56:01 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"
# include <stdio.h>

void		ft_swap_int(int *a, int *b)
{
	int		c;

	c = *a;
	*a = *b;
	*b = c;
}

void		ft_bubble_sort(int *tab, int lenght)
{
	int		i;
	int		chgt;

	chgt = 1;
	i = 0;
	while (chgt == 1)
	{
		chgt = 0;
		while( i < lenght)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap_int(&tab[i], &tab[i + 1]);
				chgt = 1;
			}
			i++;
		}
	}
}

int main(void)
{
	int		tab[] = {3, 9, 10, 6, 8, 2, 5};
	int		i;

	i = 0;
	ft_bubble_sort(tab, 7);
	while(i < 7)
	{
		printf("chiffre numero %d : %d\n", i + 1, tab[i]);
		i++;
	}
	return (0);
}
