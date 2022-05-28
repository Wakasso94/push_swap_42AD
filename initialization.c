/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaman-s < imaman-s@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:37:50 by imaman-s          #+#    #+#             */
/*   Updated: 2022/05/28 09:07:11 by imaman-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** <-------------------------------->
** ft_init_stack - Initialize stacks.
** Form stack A by overwriting data
** from an array of numbers to lists.
** <-------------------------------->
*/

void	ft_init_stack(t_data *new, t_stacks *stacks)
{
	stacks->a = ft_create_stack(new->a, new->count_element);
	stacks->b = NULL;
}

/*
** <--------------------------------------------------------->
** ft_create_stack - We form a stack,
** rewriting numbers from the buff array into sheets (lists).
** <--------------------------------------------------------->
*/

t_stack	*ft_create_stack(const int *buff, int count)
{
	int		i;
	t_stack	*new_list;
	t_stack	*first_element;

	i = 0;
	new_list = (t_stack *)malloc(sizeof(t_stack));
	if (!new_list)
		exit(1);
	first_element = new_list;
	while (i < count)
	{
		if (i < count - 1)
		{
			new_list->next = (t_stack *)malloc(sizeof(t_stack));
			if (!new_list->next)
				exit(1);
		}
		new_list->data = buff[i];
		if (i == (count - 1))
			new_list->next = NULL;
		else
			new_list = new_list->next;
		i++;
	}
	return (first_element);
}

/*
** <------------------------------------------------------>
** ft_free_stack - Free the memory allocated for the stack.
** <------------------------------------------------------>
*/

void	ft_free_stack(t_stacks *stacks)
{
	int		i;
	t_stack	*buff;

	i = 0;
	while (i < stacks->count_a)
	{
		buff = stacks->a;
		stacks->a = stacks->a->next;
		free(buff);
		i++;
	}
	i = 0;
	while (i < stacks->count_b)
	{
		buff = stacks->b;
		stacks->b = stacks->b->next;
		free(buff);
		i++;
	}
}

/*
** <------------------------------------------>
** ft_null - Nullify the data in the structure.
** <------------------------------------------>
*/

void	ft_null(t_stacks *stacks, t_data *new)
{
	new->count_element = 0;
	stacks->count_a = 0;
	stacks->count_b = 0;
	stacks->min = 0;
	stacks->max = 0;
	stacks->med = 0;
	stacks->a = NULL;
	stacks->b = NULL;
}
