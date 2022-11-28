/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smallsort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mkootstr <mkootstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/28 16:43:47 by mkootstr      #+#    #+#                 */
/*   Updated: 2022/11/28 17:46:26 by mkootstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

void	smallsort(t_data *data)
{
	if (data->sizea == 1)
		return ;
	if (data->sizea == 2)
		if (issorted(data) == 0)
			sa(data->heada);
	if (data->sizea == 3)
		sort_three(data);
	if (data->sizea == 4)
		sort_four(data);
	if (data->sizea == 5)
		sort_five(data);
}

void	sort_three(t_data *data)
{
	t_stack	*node1;
	t_stack	*node2;
	t_stack	*node3;

	node1 = data->heada;
	node2 = node1->next;
	node3 = node2->next;
	while (issorted(data) == 0)
	{
		if ((node1->index < node3->index && node1->index > node2->index) || \
	(node3->index > node1->index && node3->index < node2->index) || \
	(node2->index < node1->index && node2->index > node3->index))
			sa(data->heada);
		else if (node1->index > node2->index)
			ra(data);
		else
			rra(data);
	}
}

void	sort_four(t_data *data)
{
	int	pos;

	pos = find_lowest(data);
	optimize(4, pos, data);
	if (issorted(data) == 0)
	{
		pb(data);
		sort_three(data);
		pa(data);
	}
}

void	sort_five(t_data *data)
{
	int		pos;

	pos = find_lowest(data);
	optimize(5, pos, data);
	if (issorted(data) == 0)
	{
		pb(data);
		sort_four(data);
		pa(data);
	}
}
