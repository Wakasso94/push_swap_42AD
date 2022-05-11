/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaman-s < imaman-s@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:37:26 by imaman-s          #+#    #+#             */
/*   Updated: 2022/05/11 19:58:52 by imaman-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** <----------------------------->
** ft_only_spaces - Check string
** for the presence of separators.
** <----------------------------->
*/

int		ft_only_spaces(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == ' ' || str[i] == '\r' || str[i] == '\f')
			i++;
		else
			return (1);
	}
	return (0);
}

/*
** <------------------------->
** ft_is_sorted - Check array
** for sorting.
** <------------------------->
*/

int		ft_is_sorted(t_data *new)
{
	int i;

	i = 0;
	while (i < (new->count_element - 1))
	{
		if (new->a[i] > new->a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

/*
** <-------------------------------->
** rrr: rra and rrb at the same time.
** <-------------------------------->
*/


void	ft_rrr(t_stacks *s, int i)
{
	ft_rra(&s->a, 0);
	ft_rrb(&s->b, 0);
	if (i == 1)
		write(1, "rrr\n", 4);
}
