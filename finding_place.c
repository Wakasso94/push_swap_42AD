/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaman-s < imaman-s@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:37:44 by imaman-s          #+#    #+#             */
/*   Updated: 2022/05/25 16:10:20 by imaman-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** <------------------------------------------->
** ft_help_finding_place - Helper function for
** ft_finding_place. This function searches
** the best position for insertion.
** <------------------------------------------->
*/

void	ft_help_finding_place(t_stacks *s, t_stack *b, int *action, int *buff)
{
	while (s->a)
	{
		*buff = s->a->data;
		if (b->data > s->a->data)
		{
			*action += 1;
			if (b->data < s->a->next->data)
				break ;
			s->a = s->a->next;
		}
		else
			break ;
	}
	if (ft_smaller_element_detection(s->a, *buff, b->data) == 1)
	{
		while (s->a)
		{
			if (s->a->data < *buff && s->a->data > b->data)
				break ;
			*action += 1;
			s->a = s->a->next;
		}
	}
}

/*
** <--------------------------------------------------------------->
** ft_finding_place - Function after finding the insertion point
** writes data to the steps structure, which will then be executed
** in the ft_instruction_execution function will insert the element
** to the right place with the least amount of action.
** <--------------------------------------------------------------->
*/

int	ft_finding_place(t_stacks *s, t_stack *b, t_steps *steps, int min)
{
	int		action;
	int		res;
	int		buff;

	action = 0;
	buff = 0;
	ft_help_finding_place(s, b, &action, &buff);
	if (s->a->rotate == -1)
		action = s->count_a - action;
	if (min == -1 || (action + b->step) < min)
	{
		steps->dest_a = s->a->rotate;
		steps->dest_b = b->rotate;
		steps->count_a = action;
		steps->count_b = b->step;
		res = action + b->step;
	}
	else
		res = min;
	return (res);
}

/*
** <--------------------------------------------------->
** ft_smaller_element_detection - The function compares
** found place with others to find a better place
** where the element can be inserted.
** <--------------------------------------------------->
*/

int	ft_smaller_element_detection(t_stack *a, int buff, int src)
{
	t_stack	*save;
	int		ret;

	save = a;
	ret = 0;
	while (save && ret == 0)
	{
		if (save->data < buff && save->data > src)
			ret = 1;
		save = save->next;
	}
	return (ret);
}

/*
** <--------------------------------------------------------->
** ft_count_to_min - The function returns
** the position of the minimum element (number) on the stack.
** <--------------------------------------------------------->
*/

int	ft_count_to_min(t_stack *a, int min)
{
	int		i;

	i = 0;
	while (a)
	{
		if (a->data == min)
			break ;
		a = a->next;
		i++;
	}
	return (i);
}
