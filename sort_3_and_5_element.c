/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_and_5_element.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaman-s < imaman-s@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:38:10 by imaman-s          #+#    #+#             */
/*   Updated: 2022/05/11 19:49:12 by imaman-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3_element(t_stacks *stacks)
{
	int max;

	max = ft_max(stacks->a);
	if (stacks->count_a == 1)
		return ;
	else if (stacks->count_a == 2)
	{
		if (stacks->a->data > stacks->a->next->data)
			ft_sa(stacks->a, 1);
		return ;
	}
	else if (stacks->count_a == 3)
	{
		if (stacks->a->data == max)
			ft_ra(&stacks->a, 1);
		if (stacks->a->next->data == max)
			ft_rra(&stacks->a, 1);
		if (stacks->a->data > stacks->a->next->data)
			ft_sa(stacks->a, 1);
	}
}

/*
** <------------------------------------------>
** ft_sort_5_element - algorithm for sorting 5
** and 4 numbers.
** <------------------------------------------>
*/

void	ft_sort_5_element(t_stacks *stacks)
{
	while (stacks->count_b < 2)
	{
		if (stacks->a->data == stacks->min || stacks->a->data == stacks->max)
			ft_pb(stacks, 1);
		else
			ft_ra(&stacks->a, 1);
	}
	ft_sort_3_element(stacks);
	ft_pa(stacks, 1);
	ft_pa(stacks, 1);
	if (stacks->a->data == stacks->max)
	{
		ft_ra(&stacks->a, 1);
	}
	else
	{
		ft_sa(stacks->a, 1);
		ft_ra(&stacks->a, 1);
	}
}

/*
** <---------------------------------------------->
** ft_max - the function returns the maximum value
** from the stack.
** <---------------------------------------------->
*/

int		ft_max(t_stack *s)
{
	int max;

	max = s->data;
	while (s)
	{
		if (s->data > max)
			max = s->data;
		s = s->next;
	}
	return (max);
}
