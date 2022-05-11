/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaman-s < imaman-s@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:38:07 by imaman-s          #+#    #+#             */
/*   Updated: 2022/05/11 19:48:41 by imaman-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_array_separation(int argc, char **argv, t_data *new)
{
	int		p;
	int		i;
	int		*buff;
	char	**mass;
	int		count_element;

	i = 1;
	while (i < argc)
	{
		p = -1;
		count_element = ft_countword(argv[i]);
		mass = ft_strsplit(argv[i], count_element);
		if (!(buff = (int *)malloc(sizeof(int) * (count_element))))
			exit(1);
		while (count_element > ++p)
		{
			buff[p] = ft_atoi(mass[p]);
			free(mass[p]);
		}
		free(mass);
		ft_stacking(new, buff, count_element);
		i++;
	}
}

/*
** <------------------------------------------------------>
** ft_stacking - In this function, we rewrite
** data from buff to new->a(int array in t_data structure)
** a certain number of times (count).
** <------------------------------------------------------>
*/

void	ft_stacking(t_data *new, int *buff, int count)
{
	int i;

	i = -1;
	while (count > ++i)
		new->a[new->count_element + i] = buff[i];
	new->count_element += count;
	free(buff);
}
