/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaman-s < imaman-s@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:28:11 by imaman-s          #+#    #+#             */
/*   Updated: 2022/05/11 19:58:21 by imaman-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** <---------------------------------------->
** sa: swap a - swap the first 2 elements in
** top stack a. Do nothing if there is
** only one or no items.
** <---------------------------------------->
*/

void	ft_sa(t_stack *a, int i)
{
	int		buff;

	if (a == NULL || a->next == NULL)
		return ;
	buff = a->data;
	a->data = a->next->data;
	a->next->data = buff;
	if (i == 1)
		write(1, "sa\n", 3);
}

/*
** <------------------------------------>
** sb: swap b - swap first 2 elements in
** top stack b. Do nothing if there is
** only one or no items.
** <------------------------------------>
*/

void	ft_sb(t_stack *b, int i)
{
	int		buff;

	if (b == NULL || b->next == NULL)
		return ;
	buff = b->data;
	b->data = b->next->data;
	b->next->data = buff;
	if (i == 1)
		write(1, "sb\n", 3);
}

/*
** <----------------------------->
** ss: sa and sb at the same time.
** <----------------------------->
*/

void	ft_ss(t_stacks *s, int i)
{
	ft_sa(s->a, 0);
	ft_sb(s->b, 0);
	if (i == 1)
		write(1, "ss\n", 3);
}

/*
** <--------------------------------------------->
** pa: push a - take the first element at the top
** b and place it on top of a. To do nothing,
** if b is empty.
** <--------------------------------------------->
*/

void	ft_pa(t_stacks *s, int i)
{
	t_stack	*buff;

	if (s->b == NULL)
		return ;
	s->count_a += 1;
	s->count_b -= 1;
	buff = s->b;
	s->b = s->b->next;
	buff->next = s->a;
	s->a = buff;
	if (i == 1)
		write(1, "pa\n", 3);
}

/*
** <--------------------------------------------->
** pb: push b - take the first element at the top
** a and place it on top of b.
** Do nothing if a is empty.
** <--------------------------------------------->
*/

void	ft_pb(t_stacks *s, int i)
{
	t_stack	*buff;

	if (s->a == NULL)
		return ;
	s->count_a -= 1;
	s->count_b += 1;
	buff = s->a;
	s->a = s->a->next;
	buff->next = s->b;
	s->b = buff;
	if (i == 1)
		write(1, "pb\n", 3);
}
