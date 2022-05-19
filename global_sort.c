/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaman-s < imaman-s@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:37:47 by imaman-s          #+#    #+#             */
/*   Updated: 2022/05/15 17:17:01 by imaman-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** <------------------------------------------->
** ft_global_sort - algorithm for sorting
** numbers of any size are written on the base
** insertion sort. This function
** prepares the stack for sorting.
** <------------------------------------------->
*/

void	ft_global_sort(t_stacks *stacks)
{
	while (stacks->count_a > 2)
	{
		if (stacks->a->data != stacks->min && stacks->a->data != stacks->max)
		{
			ft_pb(stacks, 1);
			if (stacks->b->data > stacks->med)
				ft_rb(&stacks->b, 1);
		}
		else
			ft_ra(&stacks->a, 1);
	}
	if (stacks->a->data < stacks->a->next->data)
		ft_sa(stacks->a, 1);
	ft_pa(stacks, 1);
	ft_start_sort(stacks);
}

/*
** <------------------------------------>
** ft_start_sort - start sorting process.
** <------------------------------------>
*/

void	ft_start_sort(t_stacks *stacks)
{
	t_steps *step;

	if (!(step = (t_steps *)malloc(sizeof(t_steps))))
		exit(1);
	while (stacks->count_b != 0)
	{
		step->count_a = -1;
		step->count_b = -1;
		step->dest_a = 0;
		step->dest_b = 0;
		ft_steps_markup(stacks->a, stacks->count_a);
		ft_steps_markup(stacks->b, stacks->count_b);
		ft_minimum_insertion_steps(stacks, step);
		ft_instruction_execution(stacks, step);
	}
	if ((ft_count_to_min(stacks->a, stacks->min)) > stacks->count_a / 2)
	{
		while (stacks->a->data != stacks->min)
			ft_rra(&stacks->a, 1);
	}
	else
		while (stacks->a->data != stacks->min)
			ft_ra(&stacks->a, 1);
	free(step);
}

/*
** <---------------------------------------------------->
** ft_steps_markup - markup of each element of the stack
** the number of steps it takes for the element to
** got to the top (to the first position).
** <---------------------------------------------------->
*/

void	ft_steps_markup(t_stack *b, int count)
{
	int		i;
	int		iter;
	t_stack	*buff;

	i = -1;
	iter = count / 2;
	buff = b;
	while (++i <= iter)
	{
		buff->step = i;
		buff->rotate = 1;
		buff = buff->next;
	}
	if (count % 2 == 0)
		i--;
	while (--i > 0)
	{
		buff->step = i;
		buff->rotate = -1;
		buff = buff->next;
	}
}

/*
** <---------------------------------------------------------->
** ft_minimum_insertion_steps - a function that finds
** element that can be moved with the minimum number of steps.
** <---------------------------------------------------------->
*/

void	ft_minimum_insertion_steps(t_stacks *stacks, t_steps *steps)
{
	int		min_action;
	t_stack	*first_a;
	t_stack	*first_b;

	min_action = -1;
	first_a = stacks->a;
	first_b = stacks->b;
	while (stacks->b)
	{
		min_action = ft_finding_place(stacks, stacks->b, steps, min_action);
		stacks->a = first_a;
		stacks->b = stacks->b->next;
	}
	stacks->b = first_b;
}

/*
** <----------------------------------------------------------->
** ft_instruction_execution is a function that
** performs operations according to the previously set parameters.
** <----------------------------------------------------------->
*/

void	ft_instruction_execution(t_stacks *stacks, t_steps *steps)
{
	while (steps->count_a > 0)
	{
		if (steps->dest_a == 1)
			ft_ra(&stacks->a, 1);
		else
			ft_rra(&stacks->a, 1);
		steps->count_a--;
	}
	while (steps->count_b > 0)
	{
		if (steps->dest_b == 1)
			ft_rb(&stacks->b, 1);
		else
			ft_rrb(&stacks->b, 1);
		steps->count_b--;
	}
	ft_pa(stacks, 1);
}
