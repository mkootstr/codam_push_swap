/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/28 16:51:34 by mkootstr      #+#    #+#                 */
/*   Updated: 2022/11/29 17:43:24 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

void	optimize(int size, int pos, t_data *data)
{
	if (pos <= (size / 2))
	{
		while (pos > 0)
		{
			ra(data);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rra(data);
			pos++;
		}
	}
}

int	find_lowest(t_data *data)
{
	t_stack	*lowest;
	t_stack	*node;
	int		pos;
	int		i;

	node = data->heada;
	lowest = node;
	pos = 0;
	i = 0;
	while (node != NULL)
	{
		if (node->index < lowest->index)
		{
			lowest = node;
			pos = i;
		}
		node = node->next;
		i++;
	}
	return (pos);
}

int	issorted(t_data *data)
{
	t_stack	*node;

	node = data->heada;
	while (node->next != NULL)
	{
		if (node->index > node->next->index)
			return (0);
		node = node->next;
	}
	return (1);
}

void	pushalla(t_data *data)
{
	while (data->headb != NULL)
		pa(data);
}
