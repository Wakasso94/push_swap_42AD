/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaman-s < imaman-s@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:38:13 by imaman-s          #+#    #+#             */
/*   Updated: 2022/05/28 09:27:00 by imaman-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_validation(int argc, char **argv)
{
	int	i;
	int	ret;

	ret = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_only_spaces(argv[i]))
		{
			ft_number_availability(argv[i]);
			ft_valid_str(argv[i]);
			ret = 1;
		}
		i++;
	}
	return (ret);
}

/*
** <---------------------------------------------------->
** ft_number_availability - Check the string for numbers,
** thus we process bulk lines.
** For example: strings containing only spaces
** and tabs and lines consisting only of '+' or '-'.
** <---------------------------------------------------->
*/

void	ft_number_availability(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			return ;
		i++;
	}
	ft_error();
}

/*
** <---------------------------------------------------------------->
** ft_valid_str - Check the string for validity.
** Is everything written correctly and are there any extra characters
**		in line. We only need numbers that can
** be separated by spaces and tabs. Numbers may have
** positive or negative signs.
** <---------------------------------------------------------------->
*/

void	ft_valid_str(const char *str)
{
	size_t	i;
	int		nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr++;
		else if (str[i] == ' ' || str[i] == '\t')
		{
			if (sign != 0 && nbr == 0)
				ft_error();
			nbr = 0;
			sign = 0;
		}
		else if (((str[i] == '+' || str[i] == '-') && \
				(sign == 0 && nbr == 0)) && (str[i + 1] != '\0'))
			sign++;
		else
			ft_error();
		i++;
	}
}

/*
** <------------------------------------------------------->
** ft_duplicate_check - Start the data verification process
** for duplicates.
** <------------------------------------------------------->
*/

void	ft_duplicate_check(t_data *new, t_stacks *stacks)
{
	int			*dup;

	dup = (int *)malloc(sizeof(int) * (new->count_element));
	if (!dup)
		exit(1);
	dup = ft_intcpy(dup, new->a, new->count_element);
	ft_quick_sort(dup, 0, new->count_element - 1);
	ft_search_duplicate(dup, new->count_element - 1);
	stacks->count_a = new->count_element;
	stacks->count_b = 0;
	stacks->min = dup[0];
	stacks->med = dup[new->count_element / 2];
	stacks->max = dup[new->count_element - 1];
	free(dup);
}

/*
** ft_search_duplicate - Check an array of numbers for
** presence of duplicates.
** ༺༻
** Condition: ✓
** Norms: ✓
** ༺༻
*/

void	ft_search_duplicate(const int *dup, int count)
{
	int	i;

	i = 0;
	while (i != count)
	{
		if (dup[i] == dup[i + 1])
			ft_error();
		i++;
	}
}
